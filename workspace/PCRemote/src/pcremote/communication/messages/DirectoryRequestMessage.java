package pcremote.communication.messages;

public class DirectoryRequestMessage implements NetworkMessage {

	private byte [] message;
	
	public DirectoryRequestMessage(String path) {
		byte [] buff = path.getBytes();
		message = new byte[buff.length + 1];
		message[0] = 8;
		for (int i = 0; i < buff.length; i++) {
			message[i + 1] = buff[i];
		}
	}
	
	public byte[] getBytes() {
		return message;
	}

	public NetworkProtocol getNetworkProtoco() {
		return NetworkProtocol.TCP;
	}

}
