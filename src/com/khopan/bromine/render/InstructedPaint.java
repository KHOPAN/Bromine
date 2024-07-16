package com.khopan.bromine.render;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class InstructedPaint implements Paint {
	private final Consumer<PaintInstruction[]> dispatcher;
	private final List<PaintInstruction> list;

	private int color;

	public InstructedPaint(Consumer<PaintInstruction[]> dispatcher) {
		if(dispatcher == null) {
			throw new NullPointerException("Dispatcher cannot be null");
		}

		this.dispatcher = dispatcher;
		this.list = new ArrayList<>();
	}

	@Override
	public int getColor() {
		return this.color;
	}

	@Override
	public void setColor(int color) {
		this.color = color;
	}

	@Override
	public void fillRect(int x, int y, int width, int height) {
		this.list.add(new PaintInstruction(PaintInstruction.COMMAND_RECTANGLE_FILL, this.color, x, y, width, height));
	}

	public void dispatch() {
		if(this.list.isEmpty()) {
			return;
		}

		PaintInstruction[] array = this.list.toArray(new PaintInstruction[0]);

		if(array != null && array.length > 0) {
			this.dispatcher.accept(array);
		}
	}
}
