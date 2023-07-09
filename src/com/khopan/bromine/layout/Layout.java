package com.khopan.bromine.layout;

import com.khopan.bromine.Item;
import com.khopan.bromine.RootItem;

public abstract class Layout {
	public static final int MAX_ITEM_INFINITY = -1;

	public abstract int getMaxItem();
	public abstract void layoutItem(int index, int itemSize, Item<?> item, RootItem<?> parent);
}
