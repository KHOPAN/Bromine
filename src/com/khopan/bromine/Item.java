package com.khopan.bromine;

public abstract class Item<T extends Item<T>> {
	public Item() {

	}

	@SuppressWarnings("unchecked")
	public T show() {
		return (T) this;
	}

	@SuppressWarnings("unchecked")
	public T hide() {
		return (T) this;
	}
}
