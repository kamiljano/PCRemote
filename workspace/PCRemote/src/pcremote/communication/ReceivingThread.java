package pcremote.communication;

import java.io.IOException;
import java.io.InputStream;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.HashSet;
import java.util.Set;

import pcremote.storage.ServersStorage;
import android.content.Context;
import android.os.Handler;

public class ReceivingThread extends Thread {

	private static ReceivingThread instance;
	private Context context = null;
	private Handler handler = null;
	private InetAddress IPAddress = null;
	private InputStream in = null;
	private final Set<ResponseListener> listeners = new HashSet<ResponseListener>();
	
	private ReceivingThread() throws UnknownHostException {
		IPAddress = InetAddress.getByName(ServersStorage.getSelectedServer().Address());
		try {
			in = ServersStorage.getSocket().getInputStream();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void clear() {
		instance = null;
	}
	
	public static ReceivingThread getInstance() throws UnknownHostException {
		if (instance == null) {
			instance = new ReceivingThread();
		}
		return instance;
	}
	
	public void setContext(Context context) {
		this.context = context;
	}
	
	public void setHandler(Handler handler) {
		this.handler = handler;
	}
	
	public void addResponseListener(ResponseListener listener) {
		listeners.add(listener);
	}

	private boolean containsResponseType(ResponseType [] types, ResponseType type){
		for (ResponseType t : types) {
			if (t.equals(type)){
				return true;
			}
		}
		return false;
	}
	
	private void dispatchResponse(ResponseType type, byte [] message) {
		for (ResponseListener listener : listeners) {
			if (containsResponseType(listener.getAwaitedResponseTypes(), type)) {
				if (listener instanceof ContextResponseListener) {
					ContextResponseListener crl = (ContextResponseListener) listener;
					final Context c = crl.getMessageContext();
					final Handler h = crl.getMessageHandler();
					if (c != null && h != null) {
						h.post(new ContextRunner(listener, type, message));
					} else {
						listener.processResponse(type, message);
					}
				}
				else {
					listener.processResponse(type, message);
				}
			}
		}
	}
	
	@Override
	public void run() {
		super.run();
		byte [] messageInfo = new byte[17]; //contains message type and its length
		while(!Thread.interrupted()) {
			try {
				in.read(messageInfo);
				String strMessageInfo = new String(messageInfo);
				int messageTypeCode = Integer.parseInt(strMessageInfo.substring(0,2));
				int messageLen = Integer.parseInt(strMessageInfo.substring(2));
				byte [] message = new byte [messageLen];
				int received = 0;
				while (received < messageLen)
					received += in.read(message, received, messageLen - received);
				ResponseType type = ResponseType.getResponseTypeByCode(messageTypeCode);
				dispatchResponse(type, message);
			} catch (Exception e) {
				/*if (handler != null && context != null) {
					handler.post(new Runnable(){

						public void run() {
							Toast.makeText(context, context.getString(R.string.receiveFail), Toast.LENGTH_SHORT).show();
						}});
				}
				e.printStackTrace();*/
			}
		}
	}
	
	private class ContextRunner implements Runnable {

		private ResponseListener rl;
		private ResponseType type;
		private byte [] message;
		
		public ContextRunner(ResponseListener listener, ResponseType type, byte [] message) {
			this.rl = listener;
			this.type = type;
			this.message = message;
		}
		
		public void run() {
			rl.processResponse(type, message);
			
		}
	}
}
