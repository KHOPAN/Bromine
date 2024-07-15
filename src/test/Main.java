package test;

import com.khopan.bromine.Toolkit;
import com.khopan.bromine.unit.Size;

public class Main {
	public static void main(String[] args) throws Throwable {
		System.load("D:\\GitHub Repository\\Bromine\\Bromine\\x64\\Debug\\Bromine.dll");
		/*Window window = new Window();
		window.setTitle("Bromine Test");
		window.setBounds(200, 200, 400, 400);
		window.build();
		window.show();
		window.loop();*/
		Size size = Toolkit.getScreenSize();
		System.out.println(size);
	}
}
