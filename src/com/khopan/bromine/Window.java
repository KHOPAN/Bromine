package com.khopan.bromine;

public class Window extends RootItem {
	private String title;
	private String className;
	private boolean built;

	public Window() {

	}

	public Window(String className) {
		this.setClassName(className);
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public void setClassName(String className) {
		this.className = className;
	}

	@Override
	public void show() {
		this.showWindow();
	}

	public void build() {
		if(this.built) {
			throw new RuntimeException("The window was already built");
		}

		this.buildWindow(this.className);
		this.built = true;
	}

	public void loop() {
		this.messageLoop();
	}

	private native void buildWindow(String className);
	private native void showWindow();
	private native void messageLoop();
}
