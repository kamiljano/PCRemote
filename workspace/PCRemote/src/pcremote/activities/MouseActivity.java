package pcremote.activities;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MouseActivity extends ControllerActivity{
	
	@Override
	public void onCreate(Bundle bund)
	{
		super.onCreate(bund);
		Log.i("trolololo", "MouseActivity");
		this.setContentView(R.layout.mouse_activity);
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
	public void goToPresentation(View v)
	{
		startActivity(new Intent(this, PresentationActivity.class));
	}
}
