import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.LinkedList;
import java.util.List;


public class Main {
	
	public static void main(String [] args) throws Exception {
		
		String s="1234/5678";
		System.out.println(s.substring(s.lastIndexOf('/')+1));
		
		/*Socket s = new Socket("localhost", 1234);
		String path = "/";
		byte [] buff = path.getBytes();
		byte [] message = new byte [buff.length + 1];
		message[0] = 8;
		for (int i = 0; i < buff.length; i++) {
			message[i+1] = buff[i];
		}
		s.getOutputStream().write(message);
		
		InputStreamReader isr = new InputStreamReader(s.getInputStream());
		BufferedReader br = new BufferedReader(isr);
		String answer = br.readLine();
		
		List<RemoteFile> l = extractFiles(answer);
		
		System.out.println(new String(answer));*/
		
	}
	
	private static LinkedList<RemoteFile> extractFiles(String message) {
		LinkedList<RemoteFile> result = new LinkedList<RemoteFile>();
		
		int pos = 0;
		while (pos < message.length()) {
			boolean isDir = message.charAt(pos) == 'd';
			int len = Integer.parseInt(message.substring(pos + 1, pos + 5));
			String path = message.substring(pos + 5, pos + 5 + len);
			result.add(new RemoteFile(isDir, path));
			pos += 5 + len;
		}
		
		return result;
	}
}
