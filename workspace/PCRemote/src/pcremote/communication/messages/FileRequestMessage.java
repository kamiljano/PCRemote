package pcremote.communication.messages;

public class FileRequestMessage implements NetworkMessage {

	private String path;
	private byte [] message;
	
	public FileRequestMessage(String path){
		this.path = path;
		byte [] buff = path.getBytes();
		message = new byte[buff.length + 1];
		message[0] = 9;
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

	public String getPath() {
		return path;
	}
}
