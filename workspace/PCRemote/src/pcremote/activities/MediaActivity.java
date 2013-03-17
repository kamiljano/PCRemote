package pcremote.activities;

import pcremote.communication.messages.KeyboardMessage;
import pcremote.custom.KeyboardController.Keys;
import android.os.Bundle;
import android.view.View;

public class MediaActivity extends ControllerActivity {
	
	@Override
	public void onCreate(Bundle bund)
	{
		super.onCreate(bund);
		this.setContentView(R.layout.media_activity);
	}
	
	public void prevClicked(View v)
	{
		communicator.send(new KeyboardMessage(Keys.MEDIAPREV));
	}
	public void nextClicked(View v)
	{
		communicator.send(new KeyboardMessage(Keys.MEDIANEXT));
	}
	public void playClicked(View v)
	{
		communicator.send(new KeyboardMessage(Keys.MEDIAPLAY));
	}
	public void minusClicked(View v)
	{
		communicator.send(new KeyboardMessage(Keys.VOLDOWN));
	}
	public void plusClicked(View v)
	{
		communicator.send(new KeyboardMessage(Keys.VOLUP));
	}
}
