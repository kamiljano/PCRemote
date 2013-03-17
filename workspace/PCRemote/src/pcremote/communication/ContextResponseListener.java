package pcremote.communication;

import android.content.Context;
import android.os.Handler;

public interface ContextResponseListener extends ResponseListener{

	Handler getMessageHandler();
	Context getMessageContext();
}
