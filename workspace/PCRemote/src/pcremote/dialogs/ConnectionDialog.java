package pcremote.dialogs;

import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketAddress;

import pcremote.activities.R;
import pcremote.communication.Communicator;
import pcremote.storage.ServersStorage;
import android.app.Activity;
import android.app.ProgressDialog;
import android.os.Handler;
import android.widget.Toast;

public class ConnectionDialog extends ProgressDialog{

	private String address;
	private int port=1234;
	private Activity parent;
	private Handler h = new Handler();
	private Thread th;
	
	public ConnectionDialog(Activity context, String address, int port) {
		super(context);
		this.address = address;
		this.port = port;
		this.parent = context;
		this.setMessage(context.getString(R.string.connecting));
		this.setCancelable(true);
	}
	
	@Override
	public void onStop()
	{
		super.onStop();
		if (th != null && th.isAlive())
			th.interrupt();
	}

	@Override
	public void show()
	{
		super.show();
		th = new Thread(new Runnable(){

			public void run() {
				SocketAddress sockaddr = new InetSocketAddress(address, port);
				Socket sock = new Socket();
				try
				{
					sock.connect(sockaddr, 5000);
					sock.setKeepAlive(true);
				}
				catch(Exception e)
				{
					if (Thread.interrupted())
					{
						h.post(new Runnable(){
							
							public void run()
							{
								ConnectionDialog.this.dismiss();
							}
						});
					}
					else
					{
						h.post(new Runnable(){
							
							public void run()
							{
								Toast.makeText(parent, parent.getString(R.string.connectionFail), Toast.LENGTH_SHORT).show();
								ConnectionDialog.this.dismiss();
							}
						});
					}
					return;
				}
				boolean accepted = introduce(sock);
				if (accepted) {
					ServersStorage.setSocket(sock);
					Communicator.getCommunicator().start();
					h.post(new Runnable(){
						
						public void run()
						{
							Toast.makeText(parent, parent.getString(R.string.connected), Toast.LENGTH_SHORT).show();
							ConnectionDialog.this.dismiss();
							parent.finish();
						}
					});
				} else {
					h.post(new Runnable(){
						
						public void run()
						{
							Toast.makeText(parent, parent.getString(R.string.connectionRejected), Toast.LENGTH_SHORT).show();
							ConnectionDialog.this.dismiss();
						}
					});
				}
				
			}});
		th.start();
	}
	
	private boolean introduce(Socket s)
	{
		try
		{
			s.getOutputStream().write(new byte[]{5,1});
			byte [] buff = new byte[18];
			int read = 0;
			while (read < 18)
				read += s.getInputStream().read(buff, read, buff.length - read);
			String answer = new String(buff);
			if (answer.startsWith("03")) {
				if (answer.endsWith("2")) {
					requirePassword(s);
				}
				else
					return answer.endsWith("1");
			}
		}
		catch(Exception e)
		{}
		return false;
	}
	
	private Socket sock;
	private void requirePassword(Socket s) {
		this.sock = s;
		h.post(new Runnable(){

			public void run() {
				ConnectionDialog.this.hide();
				PasswordDialog dialog = new PasswordDialog(parent, sock);
				dialog.show();
				
			}
			
		});
	}
}
