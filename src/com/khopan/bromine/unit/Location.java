package com.khopan.bromine.unit;

public class Location {
	public int x;
	public int y;

	public Location() {
		this.x = 0;
		this.y = 0;
	}

	public Location(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public Location(Location location) {
		this.x = location == null ? 0 : location.x;
		this.y = location == null ? 0 : location.y;
	}

	public Location(Bounds bounds) {
		this.x = bounds == null ? 0 : bounds.x;
		this.y = bounds == null ? 0 : bounds.y;
	}

	public Location newLocation() {
		return new Location(this.x, this.y);
	}

	public Bounds newBounds() {
		return new Bounds(this.x, this.y, 0, 0);
	}

	public Bounds newBounds(int width, int height) {
		return new Bounds(this.x, this.y, width, height);
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
		builder.append(']');
		return builder.toString();
	}
}
