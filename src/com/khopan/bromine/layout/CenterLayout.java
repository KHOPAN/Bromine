package com.khopan.bromine.layout;

import java.awt.Rectangle;

import com.khopan.bromine.Item;
import com.khopan.bromine.RootItem;

public class CenterLayout extends Layout {
	public static final CenterLayout INSTANCE = new CenterLayout();

	private CenterLayout() {

	}

	@Override
	public int getMaxItem() {
		return 1;
	}

	@Override
	public void layoutItem(int index, int itemSize, Item<?> item, RootItem<?> parent) {
		Rectangle bounds = item.bounds().get();
		Rectangle parentBounds = parent.bounds().get();
		bounds.x = (int) Math.round((((double) parentBounds.width) - ((double) bounds.width)) * 0.5d);
		bounds.y = (int) Math.round((((double) parentBounds.height) - ((double) bounds.height)) * 0.5d);
		item.bounds().set(bounds);
	}
}
