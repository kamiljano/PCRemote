package pcremote.custom;

import pcremote.activities.R;
import android.content.Context;
import android.text.InputType;
import android.util.AttributeSet;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.inputmethod.BaseInputConnection;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputConnection;
import android.view.inputmethod.InputMethodManager;
import android.widget.ImageView;

public class KeyboardButton extends ImageView {

	public KeyboardButton(Context context) {
		super(context);
		init();
	}
	
	public KeyboardButton(Context context, AttributeSet attrs) {
		super(context, attrs);
		init();
	}
	public KeyboardButton(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		init();
	}
	
	private void init()
	{
		this.setFocusable(true);
		this.setFocusableInTouchMode(true);
		this.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				InputMethodManager imm = (InputMethodManager) KeyboardButton.this.getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
				imm.toggleSoftInput(InputMethodManager.SHOW_FORCED,0);
			}
		});
		this.setImageResource(R.drawable.keyboard_icon);
	}
	
	@Override
	public boolean onKeyUp(int keycode, KeyEvent event)
	{
		super.onKeyUp(keycode, event);
		Log.v("trolololo", "button pressed");
		return true;
	}
	
	@Override
	public boolean onCheckIsTextEditor ()
	{
		return true;
	}
	
	@Override
	public InputConnection onCreateInputConnection (EditorInfo outAttrs)
	{
		Log.v("trolololo", "Keyboard connection created");
        BaseInputConnection fic = new BaseInputConnection(this, false);
        outAttrs.actionLabel = null;
        outAttrs.inputType = InputType.TYPE_NULL;
        outAttrs.imeOptions = EditorInfo.IME_ACTION_NEXT;
        return fic;
	}
}
