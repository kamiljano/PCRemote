package pcremote.activities;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.LinkedList;
import java.util.List;

import pcremote.communication.ContextResponseListener;
import pcremote.communication.ResponseType;
import pcremote.communication.messages.DirectoryRequestMessage;
import pcremote.communication.messages.FileRequestMessage;
import pcremote.storage.RemoteFile;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

public class RemoteFileBrowserActivity extends ControllerActivity implements ContextResponseListener{

	private TextView pathLabel;
	private LinearLayout fileZone;
	
	private ProgressDialog progress;
	private ProgressDialog progressFile;
	private String fileToDownload;
	
	private static final String startingPath = "/";
	
	private List<RemoteFile> files;
	
	@Override
	public void onCreate(Bundle bundle) {
		super.onCreate(bundle);
		setContentView(R.layout.remote_file_browser_activity);
		pathLabel = (TextView) findViewById(R.id.pathLabel);
		fileZone = (LinearLayout) findViewById(R.id.fileZone);
		pathLabel.setText(startingPath);
		progress = new ProgressDialog(this);
		progress.setMessage(getString(R.string.downloadingDirectories));
		progress.setCancelable(false);
		progressFile = new ProgressDialog(this);
		progressFile.setCancelable(false);
		progressFile.setButton(getString(R.string.cancel), new CancelFileDownloadListener());
		progressFile.setProgress(50);
		
		progress.show();
		communicator.send(new DirectoryRequestMessage(startingPath));
	}
	
	private void refreshFileZone() {
		fileZone.removeAllViews();
		DirClickListener dirListener = new DirClickListener();
		FileClickListener fileListener = new FileClickListener();
		boolean even = false;
		for (RemoteFile f : files) {
			TextView t = new TextView(this);
			t.setHeight(50);
			t.setHint(f.getPath());
			t.setText(f.getName());
			if (even) {
				even = false;
				t.setBackgroundColor(Color.rgb(173, 173, 173));
			} else {
				even = true;
				t.setBackgroundColor(Color.rgb(112, 112, 112));
			}
			
			if (f.isDirectory())
				t.setOnClickListener(dirListener);
			else
				t.setOnClickListener(fileListener);
			fileZone.addView(t);
		}
	}
	
	private class DirClickListener implements View.OnClickListener {

		public void onClick(View v) {
			TextView tv = (TextView)v;
			pathLabel.setText(tv.getHint());
			progress.show();
			communicator.send(new DirectoryRequestMessage(tv.getHint().toString()));
		}
	}
	
	private class FileClickListener implements View.OnClickListener {

		public void onClick(View v) {
			String path = ((TextView)v).getHint().toString();
			fileToDownload = path.substring(path.lastIndexOf('/') + 1);
			progressFile.setMessage(getString(R.string.downloadingFile) + fileToDownload);
			progressFile.show();
			communicator.send(new FileRequestMessage(path));
		}
	}
	
	private class CancelFileDownloadListener implements DialogInterface.OnClickListener{
		public void onClick(DialogInterface dialog, int which) {
			progressFile.hide();
			
		}
	}

	public ResponseType[] getAwaitedResponseTypes() {
		return new ResponseType[]{ResponseType.DirectoryResponse, ResponseType.FileResponse};
	}
	
	private boolean isPicture(String filename) {
		filename = filename.toLowerCase();
		if (filename.endsWith(".jpg") || filename.endsWith(".png") || filename.endsWith(".bmp") || filename.endsWith(".gif")) {
			return true;
		}
		return false;
	}
	
	private boolean isAudio(String filename) {
		filename = filename.toLowerCase();
		if (filename.endsWith(".mp3") || filename.endsWith(".wav") || filename.endsWith(".ogg") || filename.endsWith(".flac")) {
			return true;
		}
		return false;
	}
	
	private boolean isVideo(String filename){
		filename = filename.toLowerCase();
		if (filename.endsWith(".avi") ||filename.endsWith(".mov") || filename.endsWith(".rm") || filename.endsWith(".rmvb") || filename.endsWith(".3gp")) {
			return true;
		}
		return false;
	}

	public void processResponse(final ResponseType responseType, byte[] buffer) {
		if (responseType.equals(ResponseType.DirectoryResponse)) {
			files = extractFiles(new String(buffer));
			refreshFileZone();
			progress.dismiss();
		} else {
			String state = Environment.getExternalStorageState();
			if (Environment.MEDIA_MOUNTED.equals(state)) {
				File path;
				if (isPicture(fileToDownload)) {
					path = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
				} else if (isAudio(fileToDownload)) {
					path = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_MUSIC);
				} else if (isVideo(fileToDownload)) {
					path = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_MOVIES);
				} else {
					path = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS);
				}
				File file = new File(path, fileToDownload);
				path.mkdirs();
				OutputStream os = null;
				try {
					os = new FileOutputStream(file);
					os.write(buffer);
				} catch (Exception e) {
					e.printStackTrace();
					Toast.makeText(this, getString(R.string.fileSaveFail), Toast.LENGTH_SHORT).show();
				} finally {
					if (os != null) {
						try {
							os.close();
						} catch (IOException e) {
							e.printStackTrace();
						}
					}
				}
			}
			progressFile.dismiss();
			Toast.makeText(this, getString(R.string.downloadComplete), Toast.LENGTH_SHORT).show();
		}
	}
	
	private LinkedList<RemoteFile> extractFiles(String message) {
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
