package com.khopan.bromine.unit;

public interface IMutableLocation extends ILocation {
	public void setX(int x);
	public void setX(ILocation location);
	public void setY(int y);
	public void setY(ILocation location);
	public void setLocation(int x, int y);
	public void setLocation(ILocation location);
}
