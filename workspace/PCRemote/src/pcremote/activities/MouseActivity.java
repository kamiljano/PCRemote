package pcremote.activities;

import android.os.Bundle;
import android.util.Log;

public class MouseActivity extends ControllerActivity{
	
	@Override
	public void onCreate(Bundle bund)
	{
		super.onCreate(bund);
		Log.i("trolololo", "MouseActivity");
		this.setContentView(R.layout.mouse_activity);
	}
}
