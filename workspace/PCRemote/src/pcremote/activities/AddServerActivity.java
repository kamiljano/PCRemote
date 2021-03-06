package pcremote.activities;

import pcremote.storage.ServerData;
import pcremote.storage.ServersStorage;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class AddServerActivity extends Activity{

	private EditText name, address, port;
	private AlertDialog alertDialog;
	private Button button;
	private ServerData sd = null;
	
	@Override
	public void onCreate(Bundle bund)
	{
		super.onCreate(bund);
		this.setContentView(R.layout.add_server_activity);
		name = (EditText)findViewById(R.id.serverName);
		address = (EditText) findViewById(R.id.serverAddress);
		port = (EditText) findViewById(R.id.serverPort);
		
		button = (Button) findViewById(R.id.addServerButton);
		
		String temp1 = this.getIntent().getStringExtra("sname"), temp2, temp3;
		if (temp1 != null)
		{
			name.setText(temp1);
			temp2 = this.getIntent().getStringExtra("saddr");
			address.setText(temp2);
			temp3 = this.getIntent().getStringExtra("sport");
			port.setText(temp3);
			button.setText(R.string.save);
			sd = new ServerData(temp1, temp2, Integer.parseInt(temp3));
		}
	}
	
	private boolean validate()
	{
		String message="The following errors occured:\n";
		boolean e = true;
		if (name.getText().length() == 0)
		{
			message += "- No server name entered\n";
			e = false;
		}
		if (address.getText().length() == 0)
		{
			message += "- No server address entered\n";
			e = false;
		}
		if (port.getText().length() == 0)
		{
			message += "- No server port entered\n";
			e = false;
		}
		int p = 0;
		try
		{
			p = Integer.parseInt(port.getText().toString());
		}
		catch(Exception ee)
		{
			message += "Incorrect port format\n";
			e = false;
		}
		if (p<1)
		{
			message += "- The port must not be lesser than 1\n";
			e = false;
		}
		
		if (!e)
		{
			alertDialog = new AlertDialog.Builder(this).create();
			alertDialog.setTitle("Error");
			alertDialog.setMessage(message);
			alertDialog.setButton("OK", new OnClickListener(){
	
				public void onClick(DialogInterface arg0, int arg1) {
					alertDialog.cancel();
					
				}
	
				});
			alertDialog.show();
		}
		
		return e;
	}
	
	public void addServerClicked(View v)
	{
		if (validate())
		{
			ServersStorage ss = new ServersStorage(this);
			try
			{
				if (sd != null)
					ss.removeServer(sd);
				ss.addServer(new pcremote.storage.ServerData(name.getText().toString(), address.getText().toString(), Integer.parseInt(port.getText().toString())));
				if (this.getIntent().getBooleanExtra("userCall", false))
					finish();
				else
					startActivity(new Intent(this, ServerListActivity.class));
			}
			catch(Exception e)
			{
				Toast.makeText(this, "Failed to store new data", Toast.LENGTH_SHORT).show();
			}
		}
	}
}
