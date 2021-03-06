package pcremote.custom;

import java.io.OutputStream;

import pcremote.activities.R;
import pcremote.communication.messages.KeyboardMessage;
import android.content.Context;
import android.graphics.Color;
import android.os.Handler;
import android.util.AttributeSet;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import android.widget.ToggleButton;

public class KeyboardController extends ControllerGroup{

	public enum Keys{
		LSHIFT((byte)1),RSHIFT((byte)2),LALT((byte)3),RALT((byte)4),SPACE((byte)5),RCTRL((byte)6),LCTRL((byte)7),
		A((byte)8), B((byte)9), C((byte)10),D((byte)11),E((byte)12),F((byte)13),G((byte)14),H((byte)15),I((byte)16),
		J((byte)17),K((byte)18),L((byte)19),M((byte)20),N((byte)21),O((byte)22),P((byte)23),Q((byte)24),R((byte)25),
		S((byte)26),T((byte)27),U((byte)28),V((byte)29),W((byte)30),X((byte)31),Y((byte)32),Z((byte)33),
		COMA((byte)34),DOT((byte)35),SLASH((byte)36),SEMICOLON((byte)37),QUOTATION((byte)38), SQUAREBRACKET1((byte)39), SQUAREBRACKET2((byte)40),
		BACKSLASH((byte)41),TILDA((byte)42),B1((byte)43),B2((byte)44), B3((byte)45), B4((byte)46), B5((byte)47), B6((byte)48), B7((byte)49), B8((byte)50), B9((byte)51),B0((byte)52),
		MINUS((byte)53), EQUALS((byte)54), BACKSPACE((byte)55), ENTER((byte)56), TAB((byte)57), CAPSLOCK((byte)58), VOLUP ((byte)59), VOLDOWN ((byte)60), MEDIANEXT((byte)62), MEDIAPREV((byte)61), MEDIAPLAY((byte)63),ARROWLEFT((byte)64),ARROWRIGHT((byte)65);
		private byte code;
		public enum State {DOWN, UP, CLICK}
		public State state = State.CLICK;
		Keys(byte code)
		{
			this.code = code;
		}
		
		public byte getCode()
		{
			return code;
		}
		public static Keys translate(char c){
			switch (c)
			{
			case 'a':
				return A;
			case 'b':
				return B;
			case 'c':
				return C;
			case 'd':
				return D;
			case 'e':
				return E;
			case 'f':
				return F;
			case 'g':
				return G;
			case 'h':
				return H;
			case 'i':
				return I;
			case 'j':
				return J;
			case 'k':
				return K;
			case 'l':
				return L;
			case 'm':
				return M;
			case 'n':
				return N;
			case 'o':
				return O;
			case 'q':
				return Q;
			case 'p':
				return P;
			case 'r':
				return R;
			case 's':
				return S;
			case 't':
				return T;
			case 'u':
				return U;
			case 'v':
				return V;
			case 'w':
				return W;
			case 'x':
				return X;
			case 'y':
				return Y;
			case 'z':
				return Z;
			case '1':
				return B1;
			case '2':
				return B2;
			case '3':
				return B3;
			case '4':
				return B4;
			case '5':
				return B5;
			case '6':
				return B6;
			case '7':
				return B7;
			case '8':
				return B8;
			case '9':
				return B9;
			case '0':
				return B0;
			case '-':
				return MINUS;
			case '_':
				return MINUS;
			case '=':
				return EQUALS;
			case '+':
				return EQUALS;
			case '[':
				return SQUAREBRACKET1;
			case '{':
				return SQUAREBRACKET1;
			case ']':
				return SQUAREBRACKET2;
			case '}':
				return SQUAREBRACKET2;
			case '\\':
				return BACKSLASH;
			case '|':
				return BACKSLASH;
			case '~':
				return TILDA;
			case '`':
				return TILDA;
			case ',':
				return COMA;
			case '<':
				return COMA;
			case '.':
				return DOT;
			case '>':
				return DOT;
			case '/':
				return SLASH;
			case '?':
				return SLASH;
			case ';':
				return SEMICOLON;
			case ':':
				return SEMICOLON;
			case '\'':
				return QUOTATION;
			case '"':
				return QUOTATION;
			case ')':
				return B0;
			case '(':
				return B9;
			case '*':
				return B8;
			case '&':
				return B7;
			case '^':
				return B6;
			case '%':
				return B5;
			case '$':
				return B4;
			case '#':
				return B3;
			case '@':
				return B2;
			case '!':
				return B1;
			}
			return null;
		}
	}
	private Button lctrl, lalt, space, rctrl;
	private ToggleButton ralt,capsLock;
	private Button lshift,z,x,c,v,b,n,m,coma,dot,slash,rshift;
	private Button a,s,d,f,g,h,j,k,l,semicolon,quotation,enter;
	private Button tab, q,w,e,r,t,y,u,i,o,p,squareBracket1, squareBracket2, backslash;
	private Button tilda, b1,b2,b3,b4,b5,b6,b7,b8,b9,b0,minus, equals, backspace;
	
