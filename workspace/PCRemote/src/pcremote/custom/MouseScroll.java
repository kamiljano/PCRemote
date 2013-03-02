package pcremote.custom;

import pcremote.activities.R;
import pcremote.communication.messages.ScrollMessage;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.util.Log;
import android.view.MotionEvent;
import android.widget.Toast;

public class MouseScroll extends Controller{

	public enum Orientation{Vertical, Horizontal};
	private Orientation or = Orientation.Vertical;
	
	private Paint paint;
	private int textw, texth;
	
	public void setOrientation (Orientation or)
	{
		this.or = or;
	}
	
	public MouseScroll(Context context) {
		super(context);
		init();
	}
	
	public MouseScroll(Context context, AttributeSet attrs) {
		super(context, attrs);
		init();
	}
	
	public MouseScroll(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		init();
	}
	
	private void init()
	{
		this.setBackgroundColor(Color.LTGRAY);
		paint = new Paint();
		paint.setColor(Color.rgb(32, 32, 32));
		Rect r= new Rect();
		paint.getTextBounds("Scroll Y", 0, 8, r);
		textw = r.right - r.left;
		texth = r.bottom - r.top;
	}
	
	@Override
	public void onDraw(Canvas c)
	{
		if (or == Orientation.Vertical)
		{
			c.drawLine(this.getWidth() / 2, this.getHeight() / 100 * 5,
					this.getWidth() / 2, this.getHeight() / 100 * 95, paint);
		}
		else
		{
			c.drawLine(this.getWidth() / 100 * 5, this.getHeight() / 2,
					this.getWidth() / 100 * 95, this.getHeight() / 2, paint);
		}
	}
	
	//private boolean down = false;
	private float last = 0;
	
	@Override
	public boolean onTouchEvent(MotionEvent ev)
	{
		if (or == Orientation.Horizontal)
		{
			int act = ev.getAction();
			if (act == MotionEvent.ACTION_DOWN)
				last = ev.getX();
			else if (act == MotionEvent.ACTION_MOVE)
			{
				Log.v("trolololo", "Horizontal scroll move");
				try
				{
					//((MouseController)getParent()).getOutputStream().write(new byte[]{1,2, last < ev.getX() ? MouseController.getScrollSensitivity() : (byte)(MouseController.getScrollSensitivity() * (-1))}); // scroll, horizontal, up/down
					sender.addMessage(new ScrollMessage(ScrollMessage.Orientation.Horizontal, last < ev.getX() ? MouseController.getScrollSensitivity() : (byte)(MouseController.getScrollSensitivity() * (-1))));
					
					last = ev.getX();
				}
				catch (Exception e)
				{
					Toast.makeText(this.getContext(), this.getContext().getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
				}
				
			}
		}
		else    //vertical
		{
			int act = ev.getAction();
			if (act == MotionEvent.ACTION_DOWN)
				last = ev.getY();
			else if (act == MotionEvent.ACTION_MOVE)
			{
				Log.v("trolololo", "Vertical scroll move");
				try
				{
					//((MouseController)getParent()).getOutputStream().write(new byte[]{1,1, last < ev.getY() ? MouseController.getScrollSensitivity() : (byte)(MouseController.getScrollSensitivity() * (-1))}); // scroll, horizontal, up/down
					sender.addMessage(new ScrollMessage(ScrollMessage.Orientation.Vertical, last < ev.getY() ? MouseController.getScrollSensitivity() : (byte)(MouseController.getScrollSensitivity() * (-1))));
					last = ev.getY();
				}
				catch (Exception e)
				{
					Toast.makeText(this.getContext(), this.getContext().getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
				}
				
			}
		}
		return true;
	}

}
