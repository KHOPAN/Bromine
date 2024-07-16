package com.khopan.bromine;

import com.khopan.bromine.render.Paint;
import com.khopan.bromine.unit.Bounds;
import com.khopan.bromine.unit.IBounds;
import com.khopan.bromine.unit.ILocation;
import com.khopan.bromine.unit.IMutableBounds;
import com.khopan.bromine.unit.ISize;

public class Item implements IMutableBounds {
	protected final Bounds bounds;

	public Item() {
		this.bounds = new Bounds();
	}

	@Override
	public IBounds getBounds() {
		return this.bounds.getBounds();
	}

	@Override
	public int getX() {
		return this.bounds.x;
	}

	@Override
	public int getY() {
		return this.bounds.y;
	}

	@Override
	public ILocation getLocation() {
		return this.bounds.getLocation();
	}

	@Override
	public ILocation getLocation(int offsetX, int offsetY) {
		return this.bounds.getLocation(offsetX, offsetY);
	}

	@Override
	public ILocation getLocation(ILocation offset) {
		return this.bounds.getLocation(offset);
	}

	@Override
	public IBounds getBounds(int size) {
		return this.bounds.getBounds(size);
	}

	@Override
	public IBounds getBounds(ISize size) {
		return this.bounds.getBounds(size);
	}

	@Override
	public int getWidth() {
		return this.bounds.width;
	}

	@Override
	public int getHeight() {
		return this.bounds.height;
	}

	@Override
	public ISize getSize() {
		return this.bounds.getSize();
	}

	@Override
	public IBounds getBounds(ILocation location) {
		return this.bounds.getBounds(location);
	}

	@Override
	public void setX(int x) {
		this.bounds.x = x;
	}

	@Override
	public void setX(ILocation location) {
		this.bounds.setX(location);
	}

	@Override
	public void setY(int y) {
		this.bounds.y = y;
	}

	@Override
	public void setY(ILocation location) {
		this.bounds.setY(location);
	}

	@Override
	public void setLocation(int x, int y) {
		this.bounds.x = x;
		this.bounds.y = y;
	}

	@Override
	public void setLocation(ILocation location) {
		this.bounds.setLocation(location);
	}

	@Override
	public void setWidth(int width) {
		this.bounds.width = width;
	}

	@Override
	public void setWidth(ISize size) {
		this.bounds.setWidth(size);
	}

	@Override
	public void setHeight(int height) {
		this.bounds.height = height;
	}

	@Override
	public void setHeight(ISize size) {
		this.bounds.setHeight(size);
	}

	@Override
	public void setSize(int size) {
		this.bounds.width = size;
		this.bounds.height = size;
	}

	@Override
	public void setSize(int width, int height) {
		this.bounds.width = width;
		this.bounds.height = height;
	}

	@Override
	public void setSize(ISize size) {
		this.bounds.setSize(size);
	}

	@Override
	public void setBounds(int x, int y, int size) {
		this.bounds.x = x;
		this.bounds.y = y;
		this.bounds.width = size;
		this.bounds.height = size;
	}

	@Override
	public void setBounds(int x, int y, int width, int height) {
		this.bounds.x = x;
		this.bounds.y = y;
		this.bounds.width = width;
		this.bounds.height = height;
	}

	@Override
	public void setBounds(int x, int y, ISize size) {
		this.bounds.setBounds(x, y, size);
	}

	@Override
	public void setBounds(ILocation location, int size) {
		this.bounds.setBounds(location, size);
	}

	@Override
	public void setBounds(ILocation location, int width, int height) {
		this.bounds.setBounds(location, width, height);
	}

	@Override
	public void setBounds(ILocation location, ISize size) {
		this.bounds.setBounds(location, size);
	}

	@Override
	public <T extends ILocation & ISize> void setBounds(T bounds) {
		this.bounds.setBounds(bounds);
	}

	@Override
	public void centerX(int width) {
		this.bounds.centerX(width);
	}

	@Override
	public void centerX(ISize size) {
		this.bounds.centerX(size);
	}

	@Override
	public void centerY(int height) {
		this.bounds.centerY(height);
	}

	@Override
	public void centerY(ISize size) {
		this.bounds.centerY(size);
	}

	@Override
	public void centerLocation(int size) {
		this.bounds.centerLocation(size);
	}

	@Override
	public void centerLocation(int width, int height) {
		this.bounds.centerLocation(width, height);
	}

	@Override
	public void centerLocation(ISize size) {
		this.bounds.centerLocation(size);
	}

	public void show() {

	}

	public void hide() {

	}

	public void render(Paint paint) {

	}
}
