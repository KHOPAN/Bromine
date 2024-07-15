package com.khopan.bromine;

import java.lang.annotation.Native;

import com.khopan.bromine.render.Paint;
import com.khopan.bromine.unit.Size;

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

	public void center(Size size) {
		if(size == null) {
			this.x = -this.width / 2;
			this.y = -this.height / 2;
			return;
		}

		this.x = (int) Math.round((size.width - this.width) * 0.5d);
		this.y = (int) Math.round((size.height - this.height) * 0.5d);
	}

	@SuppressWarnings("unchecked")
	public T show() {
		return (T) this;
	}

	@SuppressWarnings("unchecked")
	public T hide() {
		return (T) this;
	}

	public void render(Paint paint) {

	}
}
