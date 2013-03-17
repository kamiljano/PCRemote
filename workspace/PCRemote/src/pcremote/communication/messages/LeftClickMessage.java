package pcremote.communication.messages;

public class LeftClickMessage implements NetworkMessage {
	
	private static byte [] message = new byte [] {3};	
	
	public byte[] getBytes() {
		return message;
	}

	public NetworkProtocol getNetworkProtoco() {
		return NetworkProtocol.TCP;
	}

}
