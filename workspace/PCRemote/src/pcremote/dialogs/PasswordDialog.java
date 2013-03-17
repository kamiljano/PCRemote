package pcremote.dialogs;

import java.io.IOException;
import java.net.Socket;

import pcremote.activities.R;
import pcremote.communication.Communicator;
import pcremote.storage.ServersStorage;
import android.app.Activity;
import android.app.Dialog;
import android.view.View;
import android.view.WindowManager.LayoutParams;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class PasswordDialog extends Dialog{

	private Socket socket;
	private EditText password;
	private Activity context;
	
	public PasswordDialog(Activity context, Socket socket) {
		super(context);
		this.context = context;
		this.socket = socket;
		setContentView(R.layout.password_dialog);
		((Button)findViewById(R.id.okButton)).setOnClickListener(new SubmitListener());
		((Button)findViewById(R.id.cancelButton)).setOnClickListener(new CancelListener());
		password = (EditText) findViewById(R.id.password);
		
		LayoutParams params = getWindow().getAttributes();
        params.width = LayoutParams.FILL_PARENT;
        getWindow().setAttributes((android.view.WindowManager.LayoutParams) params);
	}
	
	public class SubmitListener implements View.OnClickListener {
		public void onClick(View v) {
			try {
				byte [] buff = new byte[100];
				byte [] temp = password.getText().toString().getBytes();
				for (int i = 0; i < temp.length && i < 99; i++) {
					buff[i+1] = temp[i];
				}
				buff[0] = 10;
				socket.getOutputStream().write(buff);
				buff = new byte[1];
				socket.getInputStream().read(buff);
				if (buff[0] == 0) {
					Toast.makeText(context, "Incorrect password", Toast.LENGTH_SHORT).show();
					PasswordDialog.this.dismiss();
				} else {
					PasswordDialog.this.dismiss();
					ServersStorage.setSocket(socket);
					Communicator.getCommunicator().start();
					context.finish();
				}
				
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	public class CancelListener implements View.OnClickListener {
		public void onClick(View v) {
			try {
				socket.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			PasswordDialog.this.dismiss();
		}
	}

}
