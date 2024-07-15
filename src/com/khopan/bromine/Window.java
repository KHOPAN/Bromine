package com.khopan.bromine;

public class Window extends RootItem {
	private String title;
	private String className;

	public Window() {

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
		this.buildWindow(this.className);
	}

	public void loop() {
		this.startMessageLoop();
	}

	private native void buildWindow(String className);
	private native void showWindow();
	private native void startMessageLoop();
}
