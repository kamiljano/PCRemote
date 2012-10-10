package pcremote.dialogs;

import pcremote.activities.R;
import pcremote.storage.ServerData;
import android.app.Dialog;
import android.content.Context;
import android.view.View;
import android.view.WindowManager.LayoutParams;
import android.widget.Button;
import android.widget.TextView;

public class ServerInfoDialog extends Dialog{

	private TextView name, address, port;
	
	public ServerInfoDialog(Context context, ServerData sd) {
		super(context);
		this.setTitle(R.string.serverInfo);
		setContentView(R.layout.dialog_server_info);
		
		LayoutParams params = this.getWindow().getAttributes();
		params.width = LayoutParams.FILL_PARENT;
		params.horizontalMargin = 20;
		
		name = (TextView) findViewById(R.id.name);
		address = (TextView) findViewById(R.id.address);
		port = (TextView) findViewById (R.id.port);
		
		name.setText(": " + sd.Name());
		address.setText(": " + sd.Address());
		port.setText(": " + Integer.toString(sd.Port()));
		
		Button b = (Button) findViewById(R.id.okbutton);
		b.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				ServerInfoDialog.this.dismiss();
				
			}
		});
	}

	
}
