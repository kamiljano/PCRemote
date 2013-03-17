package pcremote.communication.messages;

public class LeftButtonUpMessage implements NetworkMessage {

	private static byte [] message = new byte[]{2,3,1};
	
	public byte[] getBytes() {
		return message;
	}

	public NetworkProtocol getNetworkProtoco() {
		return NetworkProtocol.TCP;
	}

}
