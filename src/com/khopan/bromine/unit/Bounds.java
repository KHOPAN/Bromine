package com.khopan.bromine.unit;

public class Bounds implements IMutableBounds {
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
	public IBounds getBounds() {
		return new Bounds(this.x, this.y, this.width, this.height);
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
	public void setX(int x) {
		this.x = x;
	}

	@Override
	public void setX(ILocation location) {
		this.x = location == null ? 0 : location.getX();
	}

	@Override
	public void setY(int y) {
		this.y = y;
	}

	@Override
	public void setY(ILocation location) {
		this.y = location == null ? 0 : location.getY();
	}

	@Override
	public void setLocation(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public void setLocation(ILocation location) {
		this.x = location == null ? 0 : location.getX();
		this.y = location == null ? 0 : location.getY();
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
		this.height = size == null ? 0 : size.getHeight();
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
	public void setBounds(int x, int y, int size) {
		this.x = x;
		this.y = y;
		this.width = size;
		this.height = size;
	}

	@Override
	public void setBounds(int x, int y, int width, int height) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}

	@Override
	public void setBounds(int x, int y, ISize size) {
		this.x = x;
		this.y = y;
		this.width = size == null ? 0 : size.getWidth();
		this.height = size == null ? 0 : size.getHeight();
	}

	@Override
	public void setBounds(ILocation location, int size) {
		this.x = location == null ? 0 : location.getX();
		this.y = location == null ? 0 : location.getY();
		this.width = size;
		this.height = size;
	}

	@Override
	public void setBounds(ILocation location, int width, int height) {
		this.x = location == null ? 0 : location.getX();
		this.y = location == null ? 0 : location.getY();
		this.width = width;
		this.height = height;
	}

	@Override
	public void setBounds(ILocation location, ISize size) {
		this.x = location == null ? 0 : location.getX();
		this.y = location == null ? 0 : location.getY();
		this.width = size == null ? 0 : size.getWidth();
		this.height = size == null ? 0 : size.getHeight();
	}

	@Override
	public <T extends ILocation & ISize> void setBounds(T bounds) {
		this.x = bounds == null ? 0 : bounds.getX();
		this.y = bounds == null ? 0 : bounds.getY();
		this.width = bounds == null ? 0 : bounds.getWidth();
		this.height = bounds == null ? 0 : bounds.getHeight();
	}

	@Override
	public void centerX(int width) {
		this.x = (int) Math.round((((double) width) - ((double) this.width)) * 0.5d);
	}

	@Override
	public void centerX(ISize size) {
		this.x = size == null ? 0 : (int) Math.round((((double) size.getWidth()) - ((double) this.width)) * 0.5d);
	}

	@Override
	public void centerY(int height) {
		this.y = (int) Math.round((((double) height) - ((double) this.height)) * 0.5d);
	}

	@Override
	public void centerY(ISize size) {
		this.y = size == null ? 0 : (int) Math.round((((double) size.getHeight()) - ((double) this.height)) * 0.5d);
	}

	@Override
	public void centerLocation(int size) {
		this.x = (int) Math.round((((double) size) - ((double) this.width)) * 0.5d);
		this.y = (int) Math.round((((double) size) - ((double) this.height)) * 0.5d);
	}

	@Override
	public void centerLocation(int width, int height) {
		this.x = (int) Math.round((((double) width) - ((double) this.width)) * 0.5d);
		this.y = (int) Math.round((((double) height) - ((double) this.height)) * 0.5d);
	}

	@Override
	public void centerLocation(ISize size) {
		this.x = size == null ? 0 : (int) Math.round((((double) size.getWidth()) - ((double) this.width)) * 0.5d);
		this.y = size == null ? 0 : (int) Math.round((((double) size.getHeight()) - ((double) this.height)) * 0.5d);
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

	public static Bounds getInstance() {
		return new Bounds();
	}

	public static Bounds of(int x, int y, int size) {
		return new Bounds(x, y, size);
	}

	public static Bounds of(ILocation location, int size) {
		return new Bounds(location, size);
	}

	public static Bounds of(int x, int y, int width, int height) {
		return new Bounds(x, y, width, height);
	}

	public static Bounds of(int x, int y, ISize size) {
		return new Bounds(x, y, size);
	}

	public static Bounds of(ILocation location, ISize size) {
		return new Bounds(location, size);
	}

	public static Bounds of(ILocation location, int width, int height) {
		return new Bounds(location, width, height);
	}

	public static Bounds of(IBounds bounds) {
		return new Bounds(bounds, bounds);
	}
}
