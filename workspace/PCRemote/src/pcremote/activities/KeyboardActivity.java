package pcremote.activities;

import pcremote.custom.KeyboardController;
import pcremote.storage.ServersStorage;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class KeyboardActivity extends Activity{

	@Override
	public void onCreate(Bundle bundle)
	{
		super.onCreate(bundle);
		this.setContentView(R.layout.keyboard_activity);
		KeyboardController k = (KeyboardController)findViewById(R.id.keyboard);
		try
		{
			k.setOutputStream(ServersStorage.getSocket().getOutputStream());
		}
		catch(Exception e)
		{
			Toast.makeText(this, getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
		}
	}
	
	public void goToMousepad(View v)
	{
		startActivity(new Intent(this, MouseActivity.class));
	}
	public void goToMedia(View v)
	{
		startActivity(new Intent(this, MediaActivity.class));
	}
}
