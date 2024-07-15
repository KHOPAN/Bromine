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
