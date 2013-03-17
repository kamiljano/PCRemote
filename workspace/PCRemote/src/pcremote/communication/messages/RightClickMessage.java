package pcremote.communication.messages;

public class RightClickMessage implements NetworkMessage {

	private static byte [] message = new byte [] {4};
	
	public byte[] getBytes() {
		return message;
	}

	public NetworkProtocol getNetworkProtoco() {
		return NetworkProtocol.TCP;
	}

	
}
