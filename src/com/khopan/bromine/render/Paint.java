package com.khopan.bromine.render;

import com.khopan.bromine.unit.IBounds;
import com.khopan.bromine.unit.ILocation;
import com.khopan.bromine.unit.ISize;

public interface Paint {
	int getColor();
	void setColor(int color);
	void fillRect(int x, int y, int width, int height);

	default void fillRect(int x, int y, ISize size) {
		this.fillRect(x, y, size == null ? 0 : size.getWidth(), size == null ? 0 : size.getHeight());
	}

	default void fillRect(ILocation location, int width, int height) {
		this.fillRect(location == null ? 0 : location.getX(), location == null ? 0 : location.getY(), width, height);
	}

	default void fillRect(ILocation location, ISize size) {
		this.fillRect(location == null ? 0 : location.getX(), location == null ? 0 : location.getY(), size == null ? 0 : size.getWidth(), size == null ? 0 : size.getHeight());
	}

	default void fillRect(IBounds bounds) {
		this.fillRect(bounds == null ? 0 : bounds.getX(), bounds == null ? 0 : bounds.getY(), bounds == null ? 0 : bounds.getWidth(), bounds == null ? 0 : bounds.getHeight());
	}
}
