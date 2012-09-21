package pcremote.activities;

import pcremote.storage.ServersStorage;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;

public class ServersActivity extends Activity{

	@Override
	public void onCreate(Bundle bund)
	{
		super.onCreate(bund);
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
	
}
