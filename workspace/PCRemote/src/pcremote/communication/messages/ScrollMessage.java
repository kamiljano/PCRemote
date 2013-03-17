package pcremote.communication.messages;

public class ScrollMessage implements NetworkMessage {

	public enum Orientation {Horizontal, Vertical};
	private byte [] message;
	
	public ScrollMessage (Orientation orientation, byte value) {
		byte o;
		if (orientation == Orientation.Vertical) {
			o = 1;
		} else {
			o = 2;
		}
		message = new byte [] {1, o, value};
	}
	
	public byte[] getBytes() {
		return message;
	}

	public NetworkProtocol getNetworkProtoco() {
		return NetworkProtocol.TCP;
	}

}
