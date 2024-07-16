package com.khopan.bromine.unit;

public class Location implements ILocation {
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

	public Location(ILocation location) {
		this.x = location == null ? 0 : location.getX();
		this.y = location == null ? 0 : location.getY();
	}

	@Override
	public int getX() {
		return this.x;
	}

	@Override
	public int getY() {
		return this.y;
	}

	@Override
	public ILocation getLocation() {
		return new Location(this.x, this.y);
	}

	@Override
	public ILocation getLocation(int offsetX, int offsetY) {
		return new Location(this.x + offsetX, this.y + offsetY);
	}

	@Override
	public ILocation getLocation(ILocation offset) {
		if(offset == null) {
			return new Location(this.x, this.y);
		}

		return new Location(this.x + offset.getX(), this.y + offset.getY());
	}

	@Override
	public IBounds getBounds(int size) {
		return new Bounds(this.x, this.y, size);
	}

	@Override
	public IBounds getBounds(ISize size) {
		if(size == null) {
			return new Bounds(this.x, this.y, 0);
		}

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

	public static Location getInstance() {
		return new Location();
	}

	public static Location of(int x, int y) {
		return new Location(x, y);
	}

	public static Location of(ILocation location) {
		return new Location(location);
	}
}
