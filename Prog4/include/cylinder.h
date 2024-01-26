#ifndef CYLINDER_H
#define CYLINDER_H
#include <iostream>
using std::ostream;
#include "circle.h"

class Cylinder : public Circle
{
	friend ostream& operator<<(ostream&, const Cylinder&);

    public:
        Cylinder(double h = 0.0, double r = 0.0, int x = 0, int y = 0);
        void setHeight(double);

        double getHeight() const;
        virtual double area() const;
        double volume() const;

    protected:
        double height;
};
   #endif
