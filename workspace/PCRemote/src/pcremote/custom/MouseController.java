package pcremote.custom;

import java.io.OutputStream;

import pcremote.custom.MouseScroll.Orientation;
import android.content.Context;
import android.graphics.Color;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.ViewGroup;

public class MouseController extends ViewGroup{

	private MousePad pad;
	private MouseScroll vscroll, hscroll;
	//private Button lbutton,mbutton, rbutton;
	
	private static float mouseSensitivity = 0.5f;
	private static byte scrollSensitivity = 2;
	
	private OutputStream out;
	public void setOutputStream(OutputStream out)
	{
		this.out = out;
	}
	
	public OutputStream getOutputStream()
	{
		return out;
	}
	
	public static void setMouseSensitivity(float s)
	{
		mouseSensitivity = s < 1 ? 1 : s;
	}
	
	public static float getMouseSensitivity()
	{
		return mouseSensitivity;
	}
	
	public static void setScrollSensitivity(byte s)
	{
		scrollSensitivity = s < 1 ? 1 : s;
	}
	
	public static byte getScrollSensitivity()
	{
		return scrollSensitivity;
	}
	
	
	public MouseController(Context context) {
		super(context);
		init();
	}
	
	public MouseController(Context context, AttributeSet attrs) {
		super(context, attrs);
		init();
	}
	
	public MouseController(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		init();
	}
	
	private void init()
	{
		this.setBackgroundColor(Color.DKGRAY);
		pad = new MousePad(this.getContext());
		this.hscroll = new MouseScroll(this.getContext());
		this.vscroll = new MouseScroll(this.getContext());
		//this.lbutton = new Button(this.getContext());
		//this.rbutton = new Button(this.getContext());
		//this.mbutton = new Button(this.getContext());
		hscroll.setOrientation(Orientation.Horizontal);
		this.addView(hscroll);
		this.addView(vscroll);
		this.addView(pad);
		//this.addView(lbutton);
		//this.addView(rbutton);
		/*lbutton.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				Log.i("trolololo", "Mousepad: left button clicked");
				try{
					OutputStream o = getOutputStream();
					o.write(new byte[]{3});
					o.flush();
				}
				catch(Exception e){
					Toast.makeText(MouseController.this.getContext(), MouseController.this.getContext().getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
				}
			}
		});*/
		
		/*rbutton.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				Log.i("trolololo", "Mousepad: right button clicked");
				try{
					OutputStream o = getOutputStream();
					o.write(new byte[]{4});
					o.flush();
				}
				catch(Exception e){
					Toast.makeText(MouseController.this.getContext(), MouseController.this.getContext().getString(R.string.connectionLost), Toast.LENGTH_SHORT).show();
				}
			}
		});*/
	}

	@Override
	protected void onLayout(boolean changed, int l, int t, int r, int b) {
		if (changed)
		{
			pad.layout(0,0,this.getWidth()* 95 / 100, this.getHeight()* 95 / 100);
			vscroll.layout(this.getWidth()* 95 / 100, 0, this.getWidth(), this.getHeight()* 95 / 100);
			hscroll.layout(0, this.getHeight() * 95 / 100 , this.getWidth() , this.getHeight());
			//lbutton.layout(0 , this.getHeight() / 100 *95, this.getWidth()/2, this.getHeight());
			//rbutton.layout(this.getWidth()/2, this.getHeight() / 100 *95, this.getWidth(), this.getHeight());
		}
	}
	
	@Override
	public boolean onTouchEvent(MotionEvent ev)
	{
		return false;
	}
	
}
