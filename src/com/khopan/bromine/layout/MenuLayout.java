package com.khopan.bromine.layout;

import java.awt.Rectangle;

import com.khopan.bromine.Item;
import com.khopan.bromine.RootItem;

public class MenuLayout extends Layout {
	public static final MenuLayout INSTANCE = new MenuLayout();

	private final int barSize;

	private MenuLayout() {
		this.barSize = 25;
	}

	@Override
	public int getMaxItem() {
		return 3;
	}

	@Override
	public void layoutItem(int index, int itemSize, Item<?> item, RootItem<?> parent) {
		if(itemSize == 1) {
			if(index == 0) {
				Rectangle bounds = item.bounds().get();
				bounds.x = 0;
				bounds.y = 0;
				bounds.setSize(parent.size().get());
				item.bounds().set(bounds);
			}
		} else if(itemSize == 2) {
			if(index == 0) {
				item.bounds().set(new Rectangle(0, 0, parent.width().get(), this.barSize));
			} else if(index == 1) {
				Rectangle bounds = item.bounds().get();
				bounds.x = 0;
				bounds.y = this.barSize;
				bounds.setSize(parent.size().get());
				bounds.height -= this.barSize;
				item.bounds().set(bounds);
			}
		} else if(itemSize == 3) {
			if(index == 0) {
				item.bounds().set(new Rectangle(0, 0, parent.width().get(), this.barSize));
			} else if(index == 1) {
				Rectangle bounds = item.bounds().get();
				bounds.x = 0;
				bounds.y = this.barSize;
				bounds.setSize(parent.size().get());
				bounds.height -= this.barSize * 2;
				item.bounds().set(bounds);
			} else if(index == 2) {
				Rectangle bounds = item.bounds().get();
				bounds.x = 0;
				bounds.setSize(parent.size().get());
				bounds.y = bounds.height - this.barSize;
				bounds.height = this.barSize;
				item.bounds().set(bounds);
			}
		}
	}
}
