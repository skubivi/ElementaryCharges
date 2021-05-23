#include "Charge.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Charge::Charge(double x, double y, bool positive, float size) {
	this->x = x;
	this->y = y;
	this->positive = positive;
	this->size = size;
}
int Charge::getX() {
	return x;
}
int Charge::getY() {
	return y;
}
bool Charge::isPositive() {
	return positive;
}
void Charge::draw(RenderWindow &window) {
	circle.setPosition(x, y);
	circle.setRadius(size);
	if (isPositive()) {
		circle.setFillColor(Color(255, 0, 0));
	}
	else {
		circle.setFillColor(Color(0, 0, 255));
	}
	window.draw(circle);
}