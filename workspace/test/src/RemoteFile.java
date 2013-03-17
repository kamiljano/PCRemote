
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

}
