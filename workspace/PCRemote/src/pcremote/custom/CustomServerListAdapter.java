package pcremote.custom;

import pcremote.activities.R;
import pcremote.storage.ServerData;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

public class CustomServerListAdapter extends ArrayAdapter<String>{

	private final Context context;
	private final ServerData[] values;
	
	public CustomServerListAdapter(Context context, ServerData [] values)
	{
		super(context, R.layout.activity_servers);
		this.context = context;
		this.values = values;
	}
	
	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		LayoutInflater inflater = (LayoutInflater) context
			.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
 
		View rowView = inflater.inflate(R.layout.activity_servers, parent, false);
		//TextView label = (TextView) rowView.findViewById(R.id.label);
		//label.setText("asdfasdf");
 
		return rowView;
	}
}
