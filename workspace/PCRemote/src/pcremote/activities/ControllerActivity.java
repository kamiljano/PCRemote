package pcremote.activities;

import pcremote.communication.Communicator;
import pcremote.communication.ResponseListener;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.View;

public abstract class ControllerActivity extends Activity{
	
	protected Communicator communicator;
	private final Handler handler = new Handler();
	
	@Override
	public void onCreate (Bundle bundle) {
		super.onCreate(bundle);
		communicator = Communicator.getCommunicator();
		if (this instanceof ResponseListener) {
			communicator.addResponseListener((ResponseListener)this);
		}
	}
	
	@Override
	public void onStart() {
		super.onStart();
		communicator.enableErrorHandling(this, handler);
		if (!communicator.connectionSucceeded()) {
			Log.e("trolololo", "Failed to start sending thread", communicator.getLastException());
		}
	}
	
	public void goToKeyboard(View v)
	{
		startActivity(new Intent(this, KeyboardActivity.class));
	}
	public void goToMedia(View v)
	{
		startActivity(new Intent(this, MediaActivity.class));
	}
	public void goToPresentation(View v)
	{
		startActivity(new Intent(this, PresentationActivity.class));
	}
	
	public void goToMousepad(View v)
	{
		startActivity(new Intent(this, MouseActivity.class));
	}
	
	public void goToRemoteFileBrowser(View v) {
		startActivity(new Intent(this, RemoteFileBrowserActivity.class));
	}
	
	public Context getMessageContext() {
		return this;
	}
	
	public Handler getMessageHandler() {
		return handler;
	}
}
