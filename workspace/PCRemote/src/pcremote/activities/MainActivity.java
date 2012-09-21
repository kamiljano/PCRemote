package pcremote.activities;

import pcremote.storage.ServersStorage;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.DialogInterface.OnClickListener;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends Activity {

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        goToServers();
    }
    
    private void goToServers()
    {
    	ServersStorage ss = new ServersStorage(this);
		try
		{
			if (ss.getServers().length == 0)
				startActivity(new Intent(this, AddServerActivity.class));
			else
				startActivity(new Intent(this, ServerListActivity.class));
		}
		catch(Exception e){}
    }
    
    public void goToServers(View v)
    {
    	goToServers();
    }
    
    private AlertDialog alertDialog;
    
    public void goToRemote(View v)
    {
    	if (ServersStorage.getSelectedServer() == null)
    	{
    		alertDialog = new AlertDialog.Builder(this).create();
			alertDialog.setTitle("Error");
			alertDialog.setMessage(getString(R.string.noServerSelected));
			alertDialog.setButton("OK", new OnClickListener(){
	
				public void onClick(DialogInterface arg0, int arg1) {
					alertDialog.cancel();
					goToServers();
				}
	
				});
			alertDialog.show();
    	}
    	else
    		this.startActivity(new Intent(this,MouseActivity.class));
    }
    
    public void goToAbout(View v)
    {
    	this.startActivity(new Intent(this, AboutActivity.class));
    }
}
