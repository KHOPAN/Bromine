package com.khopan.bromine;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.image.BufferedImage;

public class Bromine {
	private Bromine() {}

	public static BufferedImage getLogo(int size) {
		return Bromine.getLogo(size, 0x000000);
	}

	public static BufferedImage getLogo(int size, int color) {
		BufferedImage image = new BufferedImage(size, size, BufferedImage.TYPE_INT_ARGB);
		Graphics2D Graphics = image.createGraphics();
		Graphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		Graphics.setColor(new Color(color));
		Graphics.fill(new BromineLogo(size));
		Graphics.dispose();
		return image;
	}
}
