package com.khopan.bromine.unit;

public class Bounds {
	public int x;
	public int y;
	public int width;
	public int height;

	public Bounds() {
		this.x = 0;
		this.y = 0;
		this.width = 0;
		this.height = 0;
	}

	public Bounds(int x, int y, int size) {
		this.x = x;
		this.y = y;
		this.width = size;
		this.height = size;
	}

	public Bounds(Location location, int size) {
		this.x = location == null ? 0 : location.x;
		this.y = location == null ? 0 : location.y;
		this.width = size;
		this.height = size;
	}

	public Bounds(int x, int y, int width, int height) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}

	public Bounds(int x, int y, Size size) {
		this.x = x;
		this.y = y;
		this.width = size == null ? 0 : size.width;
		this.height = size == null ? 0 : size.height;
	}

	public Bounds(Location location, Size size) {
		this.x = location == null ? 0 : location.x;
		this.y = location == null ? 0 : location.y;
		this.width = size == null ? 0 : size.width;
		this.height = size == null ? 0 : size.height;
	}

	public Bounds(Location location, int width, int height) {
		this.x = location == null ? 0 : location.x;
		this.y = location == null ? 0 : location.y;
		this.width = width;
		this.height = height;
	}

	public Bounds(Bounds bounds) {
		this.x = bounds == null ? 0 : bounds.x;
		this.y = bounds == null ? 0 : bounds.y;
		this.width = bounds == null ? 0 : bounds.width;
		this.height = bounds == null ? 0 : bounds.height;
	}

	public Location newLocation() {
		return new Location(this.x, this.y);
	}

	public Size newSize() {
		return new Size(this.width, this.height);
	}

	public Bounds newBounds() {
		return new Bounds(this.x, this.y, this.width, this.height);
	}

	public Bounds newBounds(int size) {
		return new Bounds(this.x, this.y, size, size);
	}

	public Bounds newBounds(Location location) {
		return new Bounds(location, this.width, this.height);
	}

	public Bounds newBounds(Size size) {
		return new Bounds(this.x, this.y, size);
	}

	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append(this.getClass().getName());
		builder.append("[x=");
		builder.append(this.x);
		builder.append(",y=");
		builder.append(this.y);
		builder.append(",width=");
		builder.append(this.width);
		builder.append(",height=");
		builder.append(this.height);
		builder.append(']');
		return builder.toString();
	}
}
