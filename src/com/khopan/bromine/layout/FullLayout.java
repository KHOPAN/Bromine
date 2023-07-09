package com.khopan.bromine.layout;

import java.awt.Rectangle;

import com.khopan.bromine.Item;
import com.khopan.bromine.RootItem;

public class FullLayout extends Layout {
	public static final FullLayout INSTANCE = new FullLayout();

	private FullLayout() {

	}

	@Override
	public int getMaxItem() {
		return 1;
	}

	@Override
	public void layoutItem(int index, int itemSize, Item<?> item, RootItem<?> parent) {
		Rectangle bounds = item.bounds().get();
		bounds.x = 0;
		bounds.y = 0;
		bounds.setSize(parent.size().get());
		item.bounds().set(bounds);
	}
}
