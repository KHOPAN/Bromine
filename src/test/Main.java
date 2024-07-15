package test;

import com.khopan.bromine.Window;

public class Main {
	public static void main(String[] args) throws Throwable {
		System.load("D:\\GitHub Repository\\Bromine\\Bromine\\x64\\Debug\\Bromine.dll");
		Window window = new Window();
		window.setTitle("Bromine Test");
		window.setBounds(200, 200, 400, 400);
		window.build();
		window.show();
		window.loop();
	}
}
