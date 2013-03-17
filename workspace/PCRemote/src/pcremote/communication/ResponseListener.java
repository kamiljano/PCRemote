package pcremote.communication;


public interface ResponseListener {
	
	ResponseType [] getAwaitedResponseTypes();
	void processResponse(final ResponseType responseType, byte[] buffer);
}
