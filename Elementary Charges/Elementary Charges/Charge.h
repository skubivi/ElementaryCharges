#include <SFML/Graphics.hpp>

using namespace sf;

class Charge
{
private:
	double x;
	double y;
	bool positive;
	CircleShape circle;
	float size;
public:
	Charge(double x, double y, bool positive, float size);
	int getX();
	int getY();
	bool isPositive();
	void draw(RenderWindow &window);
};

