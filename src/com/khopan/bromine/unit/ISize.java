package com.khopan.bromine.unit;

public interface ISize {
	public int getWidth();
	public int getHeight();
	public ISize getSize();
	public IBounds getBounds(ILocation location);
}
