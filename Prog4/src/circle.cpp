#include "circle.h"

Circle::Circle(double r, int a, int b) : Point(a, b)
{
	setRadius(r);
}

void Circle::setRadius(double r)
{
	radius = (r > 0 ? r : 0);
}

double Circle::getRadius() const
{
	return radius;
}

double Circle::area() const
{
	return 3.14159 * radius * radius;
}


// Centrul = [x, y] -  Raza = a.bc

ostream& operator<<(ostream& output, const Circle& c)
{
	output << "Centrul = " << static_cast<const Point&>(c) << " -  Raza = " << setiosflags(ios::fixed | ios::showpoint) << setprecision(2) << c.radius;

        return output;
}
