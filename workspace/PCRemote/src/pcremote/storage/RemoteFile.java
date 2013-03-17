package pcremote.storage;

public class RemoteFile {
	
	private boolean directory;
	private String path;
	
	public RemoteFile(boolean isDir, String path) {
		this.path = path;
		this.directory = isDir;
	}
	
	public boolean isDirectory() {
		return directory;
	}
	public String getPath() {
		return path;
	}

	public String getName() {
		String result;
		if (path.indexOf('/') == path.lastIndexOf('/')) {
			result = path;
		} else {
			result = path.substring(path.lastIndexOf('/'));
		}
		return result;
	}
}
