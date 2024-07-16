package com.khopan.bromine;

import java.lang.annotation.Native;

import com.khopan.bromine.render.InstructedPaint;

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

	@Override
	public native void show();
	public native void loop();

	public void center() {
		super.centerLocation(Toolkit.getScreenSize());
	}

	public void build() {
		if(this.built) {
			throw new RuntimeException("The window was already built");
		}

		this.buildWindow(this.className, this.bounds.x, this.bounds.y, this.bounds.width, this.bounds.height);
		this.built = true;
	}

	private native void buildWindow(String className, int x, int y, int width, int height);

	private void renderWindow() {
		System.out.println("Render");
		InstructedPaint paint = new InstructedPaint(list -> {});
		paint.fillRect(0, 0, 100, 200);
		paint.dispatch();
	}
}
