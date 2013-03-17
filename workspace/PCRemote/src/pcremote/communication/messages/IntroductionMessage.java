package pcremote.communication.messages;

public class IntroductionMessage implements NetworkMessage {

	public byte[] getBytes() {
		return new byte[]{5,1};
	}

	public NetworkProtocol getNetworkProtoco() {
		return NetworkProtocol.TCP;
	}

	
}
