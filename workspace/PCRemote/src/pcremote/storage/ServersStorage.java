package pcremote.storage;

import java.io.FileInputStream;
import java.net.Socket;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import android.content.Context;

public class ServersStorage {

	private static final String FileName = "servers";
	private Context con;
	private Lock fileAccess = new ReentrantLock();
	
	private static ServerData selectedServer;
	private static Socket sock;
	
	public static void selectServer(ServerData sd)
	{
		selectedServer = sd;
	}
	
	public static ServerData getSelectedServer()
	{
		return selectedServer;
	}
	
	public static void setSocket(Socket s)
	{
		sock = s;
	}
	
	public static Socket getSocket()
	{
		return sock;
	}
	
	public ServersStorage(Context con)
	{
		this.con = con;
	}
	
	public ServerData[] getServers() throws Exception
	{
		fileAccess.lock();
		ServerData [] ret = new ServerData [0];
		DocumentBuilderFactory dbfac = DocumentBuilderFactory.newInstance();
        DocumentBuilder docBuilder = dbfac.newDocumentBuilder();
        Document doc = null;
        Element root = null;
		try
		{
			FileInputStream fis = con.openFileInput(FileName);
			doc = docBuilder.parse(fis);
			doc.getDocumentElement().normalize();
			root = doc.getDocumentElement();
			NodeList l = root.getElementsByTagName("server");//.getChildNodes("");
			fis.close();
			ret = new ServerData [l.getLength()];
			for (int i = 0; i<l.getLength(); i++)
			{
				Node nNode = l.item(i);
				if (nNode.getNodeType() == Node.ELEMENT_NODE) {
					
					Element el = (Element) nNode;
					ret[i] = new ServerData(el.getAttribute("name"), el.getAttribute("address"), Integer.parseInt(el.getAttribute("port")));
				}
			}
		}
		catch(Exception ex){}
		finally
		{
			fileAccess.unlock();
		}
		return ret;
	}
	
	public void addServer(ServerData d) throws Exception
	{
		fileAccess.lock();
		DocumentBuilderFactory dbfac = DocumentBuilderFactory.newInstance();
        DocumentBuilder docBuilder = dbfac.newDocumentBuilder();
        Document doc = null;
        Element root = null;
		try
		{
			FileInputStream fis = con.openFileInput(FileName);
			doc = docBuilder.parse(fis);
			doc.getDocumentElement().normalize();
			root = doc.getDocumentElement();
			fis.close();
		}
		catch(Exception ex){}
		finally
		{
			if (doc == null || root == null)
			{
				doc = docBuilder.newDocument();
				root = doc.createElement("servers");
				doc.appendChild(root);
			}
			
			Element child = doc.createElement("server");
			child.setAttribute("name", d.Name());
			child.setAttribute("address", d.Address());
			child.setAttribute("port", Integer.toString(d.Port()));
			root.appendChild(child);
			
			TransformerFactory transfac = TransformerFactory.newInstance();
            Transformer trans = transfac.newTransformer();
            trans.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION, "yes");
            trans.setOutputProperty(OutputKeys.INDENT, "yes");
            
            StreamResult result = new StreamResult(con.openFileOutput(FileName,Context.MODE_PRIVATE));
            DOMSource source = new DOMSource(doc);
            trans.transform(source, result);
            fileAccess.unlock();
		}
	}
	
	public void removeServer(ServerData d) throws Exception
	{
		fileAccess.lock();
		DocumentBuilderFactory dbfac = DocumentBuilderFactory.newInstance();
        DocumentBuilder docBuilder = dbfac.newDocumentBuilder();
        Document doc = null;
        Element root = null;
		try
		{
			FileInputStream fis = con.openFileInput(FileName);
			doc = docBuilder.parse(fis);
			doc.getDocumentElement().normalize();
			root = doc.getDocumentElement();
			NodeList l = root.getChildNodes();
			fis.close();
			for (int i = 0; i<l.getLength(); i++)
			{
				Node nNode = l.item(i);
				if (nNode.getNodeType() == Node.ELEMENT_NODE) {
					
					Element el = (Element) nNode;
					String po = Integer.toString(d.Port());
					if (el.getAttribute("name").equals(d.Name()) && el.getAttribute("address").equals(d.Address()) && el.getAttribute("port").equals(po))
					{
						root.removeChild(el);
						TransformerFactory transfac = TransformerFactory.newInstance();
			            Transformer trans = transfac.newTransformer();
			            trans.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION, "yes");
			            trans.setOutputProperty(OutputKeys.INDENT, "yes");
			            
			            StreamResult result = new StreamResult(con.openFileOutput(FileName,Context.MODE_PRIVATE));
			            DOMSource source = new DOMSource(doc);
			            trans.transform(source, result);
						break;
					}
				}
			}
		}
		catch(Exception ex){}
		finally
		{
			fileAccess.unlock();
		}
	}
}
