package pcremote.miscellaneous;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.util.Enumeration;
import java.util.LinkedList;

public class NetworkScanner {
	
	private static LinkedList<String> getBroadcastAddresses() throws Exception
	{
		LinkedList<String>ret = new LinkedList<String>();
		/*Enumeration<NetworkInterface> interfaces = NetworkInterface.getNetworkInterfaces();
		while (interfaces.hasMoreElements())
		{
			NetworkInterface networkInterface = interfaces.nextElement();
			if (networkInterface.isLoopback())
				continue;    // Don't want to broadcast to the loopback interface
			for (InterfaceAddress interfaceAddress : networkInterface.getInterfaceAddresses())
			{
				InetAddress broadcast = interfaceAddress.getBroadcast();
				if (broadcast == null)
					continue;
				ret.add(broadcast.getHostAddress());				
			}
		}*/
		return ret;
	}
	
	private static void sendRequests(LinkedList<String> addr) throws Exception
	{
		byte[] message = new byte[]{0,1};

		for (String host : addr)
		{
			// Get the internet address of the specified host
			InetAddress address = InetAddress.getByName(host);
			
			// Initialize a datagram packet with data and address
			DatagramPacket packet = new DatagramPacket(message, message.length, address, 1234);
			
			  // Create a datagram socket, send the packet through it, close it.
			DatagramSocket dsocket = new DatagramSocket();
			dsocket.send(packet);
			dsocket.close();
		}
	}
	
	public static void scan() throws Exception
	{
		//LinkedList<String>addresses = getBroadcastAddresses();
		LinkedList<String>addresses = new LinkedList<String>();
		addresses.add("192.168.56.255");
		
		scanWaiter.start();
		Thread.sleep(50);
		sendRequests(addresses);
		scanWaiterKiller.start();
	}

	
	private static Thread scanWaiter = new Thread(new Runnable()
	{
		public void run()
		{	
			byte[] receiveData = new byte[1024];
			DatagramSocket clientSocket;
			try
			{
				clientSocket = new DatagramSocket(60606);
			}
			catch (Exception e){return;}
			while (!Thread.interrupted())
			{
				try
				{
					clientSocket.setSoTimeout(500);
				    DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
				    System.out.println("receiving");
				    clientSocket.receive(receivePacket);
				    System.out.println("received");
					receiveData = receivePacket.getData();
					if (receiveData[0] == 0 && receiveData[1] == 0)
					{
						//System.out.println(receivePacket.getAddress().getHostAddress());
						int len = 0;
						for (int i = 2; i < receiveData.length-1 && (receiveData[i] != 0 && receiveData[i+1]!=0); i++)
							len ++;
						byte [] sn = new byte[++len];
						for (int i = 2; i < len+2; i++)
							sn [i-2] = receiveData[i];
						String ssn = new String(sn);
						
						String [] data = ssn.split(";");
						System.out.println(data[0]);
						System.out.println(data[1]);
					}
				}
				catch(Exception e){
					clientSocket.close();
				}
			}
			clientSocket.close();
			System.out.println("killed");
		}
	});
	
	private static Thread scanWaiterKiller = new Thread(new Runnable()
	{
		public void run()
		{	
			try
			{
				Thread.sleep(2000);
			}
			catch(Exception e){}
			scanWaiter.interrupt();
			System.out.println("killing");
		}
	});
}