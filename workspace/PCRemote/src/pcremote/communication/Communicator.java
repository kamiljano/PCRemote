package pcremote.communication;

import java.io.IOException;
import java.net.UnknownHostException;

import pcremote.communication.messages.NetworkMessage;
import pcremote.storage.ServersStorage;
import android.content.Context;
import android.os.Handler;

public class Communicator {

	private SendingThread sendingThread = null;
	private ReceivingThread receivingThread = null;
	
	private static Communicator instance = new Communicator();
	
	private boolean success = false;
	private Exception lastException = null;
	
	private Communicator() {
		try {
			sendingThread = SendingThread.getInstance();
			receivingThread = ReceivingThread.getInstance();
			success = true;
		} catch (UnknownHostException e) {
			success = false;
			lastException = e;
			e.printStackTrace();
		};
	}
	
	public static Communicator getCommunicator() {
		return instance;
	}
	
	public boolean connectionSucceeded() {
		return success;
	}
	
	public Exception getLastException() {
		return lastException;
	}
	
	public void send(NetworkMessage message) {
		sendingThread.addMessage(message);
	}
	
	public void enableErrorHandling(Context context, Handler handler) {
		sendingThread.setContext(context);
		sendingThread.setHandler(handler);
		receivingThread.setContext(context);
		receivingThread.setHandler(handler);
	}
	
	public void start() {
			sendingThread.start();
			receivingThread.start();
	}
	
	public void stop() {
		try {
			ServersStorage.getSocket().close();
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		boolean test1 = false;
		boolean test2 = false;
		if (sendingThread.isAlive()) {
			test1 = true;
			sendingThread.interrupt();
		}
		if (receivingThread.isAlive()) {
			test2 = true;
			receivingThread.interrupt();
		}
		if (test1) {
			try {
				sendingThread.join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		if (test2) {
			try {
				receivingThread.join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		if (ServersStorage.getSocket() != null) {
			try {
				ServersStorage.getSocket().close();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	
	public void addResponseListener(ResponseListener listener) {
		receivingThread.addResponseListener(listener);
	}
}
