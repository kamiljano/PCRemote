package pcremote.storage;

import pcremote.custom.MouseController;
import pcremote.custom.MousePad;

public class Preferences {

	public float cursorSensitvity;
	public byte scrollSensitivity;
	public int rightClickTime;
	
	public static Preferences getDefaultPreferences()
	{
		Preferences p = new Preferences();
		p.cursorSensitvity = 0.5f;
		p.scrollSensitivity = 2;
		p.rightClickTime = 1000;
		return p;
	}
	
	public static void setUpDefaultPreferences()
	{
		getDefaultPreferences().setUp();
	}
	
	public void setUp()
	{
		MouseController.setMouseSensitivity(cursorSensitvity);
		MouseController.setScrollSensitivity(scrollSensitivity);
		MousePad.setLongClickTime(rightClickTime);
	}
}
