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
	double size;
	double m;
	double aX;
	double aY;
	double vX;
	double vY;
	const double k = 0.01f;
public:
	Charge(float x, float y, bool positive, double size, bool stat);
	float getX();
	float getY();
	double getSize();
	double getMass();
	bool isPositive();
	void draw(RenderWindow &window);
	void accelerate();
	void move();
	void force(Charge &other);
	void hit(Charge &other);
	void clearA();
};

