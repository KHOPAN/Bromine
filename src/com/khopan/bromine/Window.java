package com.khopan.bromine;

import java.lang.annotation.Native;

public class Window extends RootItem<Window> {
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

	public Window setTitle(String title) {
		this.title = title;
		return this;
	}

	public Window setClassName(String className) {
		this.className = className;
		return this;
	}

	@Override
	public Window show() {
		this.showWindow();
		return this;
	}

	public Window build() {
		if(this.built) {
			throw new RuntimeException("The window was already built");
		}

		this.buildWindow(this.className);
		this.built = true;
		return this;
	}

	public Window loop() {
		this.messageLoop();
		return this;
	}

	private void renderWindow() {
		System.out.println("Render");
	}

	private native void showWindow();
	private native void buildWindow(String className);
	private native void messageLoop();
}
