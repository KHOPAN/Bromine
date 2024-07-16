package com.khopan.bromine.unit;

public interface IMutableBounds extends IBounds, IMutableLocation, IMutableSize {
	public void setBounds(int x, int y, int size);
	public void setBounds(int x, int y, int width, int height);
	public void setBounds(int x, int y, ISize size);
	public void setBounds(ILocation location, int size);
	public void setBounds(ILocation location, int width, int height);
	public void setBounds(ILocation location, ISize size);
	public <T extends ILocation & ISize> void setBounds(T bounds);
	public void centerX(int width);
	public void centerX(ISize size);
	public void centerY(int height);
	public void centerY(ISize size);
	public void centerLocation(int size);
	public void centerLocation(int width, int height);
	public void centerLocation(ISize size);
}
