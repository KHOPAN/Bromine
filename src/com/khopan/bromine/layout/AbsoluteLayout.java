package com.khopan.bromine.layout;

import com.khopan.bromine.Item;
import com.khopan.bromine.RootItem;

public class AbsoluteLayout extends Layout {
	public static final AbsoluteLayout INSTANCE = new AbsoluteLayout();

	private AbsoluteLayout() {

	}

	@Override
	public int getMaxItem() {
		return Layout.MAX_ITEM_INFINITY;
	}

	@Override
	public void layoutItem(int index, int itemSize, Item<?> item, RootItem<?> parent) {

	}
}
