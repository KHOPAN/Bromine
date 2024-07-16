package com.khopan.bromine.render;

public class PaintInstruction {
	static final int COMMAND_RECTANGLE_FILL = 1;

	int command;
	int color;
	int x;
	int y;
	int width;
	int height;

	PaintInstruction(int command, int color, int x, int y, int width, int height) {
		this.command = command;
		this.color = color;
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}
}