	private boolean shift = false;
	private boolean alt = false;
	private boolean caps = false;
	private Handler handle = new Handler();
	
	public KeyboardController(Context context) {
		super(context);
		init();
	}
	
	public KeyboardController(Context context, AttributeSet attrs) {
		super(context, attrs);
		init();
	}
	
	public KeyboardController(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		init();
	}
	
	private void init()
	{
		this.setBackgroundColor(Color.DKGRAY);
		
		lctrl = new Button(this.getContext());
		lalt = new Button(this.getContext());
		space = new Button(this.getContext());;
		ralt = new ToggleButton(this.getContext());
		rctrl = new Button(this.getContext());
		
		lctrl.setText("Ctrl");
		lalt.setText("Alt");
		ralt.setTextOn("Alt");
		ralt.setText("Alt");
		ralt.setTextOff("Alt");
		rctrl.setText("Ctrl");
		space.setText(" ");
		
		this.addView(lctrl);
		this.addView(lalt);
		this.addView(space);
		this.addView(ralt);
		this.addView(rctrl);
		
		lshift = new Button(this.getContext());
		z = new Button(this.getContext());
		x = new Button(this.getContext());
		c = new Button(this.getContext());
		v = new Button(this.getContext());
		b = new Button(this.getContext());
		n = new Button(this.getContext());
		m = new Button(this.getContext());
		coma = new Button(this.getContext());
		dot = new Button(this.getContext());
		slash = new Button(this.getContext());
		rshift = new Button(this.getContext());
		
		z.setOnClickListener(charButtonListener);
		x.setOnClickListener(charButtonListener);
		c.setOnClickListener(charButtonListener);
		v.setOnClickListener(charButtonListener);
		b.setOnClickListener(charButtonListener);
		n.setOnClickListener(charButtonListener);
		m.setOnClickListener(charButtonListener);
		coma.setOnClickListener(charButtonListener);
		dot.setOnClickListener(charButtonListener);
		slash.setOnClickListener(charButtonListener);
		
		lshift.setText("Shift");
		rshift.setText("Shift");
		
		this.addView(lshift);
		this.addView(z);
		this.addView(x);
		this.addView(c);
		this.addView(v);
		this.addView(b);
		this.addView(n);
		this.addView(m);
		this.addView(coma);
		this.addView(dot);
		this.addView(slash);
		this.addView(rshift);
		
		capsLock = new ToggleButton(this.getContext());
		a = new Button(this.getContext());
		s = new Button(this.getContext());
		d = new Button(this.getContext());
		f = new Button(this.getContext());
		g = new Button(this.getContext());
		h = new Button(this.getContext());
		j = new Button(this.getContext());
		k = new Button(this.getContext());
		l = new Button(this.getContext());
		semicolon = new Button(this.getContext());
		quotation = new Button(this.getContext());
		enter = new Button(this.getContext());
		
		capsLock.setTextOn("Caps");
		capsLock.setTextOff("Caps");
		capsLock.setText("Caps");
		enter.setText("↵");
		
		a.setOnClickListener(charButtonListener);
		s.setOnClickListener(charButtonListener);
		d.setOnClickListener(charButtonListener);
		f.setOnClickListener(charButtonListener);
		g.setOnClickListener(charButtonListener);
		h.setOnClickListener(charButtonListener);
		j.setOnClickListener(charButtonListener);
		k.setOnClickListener(charButtonListener);
		l.setOnClickListener(charButtonListener);
		semicolon.setOnClickListener(charButtonListener);
		quotation.setOnClickListener(charButtonListener);
		
		this.addView(capsLock);
		this.addView(a);
		this.addView(s);
		this.addView(d);
		this.addView(f);
		this.addView(g);
		this.addView(h);
		this.addView(j);
		this.addView(k);
		this.addView(l);
		this.addView(semicolon);
		this.addView(quotation);
		this.addView(enter);
		
		tab = new Button(this.getContext());
		q = new Button(this.getContext());
		w = new Button(this.getContext());
		e = new Button(this.getContext());
		r = new Button(this.getContext());
		t = new Button(this.getContext());
		y = new Button(this.getContext());
		u = new Button(this.getContext());
		i = new Button(this.getContext());
		o = new Button(this.getContext());
		p = new Button(this.getContext());
		squareBracket1 = new Button(this.getContext());
		squareBracket2 = new Button(this.getContext());
		backslash = new Button(this.getContext());
		
		tab.setText("⇆");
		
		q.setOnClickListener(charButtonListener);
		w.setOnClickListener(charButtonListener);
		e.setOnClickListener(charButtonListener);
		r.setOnClickListener(charButtonListener);
		t.setOnClickListener(charButtonListener);
		y.setOnClickListener(charButtonListener);
		u.setOnClickListener(charButtonListener);
		i.setOnClickListener(charButtonListener);
		o.setOnClickListener(charButtonListener);
		p.setOnClickListener(charButtonListener);
		squareBracket1.setOnClickListener(charButtonListener);
		squareBracket2.setOnClickListener(charButtonListener);
		backslash.setOnClickListener(charButtonListener);
		
		this.addView(tab);
		this.addView(q);
		this.addView(w);
		this.addView(e);
		this.addView(r);
		this.addView(t);
		this.addView(y);
		this.addView(u);
		this.addView(i);
		this.addView(o);
		this.addView(p);
		this.addView(squareBracket1);
		this.addView(squareBracket2);
		this.addView(backslash);
		
		tilda = new Button(this.getContext());
		b1 = new Button(this.getContext());
		b2 = new Button(this.getContext());
		b3 = new Button(this.getContext());
		b4 = new Button(this.getContext());
		b5 = new Button(this.getContext());
		b6 = new Button(this.getContext());
		b7 = new Button(this.getContext());
		b8 = new Button(this.getContext());
		b9 = new Button(this.getContext());
		b0 = new Button(this.getContext());
		minus = new Button(this.getContext());
		equals = new Button(this.getContext());
		backspace = new Button(this.getContext());
		
		tilda.setOnClickListener(charButtonListener);
		b1.setOnClickListener(charButtonListener);
		b2.setOnClickListener(charButtonListener);
		b3.setOnClickListener(charButtonListener);
		b4.setOnClickListener(charButtonListener);
		b5.setOnClickListener(charButtonListener);
		b6.setOnClickListener(charButtonListener);
		b7.setOnClickListener(charButtonListener);
		b8.setOnClickListener(charButtonListener);
		b9.setOnClickListener(charButtonListener);
		b0.setOnClickListener(charButtonListener);
		minus.setOnClickListener(charButtonListener);
		equals.setOnClickListener(charButtonListener);
		
		this.addView(tilda);
		this.addView(b1);
		this.addView(b2);
		this.addView(b3);
		this.addView(b4);
		this.addView(b5);
		this.addView(b6);
		this.addView(b7);
		this.addView(b8);
		this.addView(b9);
		this.addView(b0);
		this.addView(minus);
		this.addView(equals);
		this.addView(backspace);
		
		backspace.setText("←");
		
		setLowerCase();
		
		lshift.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				toggleShift();
				Keys k = Keys.LSHIFT;
				k.state = shift ? Keys.State.DOWN : Keys.State.UP;
				sender.addMessage(new KeyboardMessage(k));
			}
		});
		rshift.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				toggleShift();
				Keys k = Keys.RSHIFT;
				k.state = shift ? Keys.State.DOWN : Keys.State.UP;
				sender.addMessage(new KeyboardMessage(k));
			}
		});
		enter.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				sender.addMessage(new KeyboardMessage(Keys.ENTER));
			}
		});
		lctrl.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				sender.addMessage(new KeyboardMessage(Keys.LCTRL));
			}
		});
		rctrl.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				sender.addMessage(new KeyboardMessage(Keys.RCTRL));
			}
		});
		lalt.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				sender.addMessage(new KeyboardMessage(Keys.LALT));
			}
		});
		ralt.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				Keys k = Keys.RALT;
				alt = !alt;
				k.state = alt ? Keys.State.DOWN : Keys.State.UP;
				sender.addMessage(new KeyboardMessage(k));
			}
		});
		tab.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				sender.addMessage(new KeyboardMessage(Keys.TAB));
			}
		});
		backspace.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				sender.addMessage(new KeyboardMessage(Keys.BACKSPACE));
			}
		});
		space.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				sender.addMessage(new KeyboardMessage(Keys.SPACE));
			}
		});
		capsLock.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				Keys k = Keys.CAPSLOCK;
				toggleCaps();
				sender.addMessage(new KeyboardMessage(k));
			}
		});
	}
	
	private View.OnClickListener charButtonListener = new View.OnClickListener() {
		
		public void onClick(View v) {
			Button but = (Button)v;
			String s = but.getText().toString();
			Keys k = Keys.translate(s.toLowerCase().charAt(0));
			sender.addMessage(new KeyboardMessage(k));
			if (shift)
			{
				toggleShift();
				Keys k2 = Keys.LSHIFT;
				k2.state = Keys.State.UP;
				sender.addMessage(new KeyboardMessage(k2));
			}
		}
	};
	
	private void toggleCaps()
	{
		if (caps)
			unsetCaps();
		else
			setCaps();
	}
	
	private void setCaps()
	{
		caps = true;
	}
	
	private void unsetCaps()
	{
		caps = false;
	}
	private void toggleShift()
	{
		if (shift)
			setLowerCase();
		else
			setUpperCase();
	}
	
	private void setUpperCase()
	{
		shift = true;
		z.setText("Z");
		x.setText("X");
		c.setText("C");
		v.setText("V");
		b.setText("B");
		n.setText("N");
		m.setText("M");
		coma.setText("<");
		dot.setText(">");
		slash.setText("?");
		
		a.setText("A");
		s.setText("S");
		d.setText("D");
		f.setText("F");
		g.setText("G");
		h.setText("H");
		j.setText("J");
		k.setText("K");
		l.setText("L");
		semicolon.setText(":");
		quotation.setText("\"");
		
		q.setText("Q");
		w.setText("W");
		e.setText("E");
		r.setText("R");
		t.setText("T");
		y.setText("Y");
		u.setText("U");
		i.setText("I");
		o.setText("O");
		p.setText("P");
		squareBracket1.setText("{");
		squareBracket2.setText("}");
		backslash.setText("|");
		
		tilda.setText("~");
		b1.setText("!");
		b2.setText("@");
		b3.setText("#");
		b4.setText("$");
		b5.setText("%");
		b6.setText("^");
		b7.setText("&");
		b8.setText("*");
		b9.setText("(");
		b0.setText(")");
		minus.setText("_");
		equals.setText("+");
	}
	
	private void setLowerCase()
	{
		shift = false;
		z.setText("z");
		x.setText("x");
		c.setText("c");
		v.setText("v");
		b.setText("b");
		n.setText("n");
		m.setText("m");
		coma.setText(",");
		dot.setText(".");
		slash.setText("/");
		
		a.setText("a");
		s.setText("s");
		d.setText("d");
		f.setText("f");
		g.setText("g");
		h.setText("h");
		j.setText("j");
		k.setText("k");
		l.setText("l");
		semicolon.setText(";");
		quotation.setText("'");
		
		q.setText("q");
		w.setText("w");
		e.setText("e");
		r.setText("r");
		t.setText("t");
		y.setText("y");
		u.setText("u");
		i.setText("i");
		o.setText("o");
		p.setText("p");
		squareBracket1.setText("[");
		squareBracket2.setText("]");
		backslash.setText("\\");
		
		tilda.setText("`");
		b1.setText("1");
		b2.setText("2");
		b3.setText("3");
		b4.setText("4");
		b5.setText("5");
		b6.setText("6");
		b7.setText("7");
		b8.setText("8");
		b9.setText("9");
		b0.setText("0");
		minus.setText("-");
		equals.setText("=");
	}

	@Override
	protected void onLayout(boolean changed, int lo, int to, int ro, int bo) {
		if (changed)
		{
			final int numberOfRows = 5;
			final int rowHeight = this.getHeight() / numberOfRows;
			final int row1Top = this.getHeight() - rowHeight;
			final int row1Bottom = this.getHeight();
			final int row2Top = row1Top - rowHeight;
			final int row2Bottom = row1Top;
			final int row3Top = row2Top - rowHeight;
			final int row3Bottom = row2Top;
			final int row4Top = row3Top - rowHeight;
			final int row4Bottom = row3Top;
			final int row5Top = row4Top - rowHeight;
			final int row5Bottom = row4Top;
			
			lctrl.layout(0, row1Top, this.getWidth()/6, row1Bottom);
			lalt.layout(this.getWidth()/6, row1Top, this.getWidth()/3, row1Bottom);
			space.layout(this.getWidth()/3, row1Top, this.getWidth()*4/6, row1Bottom);
			ralt.layout(this.getWidth()*4/6, row1Top, this.getWidth()*5/6, row1Bottom);
			rctrl.layout(this.getWidth()*5/6, row1Top, this.getWidth(), row1Bottom);
			
			lshift.layout(0, row2Top, this.getWidth()*2/14, row2Bottom);
			z.layout(this.getWidth()*2/14, row2Top, this.getWidth()*3/14, row2Bottom);
			x.layout(this.getWidth()*3/14, row2Top, this.getWidth()*4/14, row2Bottom);
			c.layout(this.getWidth()*4/14, row2Top, this.getWidth()*5/14, row2Bottom);
			v.layout(this.getWidth()*5/14, row2Top, this.getWidth()*6/14, row2Bottom);
			b.layout(this.getWidth()*6/14, row2Top, this.getWidth()*7/14, row2Bottom);
			n.layout(this.getWidth()*7/14, row2Top, this.getWidth()*8/14, row2Bottom);
			m.layout(this.getWidth()*8/14, row2Top, this.getWidth()*9/14, row2Bottom);
			coma.layout(this.getWidth()*9/14, row2Top, this.getWidth()*10/14, row2Bottom);
			dot.layout(this.getWidth()*10/14, row2Top, this.getWidth()*11/14, row2Bottom);
			slash.layout(this.getWidth()*11/14, row2Top, this.getWidth()*12/14, row2Bottom);
			rshift.layout(this.getWidth()*12/14, row2Top, this.getWidth(), row2Bottom);
			
			capsLock.layout(0, row3Top, this.getWidth()*2/15, row3Bottom);
			a.layout(this.getWidth()*2/15, row3Top, this.getWidth()*3/15, row3Bottom);
			s.layout(this.getWidth()*3/15, row3Top, this.getWidth()*4/15, row3Bottom);
			d.layout(this.getWidth()*4/15, row3Top, this.getWidth()*5/15, row3Bottom);
			f.layout(this.getWidth()*5/15, row3Top, this.getWidth()*6/15, row3Bottom);
			g.layout(this.getWidth()*6/15, row3Top, this.getWidth()*7/15, row3Bottom);
			h.layout(this.getWidth()*7/15, row3Top, this.getWidth()*8/15, row3Bottom);
			j.layout(this.getWidth()*8/15, row3Top, this.getWidth()*9/15, row3Bottom);
			k.layout(this.getWidth()*9/15, row3Top, this.getWidth()*10/15, row3Bottom);
			l.layout(this.getWidth()*10/15, row3Top, this.getWidth()*11/15, row3Bottom);
			semicolon.layout(this.getWidth()*11/15, row3Top, this.getWidth()*12/15, row3Bottom);
			quotation.layout(this.getWidth()*12/15, row3Top, this.getWidth()*13/15, row3Bottom);
			enter.layout(this.getWidth()*13/15, row3Top, this.getWidth(), row3Bottom);
			
			tab.layout(0, row4Top, this.getWidth()*2/15, row4Bottom);
			q.layout(this.getWidth()*2/15, row4Top, this.getWidth()*3/15, row4Bottom);
			w.layout(this.getWidth()*3/15, row4Top, this.getWidth()*4/15, row4Bottom);
			e.layout(this.getWidth()*4/15, row4Top, this.getWidth()*5/15, row4Bottom);
			r.layout(this.getWidth()*5/15, row4Top, this.getWidth()*6/15, row4Bottom);
			t.layout(this.getWidth()*6/15, row4Top, this.getWidth()*7/15, row4Bottom);
			y.layout(this.getWidth()*7/15, row4Top, this.getWidth()*8/15, row4Bottom);
			u.layout(this.getWidth()*8/15, row4Top, this.getWidth()*9/15, row4Bottom);
			i.layout(this.getWidth()*9/15, row4Top, this.getWidth()*10/15, row4Bottom);
			o.layout(this.getWidth()*10/15, row4Top, this.getWidth()*11/15, row4Bottom);
			p.layout(this.getWidth()*11/15, row4Top, this.getWidth()*12/15, row4Bottom);
			squareBracket1.layout(this.getWidth()*12/15, row4Top, this.getWidth()*13/15, row4Bottom);
			squareBracket2.layout(this.getWidth()*13/15, row4Top, this.getWidth()*14/15, row4Bottom);
			backslash.layout(this.getWidth()*14/15, row4Top, this.getWidth(), row4Bottom);
			
			tilda.layout(0, row5Top, this.getWidth() / 15, row5Bottom);
			b1.layout(this.getWidth() / 15, row5Top, this.getWidth() *2 / 15, row5Bottom);
			b2.layout(this.getWidth() *2/ 15, row5Top, this.getWidth() *3 / 15, row5Bottom);
			b3.layout(this.getWidth() *3/ 15, row5Top, this.getWidth() *4 / 15, row5Bottom);
			b4.layout(this.getWidth() *4/ 15, row5Top, this.getWidth() *5 / 15, row5Bottom);
			b5.layout(this.getWidth() *5/ 15, row5Top, this.getWidth() *6 / 15, row5Bottom);
			b6.layout(this.getWidth() *6/ 15, row5Top, this.getWidth() *7 / 15, row5Bottom);
			b7.layout(this.getWidth() *7/ 15, row5Top, this.getWidth() *8 / 15, row5Bottom);
			b8.layout(this.getWidth() *8/ 15, row5Top, this.getWidth() *9 / 15, row5Bottom);
			b9.layout(this.getWidth() *9/ 15, row5Top, this.getWidth() *10 / 15, row5Bottom);
			b0.layout(this.getWidth() *10/ 15, row5Top, this.getWidth() *11 / 15, row5Bottom);
			minus.layout(this.getWidth() *11/ 15, row5Top, this.getWidth() *12 / 15, row5Bottom);
			equals.layout(this.getWidth() *12/ 15, row5Top, this.getWidth() *13 / 15, row5Bottom);
			backspace.layout(this.getWidth() *13/ 15, row5Top, this.getWidth(), row5Bottom);
			
		}
	}

}
