package pcremote.communication;

public enum ResponseType {
	
	Unspecified(-1),
	DirectoryResponse(1),
	FileResponse(2),
	IntroductionResponse(3);
	
	private int code;
	private ResponseType(int code) {
		this.code = code;
	}
	
	public int getCode () {
		return code;
	}
	
	public static ResponseType getResponseTypeByCode(int code){
		switch(code) {
		case 1:
			return DirectoryResponse;
		case 2:
			return FileResponse;
		case 3:
			return IntroductionResponse;
		}
		return Unspecified;
	}
}