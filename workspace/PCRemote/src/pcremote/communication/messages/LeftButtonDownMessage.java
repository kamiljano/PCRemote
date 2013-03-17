package pcremote.communication.messages;

public class LeftButtonDownMessage implements NetworkMessage {

	private static byte [] message = new byte[]{2,2,1};
	
	public byte[] getBytes() {
		return message;
	}

	public NetworkProtocol getNetworkProtoco() {
		return NetworkProtocol.TCP;
	}

}
