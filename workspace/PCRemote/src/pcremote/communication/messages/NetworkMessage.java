package pcremote.communication.messages;

public interface NetworkMessage {
	
	public enum NetworkProtocol{UDP, TCP};
	public byte [] getBytes();
	public NetworkProtocol getNetworkProtoco();
}
