package com.khopan.bromine.unit;

public interface ILocation {
	public int getX();
	public int getY();
	public ILocation getLocation();
	public ILocation getLocation(int offsetX, int offsetY);
	public ILocation getLocation(ILocation offset);
	public IBounds getBounds(int size);
	public IBounds getBounds(ISize size);
}
