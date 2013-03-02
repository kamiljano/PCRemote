package pcremote.activities;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class KeyboardActivity extends ControllerActivity{

	@Override
	public void onCreate(Bundle bundle)
	{
		super.onCreate(bundle);
		this.setContentView(R.layout.keyboard_activity);
	}
	
	public void goToMousepad(View v)
	{
		startActivity(new Intent(this, MouseActivity.class));
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
