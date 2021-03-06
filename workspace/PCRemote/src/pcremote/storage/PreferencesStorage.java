package pcremote.storage;

import java.io.FileInputStream;
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

public class PreferencesStorage {

	private static final String FileName = "preferences.conf";
	private static Context con;
	private static Lock fileAccess = new ReentrantLock();
	
	public static void setContext(Context c)
	{
		con = c;
	}
	
	public static Preferences getPreferences() throws Exception
	{
		fileAccess.lock();
		Preferences ret = new Preferences();
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
			NodeList l = root.getElementsByTagName("touchpad");
			fis.close();
			for (int i = 0; i<l.getLength(); i++)
			{
				Node nNode = l.item(i);
				if (nNode.getNodeType() == Node.ELEMENT_NODE) {
					
					Element el = (Element) nNode;
					ret.cursorSensitvity = Float.parseFloat(el.getAttribute("cursorSensitivity"));
					ret.scrollSensitivity = Byte.parseByte(el.getAttribute("scrollSensitivity"));
					ret.rightClickTime = Integer.parseInt(el.getAttribute("rightClickTime"));
				}
			}
		}
		finally
		{
			fileAccess.unlock();
		}
		return ret;
	}
	
	public static void savePreferences(float cursorSens, byte scrollSens, int rightClickTime) throws Exception
	{
		fileAccess.lock();
		try
		{
			DocumentBuilderFactory dbfac = DocumentBuilderFactory.newInstance();
	        DocumentBuilder docBuilder = dbfac.newDocumentBuilder();
	        Document doc = null;
	        Element root = null;
	
			doc = docBuilder.newDocument();
			root = doc.createElement("preferences");
			doc.appendChild(root);
			
			Element child = doc.createElement("touchpad");
			child.setAttribute("cursorSensitivity", Float.toString(cursorSens));
			child.setAttribute("scrollSensitivity", Byte.toString(scrollSens));
			child.setAttribute("rightClickTime", Integer.toString(rightClickTime));
			root.appendChild(child);
			
			TransformerFactory transfac = TransformerFactory.newInstance();
	        Transformer trans = transfac.newTransformer();
	        trans.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION, "yes");
	        trans.setOutputProperty(OutputKeys.INDENT, "yes");
	        
	        StreamResult result = new StreamResult(con.openFileOutput(FileName,Context.MODE_PRIVATE));
	        DOMSource source = new DOMSource(doc);
	        trans.transform(source, result);
		}
		finally
		{
			fileAccess.unlock();
		}

	}
}
