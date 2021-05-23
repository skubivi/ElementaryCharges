#include <SFML/Graphics.hpp>
#include <vector>
#include "Charge.h"

using namespace sf;

void draw(std::vector<Charge>&charges, RenderWindow &window, CircleShape prototype, float size) {
	window.clear();
	prototype.setRadius(size);
	window.draw(prototype);

	for (int i = 0; i < charges.size(); i++){
		charges[i].draw(window);
	}
	window.display();
}

void calcAV(std::vector<Charge>& charges) {
	for (int i = 0; i < charges.size(); i++) {
		charges[i].clearA();
		for (int j = 0; j < charges.size(); j++) {
			if (i != j) {
				charges[i].force(charges[j]);
				charges[i].hit(charges[j]);
			}
		}
	}
}

int main()
{
	RenderWindow window(VideoMode(1600, 900), "Elementary Charges");
	window.setKeyRepeatEnabled(false);
	std::vector<Charge>charges;
	float chargeSize = 10.0f;
	bool stat = false;

	CircleShape prototype = CircleShape(chargeSize);
	prototype.setFillColor(Color(150, 150, 150));
	prototype.setPosition(1000.0f, 0.0f);
	

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left)
					charges.push_back(Charge(event.mouseButton.x, event.mouseButton.y, false, chargeSize, stat));
				else
					charges.push_back(Charge(event.mouseButton.x, event.mouseButton.y, true, chargeSize, stat));
			}
			else if (event.type == Event::MouseWheelScrolled) {
				chargeSize += 5 * event.mouseWheelScroll.delta;
			}
			else if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::BackSpace && charges.size() > 0)
					charges.pop_back();
				else if (event.key.code == Keyboard::C)
					charges.clear();
				else if (event.key.code == Keyboard::S)
					stat = !stat;
			}
		}

		calcAV(charges);
		for (int i = 0; i < charges.size(); i++) {
			charges[i].move();
		}

		draw(charges, window, prototype, chargeSize);
	}

	return 0;
}