package com.khopan.bromine.unit;

public class Size implements IMutableSize {
	public int width;
	public int height;

	public Size() {
		this.width = 0;
		this.height = 0;
	}

	public Size(int size) {
		this.width = size;
		this.height = size;
	}

	public Size(int width, int height) {
		this.width = width;
		this.height = height;
	}

	public Size(ISize size) {
		this.width = size == null ? 0 : size.getWidth();
		this.height = size == null ? 0 : size.getHeight();
	}

	@Override
	public int getWidth() {
		return this.width;
	}

	@Override
	public int getHeight() {
		return this.height;
	}

	@Override
	public ISize getSize() {
		return new Size(this.width, this.height);
	}

	@Override
	public IBounds getBounds(ILocation location) {
		if(location == null) {
			return new Bounds(0, 0, this.width, this.height);
		}

		return new Bounds(location, this.width, this.height);
	}

	@Override
	public void setWidth(int width) {
		this.width = width;
	}

	@Override
	public void setWidth(ISize size) {
		this.width = size == null ? 0 : size.getWidth();
	}

	@Override
	public void setHeight(int height) {
		this.height = height;
	}

	@Override
	public void setHeight(ISize size) {
		this.width = size == null ? 0 : size.getHeight();
	}

	@Override
	public void setSize(int size) {
		this.width = size;
		this.height = size;
	}

	@Override
	public void setSize(int width, int height) {
		this.width = width;
		this.height = height;
	}

	@Override
	public void setSize(ISize size) {
		this.width = size == null ? 0 : size.getWidth();
		this.height = size == null ? 0 : size.getHeight();
	}

	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append(this.getClass().getName());
		builder.append("[width=");
		builder.append(this.width);
		builder.append(",height=");
		builder.append(this.height);
		builder.append(']');
		return builder.toString();
	}

	public static Size getInstance() {
		return new Size();
	}

	public static Size of(int size) {
		return new Size(size);
	}

	public static Size of(int width, int height) {
		return new Size(width, height);
	}

	public static Size of(ISize size) {
		return new Size(size);
	}
}
