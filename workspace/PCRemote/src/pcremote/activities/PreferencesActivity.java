package pcremote.activities;

import pcremote.storage.Preferences;
import pcremote.storage.PreferencesStorage;
import android.app.Activity;
import android.os.Bundle;
import android.widget.SeekBar;
import android.widget.Toast;

public class PreferencesActivity extends Activity{

	private SeekBar cursorSens, scrollSens, rightClickTime;
	
	@Override
	public void onCreate(Bundle bund)
	{
		super.onCreate(bund);
		setContentView(R.layout.preferences_activity);
		cursorSens = (SeekBar)findViewById(R.id.cursorSens);
		cursorSens.setMax(100);
		scrollSens = (SeekBar)findViewById(R.id.scrollSens);
		scrollSens.setMax(10);
		rightClickTime = (SeekBar) findViewById (R.id.rightClickTime);
		rightClickTime.setMax(500);
		try
		{
			Preferences p = PreferencesStorage.getPreferences();
			setPreferences(p);
		}
		catch(Exception e)
		{
			Preferences p = Preferences.getDefaultPreferences();
			setPreferences(p);
		}
	}
	
	private void setPreferences(Preferences p)
	{
		cursorSens.setProgress((int)(p.cursorSensitvity * 100));
		scrollSens.setProgress(p.scrollSensitivity);
		rightClickTime.setProgress(p.rightClickTime / 10);
	}
	
	
	@Override
	public void onStop()
	{
		super.onStop();
		PreferencesStorage.setContext(this);
		try
		{
			float a = (float)(cursorSens.getProgress()/100.0);
			if (a == 0) a = 0.1f;
			byte b = (byte)scrollSens.getProgress();
			if (b == 0) b = 1;
			int c = rightClickTime.getProgress() * 10;
			if (c == 0) c = 1000;
			PreferencesStorage.savePreferences(a, b, c);
		}
		catch (Exception e)
		{
			Toast.makeText(this, getString(R.string.prefsStoreFail), Toast.LENGTH_SHORT).show();
		}
	}
}
