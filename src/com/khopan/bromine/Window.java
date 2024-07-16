package com.khopan.bromine;

import java.lang.annotation.Native;

public class Window extends RootItem {
	@Native
	private final long handle;

	private String title;
	private String className;
	private boolean built;

	public Window() {
		this.handle = 0L;
	}

	public Window(String className) {
		this();
		this.setClassName(className);
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public void setClassName(String className) {
		this.className = className;
	}

	public void center() {
		super.centerLocation(Toolkit.getScreenSize());
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

	private void renderWindow() {
		System.out.println("Render");
	}

	private native void showWindow();
	private native void buildWindow(String className);
	private native void messageLoop();
}
