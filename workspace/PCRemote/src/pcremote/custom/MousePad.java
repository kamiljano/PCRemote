package pcremote.custom;

import java.io.OutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Calendar;
import java.util.concurrent.ArrayBlockingQueue;

import pcremote.activities.R;
import pcremote.storage.CursorMovementData;
import pcremote.storage.ServersStorage;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.os.Handler;
import android.util.AttributeSet;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Toast;

public class MousePad extends View {

	private Paint paint;
	private int w,h;
	
	private ArrayBlockingQueue <CursorMovementData> movements = new ArrayBlockingQueue<CursorMovementData>(20);
	private Thread sendingThread;
	
	private static int longClickTime = 1000;
	private static int buttonDownTime = 400;
	private Handler handle = new Handler();
	
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
					OutputStream o =((MouseController)getParent()).getOutputStream();
					o.write(new byte[]{3});
					o.flush();
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
					((MouseController)getParent()).getOutputStream().write(new byte[]{4});
				}
				catch(Exception e){
					Toast.makeText(MousePad.this.getContext(), MousePad.this.getContext().getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
				}
				return true;
			}
		});
		
		this.sendingThread = new Thread(new Runnable(){

			public void run() {
				CursorMovementData cmd;
				DatagramSocket clientSocket;
				InetAddress IPAddress = null;
				try
				{
					IPAddress = InetAddress.getByName(ServersStorage.getSelectedServer().Address());
				}
				catch(Exception e)
				{
					handle.post(new Runnable(){

						public void run() {
							Toast.makeText(MousePad.this.getContext(), MousePad.this.getContext().getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
						}});
					return;
				}
				while (!Thread.interrupted())
				{
					try
					{
					clientSocket = new DatagramSocket();
					cmd = movements.take();
				    DatagramPacket sendPacket = new DatagramPacket(new byte[] {1, cmd.x,cmd.y}, 3, IPAddress, 1234);
				    clientSocket.send(sendPacket);
				    clientSocket.close();
					}
					catch(Exception e)
					{
						handle.post(new Runnable(){

							public void run() {
								Toast.makeText(MousePad.this.getContext(), MousePad.this.getContext().getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
							}});
						
						movements.clear();
					}
				}
				
			}});
		sendingThread.start();
	}
	
	private void leftButtonDown()
	{
		try{
			OutputStream o =((MouseController)getParent()).getOutputStream();
			o.write(new byte[]{2,2,1});
			o.flush();
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
			OutputStream o =((MouseController)getParent()).getOutputStream();
			o.write(new byte[]{2,3,1});
			o.flush();
			leftButtonDown = false;
			Log.i("trolololo", "left button up");
		}
		catch(Exception e){
			Toast.makeText(MousePad.this.getContext(), MousePad.this.getContext().getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
		}
	}
	
	@Override
	protected void finalize() throws Throwable
	{
		super.finalize();
		sendingThread.interrupt();
	}
	
	private float x,y;
	private int lastAction = MotionEvent.ACTION_UP;
	private long lastDownTime, lastUpTime;
	private float downx, downy;
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
				movements.offer(new CursorMovementData((byte)(MouseController.getMouseSensitivity() * (nx - x)), (byte)(MouseController.getMouseSensitivity() * (ny - y))));
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