package test;

import com.khopan.bromine.Toolkit;
import com.khopan.bromine.Window;

public class Main {
	public static void main(String[] args) throws Throwable {
		System.load("D:\\GitHub Repository\\Bromine\\Bromine\\x64\\Release\\Bromine.dll");
		Window window = new Window();
		window.setTitle("Bromine Test");
		window.setSize(600, 400);
		window.center(Toolkit.getScreenSize());
		window.build();
		window.show();
		window.loop();
	}
}
