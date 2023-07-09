package com.khopan.bromine.item.textlabel;

import java.awt.Color;
import java.awt.Font;

import com.khopan.bromine.Item;
import com.khopan.bromine.animation.interpolator.Interpolator;
import com.khopan.bromine.animation.transform.ColorTransform;
import com.khopan.bromine.area.Area;
import com.khopan.bromine.property.Property;
import com.khopan.bromine.property.SimpleProperty;
import com.khopan.bromine.theme.Theme;

public class TextLabel extends Item<TextLabel> {
	private final ColorTransform transform;

	private Font font;
	private Color color;

	public TextLabel() {
		this.transform = new ColorTransform();
		this.transform.duration().set(150);
		this.transform.value().set(this.theme.getColor(Theme.KEY_TEXT_COLOR));
		this.transform.interpolator().set(Interpolator.SINE_EASE_IN_OUT);
		this.transform.framerate().set(240);
		this.transform.ticker().set(color -> {
			this.color = color;
			this.update();
		});

		this.font = new Font(Font.SANS_SERIF, Font.PLAIN, 10);
	}

	public Property<Font, TextLabel> font() {
		return new SimpleProperty<Font, TextLabel>(() -> this.font, font -> this.font = font, font -> this.update(), this).nullable().whenNull(new Font(Font.SANS_SERIF, Font.PLAIN, 10));
	}

	@Override
	protected void onThemeUpdate(Theme theme) {
		this.transform.begin(theme.getColor(Theme.KEY_TEXT_COLOR));
	}

	@Override
	protected void render(Area area) {
		area.smooth();
		area.font(this.font);
		area.color(this.color);
		area.textCenter("Label:");
	}
}
