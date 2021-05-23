#include <SFML/Graphics.hpp>

using namespace sf;

class Charge
{
private:
	float x;
	float y;
	bool positive;
	bool stat;
	CircleShape circle;
	float size;
	float aX;
	float aY;
	float vX;
	float vY;
	const float k = 0.05f;
public:
	Charge(float x, float y, bool positive, float size, bool stat);
	float getX();
	float getY();
	float getSize();
	bool isPositive();
	void draw(RenderWindow &window);
	void move();
	void force(Charge &other);
	void hit(Charge &other);
	void clearA();
};

