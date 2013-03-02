package pcremote.custom;

import java.util.Calendar;

import pcremote.activities.R;
import pcremote.communication.SendingThread;
import pcremote.communication.messages.CursorMovementMessage;
import pcremote.communication.messages.LeftButtonDownMessage;
import pcremote.communication.messages.LeftButtonUpMessage;
import pcremote.communication.messages.LeftClickMessage;
import pcremote.communication.messages.RightClickMessage;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Toast;

public class MousePad extends Controller {

	private Paint paint;
	private int w,h;
	
	private static int longClickTime = 1000;
	private static int buttonDownTime = 400;
	
	public MousePad(Context context) {
		super(context);
		init();
	}
	
	public MousePad(Context context, AttributeSet attrs) {
		super(context, attrs);
		init();
	}
	
	public MousePad(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		init();
	}
	
	public static void setLongClickTime(int t)
	{
		MousePad.longClickTime = t;
	}
	
	public static int getLongClickTime()
	{
		return MousePad.longClickTime;
	}
	
	private void init()
	{
		this.setBackgroundColor(Color.LTGRAY);
		paint = new Paint();
		paint.setColor(Color.rgb(32, 32, 32));
		//paint.measureText(this.getContext().getString(R.string.mouseInfo));
		Rect r = new Rect();
		String s = this.getContext().getString(R.string.mouseInfo);
		paint.getTextBounds(s, 0, s.length(), r);
		w = r.right - r.left;
		h = r.bottom - r.top;
		this.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				Log.i("trolololo", "Mousepad: left button clicked");
				try{
					sender.addMessage(new LeftClickMessage());
				}
				catch(Exception e){
					Toast.makeText(MousePad.this.getContext(), MousePad.this.getContext().getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
				}
			}
		});
		
		this.setOnLongClickListener(new View.OnLongClickListener() {
			
			public boolean onLongClick(View v) {
				Log.i("trolololo", "Mousepad: right button clicked");
				try{
					sender.addMessage(new RightClickMessage());
				}
				catch(Exception e){
					Toast.makeText(MousePad.this.getContext(), MousePad.this.getContext().getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
				}
				return true;
			}
		});
	}
	
	private void leftButtonDown()
	{
		try{
			sender.addMessage(new LeftButtonDownMessage());
			leftButtonDown = true;
			Log.i("trolololo", "left button down");
		}
		catch(Exception e){
			Toast.makeText(MousePad.this.getContext(), MousePad.this.getContext().getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
		}
	}
	private void leftButtonUp()
	{
		try{
			sender.addMessage(new LeftButtonUpMessage());
			leftButtonDown = false;
			Log.i("trolololo", "left button up");
		}
		catch(Exception e){
			Toast.makeText(MousePad.this.getContext(), MousePad.this.getContext().getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
		}
	}
	
	private float x,y;
	private int lastAction = MotionEvent.ACTION_UP;
	private long lastDownTime, lastUpTime;
	//private float downx, downy;
	private int steps;
	private Thread longClickThread;
	private boolean leftButtonDown = false;
	
	@Override
	public boolean onTouchEvent(MotionEvent ev)
	{
		if ((lastAction == MotionEvent.ACTION_DOWN || (lastAction == MotionEvent.ACTION_MOVE && steps < 3)) && ev.getAction() == MotionEvent.ACTION_UP)
		{
			if (Calendar.getInstance().getTimeInMillis() - lastDownTime < longClickTime)
			{
				//Log.v("trolololo", "short click");
				this.performClick();
			}
			/*else
			{
				Log.v("trolololo", "long click");
				this.performLongClick();
			}*/
		}
		lastAction = ev.getAction();
		if (ev.getAction() == MotionEvent.ACTION_UP)
		{
			lastUpTime = Calendar.getInstance().getTimeInMillis();
			if (leftButtonDown)
			{
				leftButtonUp();
			}
		}
		else if (ev.getAction() == MotionEvent.ACTION_DOWN)
		{
			x = ev.getX();
			y = ev.getY();
			steps = 0;
			lastDownTime = Calendar.getInstance().getTimeInMillis();
			if (Calendar.getInstance().getTimeInMillis() - lastUpTime < buttonDownTime)
			{
				//Log.v("trolololo", "left button down");
				leftButtonDown();
			}
			//else
			{
				longClickThread = new Thread(new Runnable(){
	
					public void run() {
						try
						{
							Thread.sleep(longClickTime);
						}
						catch(Exception e){return;}
						if (lastAction == MotionEvent.ACTION_DOWN || (lastAction == MotionEvent.ACTION_MOVE && steps < 3))
							performLongClick();
					}});
				longClickThread.start();
			}
		}
		else if (ev.getAction() == MotionEvent.ACTION_MOVE)
		{
			steps++;
			float nx = ev.getX(), ny = ev.getY();
			try
			{
				SendingThread.getInstance().addMessage(new CursorMovementMessage((byte)(MouseController.getMouseSensitivity() * (nx - x)), (byte)(MouseController.getMouseSensitivity() * (ny - y))));
			}
			catch(Exception e){}
			x = nx;
			y = ny;
		}
		return true;
	}
	
	@Override
	protected void onDraw(Canvas c)
	{
		super.onDraw(c);
		c.drawText(this.getContext().getString(R.string.mouseInfo), (this.getWidth() - w) / 2,
				(this.getHeight() - h) / 2, paint);
	}

}
