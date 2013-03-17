package pcremote.communication.messages;

public class CursorMovementMessage implements NetworkMessage {

	private byte [] message;
	
	public CursorMovementMessage(byte x, byte y) {
		message = new byte []{1, x, y};
	}
	
	public byte[] getBytes() {
		return message;
	}

	public NetworkProtocol getNetworkProtoco() {
		return NetworkProtocol.UDP;
	}

}
