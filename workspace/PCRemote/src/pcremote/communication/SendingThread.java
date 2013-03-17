package pcremote.communication;

import java.io.IOException;
import java.io.OutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.concurrent.ArrayBlockingQueue;

import pcremote.activities.R;
import pcremote.communication.messages.NetworkMessage;
import pcremote.communication.messages.NetworkMessage.NetworkProtocol;
import pcremote.storage.ServersStorage;
import android.content.Context;
import android.os.Handler;
import android.util.Log;
import android.widget.Toast;

public class SendingThread extends Thread{

	private static SendingThread instance;
	private ArrayBlockingQueue <NetworkMessage> messages = new ArrayBlockingQueue<NetworkMessage>(20);
	private Context context = null;
	private Handler handler = null;
	private InetAddress IPAddress = null;
	private OutputStream out = null;
	
	private SendingThread() throws UnknownHostException {
		IPAddress = InetAddress.getByName(ServersStorage.getSelectedServer().Address());
		try {
			this.out = ServersStorage.getSocket().getOutputStream();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void addMessage(NetworkMessage message) {
		messages.offer(message);
	}
	
	public static void clear() {
		instance = null;
	}
	
	public static SendingThread getInstance() throws UnknownHostException {
		if (instance == null) {
			instance = new SendingThread();
		}
		return instance;
	}
	
	public void setContext(Context context) {
		this.context = context;
	}
	
	public void setHandler(Handler handler) {
		this.handler = handler;
	}
	
	@Override
	public void run() {
		super.run();
		Log.v("trolololo", "SendingThread started");
		while (!Thread.interrupted()) {
			NetworkMessage message;
			try {
				message = messages.take();
			} catch (InterruptedException e1) {
				return;
			}
			Log.v("trolololo", "Sending message: " + message.getClass().getName());
			if (message.getNetworkProtoco() == NetworkProtocol.UDP) {
				try
				{
					DatagramSocket clientSocket = new DatagramSocket();
				    DatagramPacket sendPacket = new DatagramPacket(message.getBytes(), message.getBytes().length, IPAddress, 1234);
				    clientSocket.send(sendPacket);
				    clientSocket.close();
				}
				catch(Exception e)
				{
					if (handler != null && context != null) {
						handler.post(new Runnable(){
		
							public void run() {
								Toast.makeText(context, context.getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
							}});
						
						break;
					}
				}
			} else { //if TCP
				try {
					out.write(message.getBytes());
					out.flush();
				} catch (Exception e) {
					break;
				}
				
			}
		}
		messages.clear();
	}
}
