package pcremote.activities;

import pcremote.communication.messages.KeyboardMessage;
import pcremote.custom.KeyboardController.Keys;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class PresentationActivity extends ControllerActivity{
	
	@Override
	public void onCreate(Bundle bundle)
	{
		super.onCreate(bundle);
		this.setContentView(R.layout.presentation_activity);
	}
	
	public void goToKeyboard(View v)
	{
		startActivity(new Intent(this, KeyboardActivity.class));
	}
	public void goToMousepad(View v)
	{
		startActivity(new Intent(this, MouseActivity.class));
	}
	public void goToMedia(View v)
	{
		startActivity(new Intent(this, MediaActivity.class));
	}
	
	public void nextSlide(View v){
		communicator.send(new KeyboardMessage(Keys.ARROWRIGHT));
	}
	
	public void prevSlide(View v){
		communicator.send(new KeyboardMessage(Keys.ARROWLEFT));
	}
}
