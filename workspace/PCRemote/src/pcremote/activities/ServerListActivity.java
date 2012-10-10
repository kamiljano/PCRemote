package pcremote.activities;

import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketAddress;

import pcremote.dialogs.ConnectionDialog;
import pcremote.dialogs.ServerInfoDialog;
import pcremote.storage.ServerData;
import pcremote.storage.ServersStorage;
import android.app.ListActivity;
import android.app.ProgressDialog;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.ContextMenu;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.AdapterContextMenuInfo;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

public class ServerListActivity extends ListActivity{
	
	private ServerData [] sd = null;
	private ArrayAdapter<String>adapter;
	private ProgressDialog progress;
	
	@Override
	public void onCreate(Bundle b)
	{
		super.onCreate(b);
		
		ListView listView = getListView();
		listView.setTextFilterEnabled(true);
		this.registerForContextMenu(listView);
 
		listView.setOnItemClickListener(new OnItemClickListener() {
			public void onItemClick(AdapterView<?> parent, View view,
					int position, long id) {
			    //Toast.makeText(getApplicationContext(),((TextView) view).getText(), Toast.LENGTH_SHORT).show();
				ServersStorage.selectServer(sd[position]);
				progress = new ConnectionDialog(ServerListActivity.this, sd[position].Address(), sd[position].Port());//new ProgressDialog(ServerListActivity.this);
				//progress.setCancelable(true);
				//progress.setMessage(getString(R.string.connecting));
				progress.show();
				//new Thread(new Test(progress,sd[position], new Handler())).start();
				//Toast.makeText(ServerListActivity.this, Integer.toString(position), Toast.LENGTH_SHORT).show();
			}
		});
	}
	
	class Test implements Runnable
	{
		private ProgressDialog pd;
		private ServerData sd;
		private Handler h;
		
		public Test(ProgressDialog pd, ServerData sd, Handler h)
		{
			this.pd = pd;
			this.sd = sd;
			this.h = h;
		}
		
		public void run()
		{
			SocketAddress sockaddr = new InetSocketAddress(sd.Address(), sd.Port());
			Socket sock = new Socket();
			try
			{
				sock.connect(sockaddr, 5000);
			}
			catch(Exception e)
			{
				h.post(new Runnable(){
					
					public void run()
					{
						Toast.makeText(ServerListActivity.this, getString(R.string.connectionFail), Toast.LENGTH_SHORT).show();
						pd.dismiss();
					}
				});
				return;
			}
			ServersStorage.setSocket(sock);
			h.post(new Runnable(){
				
				public void run()
				{
					Toast.makeText(ServerListActivity.this, getString(R.string.connected), Toast.LENGTH_SHORT).show();
					pd.dismiss();
					ServerListActivity.this.finish();
				}
			});
		}
	}
	
	@Override
	public void onStart()
	{
		super.onStart();
		setAdapter();
	}
	
	private void setAdapter()
	{
		ServersStorage ss = new ServersStorage (this);
		try
		{
			sd = ss.getServers();
		}
		catch(Exception e)
		{
			Toast.makeText(this, "Unable to load servers", Toast.LENGTH_SHORT).show();
			return;
		}
		if (sd.length == 0)
			startActivity(new Intent(this, AddServerActivity.class));
		String [] strs =  new String[sd.length];//new String[]{"sdf","asdf"};// new String[sd.length];
		for (int i=0; i<sd.length; i++)
			strs[i] = sd[i].Name();
		adapter = new ArrayAdapter<String>(this, R.layout.activity_servers,strs);
		setListAdapter(adapter);//(new CustomServerListAdapter(this, sd));
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
	    MenuInflater inflater = getMenuInflater();
	    inflater.inflate(R.menu.serverlist_options_menu, menu);
	    return true;
	}
	
	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
	    switch (item.getItemId()) {
	    case R.id.add:
	    	Intent i = new Intent(this, AddServerActivity.class);
	    	i.putExtra("userCall", true);
	    	startActivity(i);
	    	return true;
	    default:
	            return super.onOptionsItemSelected(item);
	    }
	}
	
	@Override
	public void onCreateContextMenu(ContextMenu menu, View v,
	                                ContextMenuInfo menuInfo) {
	    super.onCreateContextMenu(menu, v, menuInfo);
	    MenuInflater inflater = getMenuInflater();
	    inflater.inflate(R.menu.serverlist_context_menu, menu);
	}
	
	@Override
	public boolean onContextItemSelected(MenuItem item) {
	    AdapterContextMenuInfo info = (AdapterContextMenuInfo) item.getMenuInfo();
	    switch (item.getItemId()) {
	        case R.id.remove:
	        	ServersStorage ss = new ServersStorage(this);
	        	try
	        	{
	        		ss.removeServer(sd[info.position]);
	        	}
	        	catch(Exception e)
	        	{
	        		Toast.makeText(this, "Failed to remove server data", Toast.LENGTH_SHORT).show();
	        	}
	        	setAdapter();
	            return true;
	        case R.id.edit:
	        	Intent i = new Intent(this, AddServerActivity.class);
	        	i.putExtra("sname", this.sd[info.position].Name());
	        	i.putExtra("saddr", this.sd[info.position].Address());
	        	i.putExtra("sport", Integer.toString(this.sd[info.position].Port()));
	        	startActivity(i);
	        	return true;
	        case R.id.info:
	        	ServerInfoDialog sd = new ServerInfoDialog(this, this.sd[info.position]);
	        	sd.show();
	            return true;
	        default:
	            return super.onContextItemSelected(item);
	    }
	}
}
