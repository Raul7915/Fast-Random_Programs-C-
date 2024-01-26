#ifndef POINT_H
#define POINT_H
#include <iostream>
using std::ostream;
class Point
{
	friend ostream& operator<<(ostream&, const Point&);

public:
	Point(int = 0, int = 0);
	void setPoint(int, int);
	int getX() const
	{
		return x;
	}
	int getY() const
	{
		return y;
	}
	virtual double area() const = 0;

protected:
	int x, y;
};
#endif
