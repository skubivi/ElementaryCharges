#include <SFML/Graphics.hpp>
#include <vector>
#include "Charge.h"

using namespace sf;

void draw(std::vector<Charge>&charges, RenderWindow &window) {
	for (int i = 0; i < charges.size(); i++){
		charges[i].draw(window);
	}
	window.display();
}

int main()
{
	RenderWindow window(VideoMode(1600, 900), "Elementary Charges");
	std::vector<Charge>charges;
	float chargeSize = 10.0f;
	

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left)
					charges.push_back(Charge(event.mouseButton.x - chargeSize, event.mouseButton.y - chargeSize, false, chargeSize));
				else
					charges.push_back(Charge(event.mouseButton.x - chargeSize, event.mouseButton.y - chargeSize, true, chargeSize));
			}
		}

		draw(charges, window);
	}

	return 0;
}