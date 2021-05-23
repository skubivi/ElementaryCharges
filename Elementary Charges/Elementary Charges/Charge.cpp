#include "Charge.h"
#include <SFML/Graphics.hpp>
#include <math.h>

using namespace sf;

Charge::Charge(float x, float y, bool positive, float size, bool stat) {
	this->x = x;
	this->y = y;
	this->positive = positive;
	this->size = size;
	this->stat = stat;
	aX = 0.0f;
	aY = 0.0f;
	vX = 0.0f;
	vY = 0.0f;
}
float Charge::getX() {
	return x;
}
float Charge::getY() {
	return y;
}
float Charge::getSize() {
	return size;
}
bool Charge::isPositive() {
	return positive;
}
void Charge::draw(RenderWindow &window) {
	circle.setPosition(x - size, y - size);
	circle.setRadius(size);
	if (isPositive()) {
		circle.setFillColor(Color(255, 0, 0));
	}
	else {
		circle.setFillColor(Color(0, 0, 255));
	}
	window.draw(circle);
}
void Charge::accelerate() {
	vX += aX;
	vY += aY;
}
void Charge::move() {
	x += vX;
	y += vY;
	if (x - size <= 0 && vX < 0)
		vX = abs(vX);
	else if (x + size >= 1600 && vX > 0)
		vX = -abs(vX);
	if (y - size <= 0 && vY < 0)
		vY = abs(vY);
	else if (y + size >= 900 && vY > 0)
		vY = -abs(vY);
}
void Charge::force(Charge &other) {
	if (!stat) {
		int c;
		if (this->isPositive() && other.isPositive()) c = -1;
		else if (!this->isPositive() && !other.isPositive()) c = -1;
		else c = 1;
		float rX = other.getX() - x;
		float rY = other.getY() - y;
		float r = sqrt(rX * rX + rY * rY);
		float rXN = rX / r;
		float rYN = rY / r;
		float a = k * other.getSize() * other.getSize() / (r * r);
		aX += a * rXN * c;
		aY += a * rYN * c;
	}
}
void Charge::hit(Charge &other) {
	if (!stat) {
		float rX = other.getX() - x;
		float rY = other.getY() - y;
		float r = sqrt(rX * rX + rY * rY);
		if (r <= size + other.getSize()) {
			float v1 = sqrt(vX * vX + vY * vY);
			float v2 = sqrt(other.vX * other.vX + other.vY * other.vY);
			float m1 = size * size;
			float m2 = other.size * other.size;
			float v = (2 * m2 * v2 + abs(m1 - m2) * v1) / (m1 + m2);
			float rXN = -rX / r;
			float rYN = -rY / r;
			vX = rXN * v;
			vY = rYN * v;
		}
	}
}
void Charge::clearA() {
	aX = 0.0f;
	aY = 0.0f;
}