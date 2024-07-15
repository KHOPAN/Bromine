package test;

import java.awt.Dimension;
import java.awt.Font;

import com.khopan.bromine.Bromine;
import com.khopan.bromine.BromineApplication;
import com.khopan.bromine.item.button.Button;
import com.khopan.bromine.layout.CenterLayout;
import com.khopan.bromine.theme.HackerTheme;

public class Main extends BromineApplication {
	@Override
	protected void initialize() {
		this.window.layout().set(CenterLayout.INSTANCE);
		this.window.add(new Button()
				.naturalRoundness()
				.text().set("Press Me")
				.size().set(new Dimension(100, 25))
				.font().set(new Font("Itim", Font.BOLD, 10))
				);

		this.window.size().set(new Dimension(600, 400));
		this.window.center();
		this.window.theme().set(HackerTheme.THEME);
		this.window.visibility().enable();
	}

	public static void main(String[] args) {
		Bromine.initialize(new Main());
	}
}
