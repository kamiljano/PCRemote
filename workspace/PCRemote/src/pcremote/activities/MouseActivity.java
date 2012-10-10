package pcremote.activities;

import pcremote.custom.MouseController;
import pcremote.storage.ServersStorage;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

public class MouseActivity extends Activity{
	
	@Override
	public void onCreate(Bundle bund)
	{
		super.onCreate(bund);
		Log.i("trolololo", "MouseActivity");
		this.setContentView(R.layout.mouse_activity);
		MouseController mc = (MouseController)findViewById(R.id.mouseController);
		try
		{
			mc.setOutputStream(ServersStorage.getSocket().getOutputStream());
		}
		catch(Exception e)
		{
			Toast.makeText(this, getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
		}
	}
	
	public void goToKeyboard(View v)
	{
		startActivity(new Intent(this, KeyboardActivity.class));
		//KeyboardView k = new KeyboardView(this);
	}
	public void goToMedia(View v)
	{
		startActivity(new Intent(this, MediaActivity.class));
	}
}
