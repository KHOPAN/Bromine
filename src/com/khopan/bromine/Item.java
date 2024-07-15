package com.khopan.bromine;

import java.lang.annotation.Native;

public abstract class Item<T extends Item<T>> {
	@Native
	private int x;

	@Native
	private int y;

	@Native
	private int width;

	@Native
	private int height;

	public Item() {

	}

	public void setBounds(int x, int y, int width, int height) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}

	public void setLocation(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public void setSize(int width, int height) {
		this.width = width;
		this.height = height;
	}

	@SuppressWarnings("unchecked")
	public T show() {
		return (T) this;
	}

	@SuppressWarnings("unchecked")
	public T hide() {
		return (T) this;
	}
}
