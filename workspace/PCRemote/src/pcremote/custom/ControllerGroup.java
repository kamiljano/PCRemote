package pcremote.custom;

import java.net.UnknownHostException;

import pcremote.communication.SendingThread;
import android.content.Context;
import android.util.AttributeSet;
import android.view.ViewGroup;

public abstract class ControllerGroup extends ViewGroup {

	protected SendingThread sender;
	
	public ControllerGroup(Context context) {
		super(context);
		init();
	}
	
	public ControllerGroup(Context context, AttributeSet attrs) {
		super(context, attrs);
		init();
	}
	
	public ControllerGroup(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		init();
	}
	
	private void init() {
		try {
			sender = SendingThread.getInstance();
		} catch (UnknownHostException e1) {
			e1.printStackTrace();
		}
	}
}
