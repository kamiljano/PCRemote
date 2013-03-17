package pcremote.custom;

import java.net.UnknownHostException;

import pcremote.communication.SendingThread;
import android.content.Context;
import android.util.AttributeSet;
import android.view.View;

public abstract class Controller extends View{

	protected SendingThread sender;
	
	public Controller(Context context) {
		super(context);
		init();
	}

	public Controller(Context context, AttributeSet attrs) {
		super(context, attrs);
		init();
	}
	
	public Controller(Context context, AttributeSet attrs, int defStyle) {
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
