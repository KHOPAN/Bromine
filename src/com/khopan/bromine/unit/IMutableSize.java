package com.khopan.bromine.unit;

public interface IMutableSize extends ISize {
	public void setWidth(int width);
	public void setWidth(ISize size);
	public void setHeight(int height);
	public void setHeight(ISize size);
	public void setSize(int size);
	public void setSize(int width, int height);
	public void setSize(ISize size);
}
