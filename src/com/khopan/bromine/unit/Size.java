package com.khopan.bromine.unit;

public class Size {
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

	public Size(Size size) {
		this.width = size == null ? 0 : size.width;
		this.height = size == null ? 0 : size.height;
	}

	public Size(Bounds bounds) {
		this.width = bounds == null ? 0 : bounds.width;
		this.height = bounds == null ? 0 : bounds.height;
	}

	public Size newSize() {
		return new Size(this.width, this.height);
	}

	public Bounds newBounds() {
		return new Bounds(0, 0, this.width, this.height);
	}

	public Bounds newBounds(int x, int y) {
		return new Bounds(x, y, this.width, this.height);
	}

	public Bounds newBounds(Location location) {
		return new Bounds(location, this.width, this.height);
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
}
