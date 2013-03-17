package pcremote.communication.messages;

import pcremote.custom.KeyboardController.Keys;

public class KeyboardMessage implements NetworkMessage{

	private byte [] message = null;
	
	public KeyboardMessage (Keys k) {
		byte stateByte = 0;
		if (k.state == Keys.State.CLICK)
			stateByte = 3;
		else if (k.state == Keys.State.DOWN)
			stateByte = 1;
		else
			stateByte = 2;
		message = new byte [] {6,stateByte, k.getCode()};
	}
	
	public byte[] getBytes() {
		return message;
	}

	public NetworkProtocol getNetworkProtoco() {
		return NetworkProtocol.TCP;
	}

}
