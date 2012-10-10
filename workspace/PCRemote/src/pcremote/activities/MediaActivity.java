package pcremote.activities;

import java.io.OutputStream;
import java.util.concurrent.ArrayBlockingQueue;

import pcremote.custom.KeyboardController.Keys;
import pcremote.storage.ServersStorage;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Toast;

public class MediaActivity extends Activity {

	private OutputStream out;
	private ArrayBlockingQueue <Keys> entered = new ArrayBlockingQueue<Keys>(20);
	private Thread sendingThread;
	private Handler handle = new Handler();
	
	@Override
	public void onCreate(Bundle bund)
	{
		super.onCreate(bund);
		this.setContentView(R.layout.media_activity);
		try
		{
			out = ServersStorage.getSocket().getOutputStream();
		}
		catch(Exception e)
		{
			Toast.makeText(this, getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
		}
	}
	
	@Override
	public void onStart()
	{
		super.onStart();
		sendingThread = new Thread(new Runnable(){
			public void run() {
				Keys k;
				while (!Thread.interrupted())
				{
					try
					{
						k = entered.take();
						out.write(new byte[]{6,3,k.getCode()});
					}
					catch(Exception e)
					{
						handle.post(new Runnable(){

							public void run() {
								Toast.makeText(MediaActivity.this, MediaActivity.this.getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
							}});
						
						entered.clear();
					}
				}
			}
		});
		sendingThread.start();
	}
	
	@Override
	public void onStop()
	{
		super.onStop();
		sendingThread.interrupt();
	}
	public void prevClicked(View v)
	{
		entered.offer(Keys.MEDIAPREV);
	}
	public void nextClicked(View v)
	{
		entered.offer(Keys.MEDIANEXT);
	}
	public void playClicked(View v)
	{
		entered.offer(Keys.MEDIAPLAY);
	}
	public void minusClicked(View v)
	{
		entered.offer(Keys.VOLDOWN);
	}
	public void plusClicked(View v)
	{
		entered.offer(Keys.VOLUP);
	}
	
	public void goToKeyboard(View v)
	{
		startActivity(new Intent(this, KeyboardActivity.class));
	}
	public void goToMousepad(View v)
	{
		startActivity(new Intent(this, MouseActivity.class));
	}
}
