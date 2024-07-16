package com.khopan.bromine.unit;

public class Bounds implements IBounds {
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

	public Bounds(ILocation location, int size) {
		this.x = location == null ? 0 : location.getX();
		this.y = location == null ? 0 : location.getY();
		this.width = size;
		this.height = size;
	}

	public Bounds(int x, int y, int width, int height) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}

	public Bounds(int x, int y, ISize size) {
		this.x = x;
		this.y = y;
		this.width = size == null ? 0 : size.getWidth();
		this.height = size == null ? 0 : size.getHeight();
	}

	public Bounds(ILocation location, ISize size) {
		this.x = location == null ? 0 : location.getX();
		this.y = location == null ? 0 : location.getY();
		this.width = size == null ? 0 : size.getWidth();
		this.height = size == null ? 0 : size.getHeight();
	}

	public Bounds(ILocation location, int width, int height) {
		this.x = location == null ? 0 : location.getX();
		this.y = location == null ? 0 : location.getY();
		this.width = width;
		this.height = height;
	}

	public Bounds(IBounds bounds) {
		this(bounds, bounds);
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
	public IBounds getBounds() {
		return new Bounds(this.x, this.y, this.width, this.height);
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
