package pcremote.storage;

public class ServerData {

	private String name, address;
	private int port = 0;
	
	public ServerData(String name, String address, int port)
	{
		this.name = name;
		this.address = address;
		this.port = port;
	}
	
	public String Name()
	{
		return name;
	}
	
	public String Address()
	{
		return address;
	}
	
	public int Port()
	{
		return port;
	}
	
	@Override
	public String toString()
	{
		return name;
	}
}
