#include <iostream>
using std::cout;
using std::endl;
#include "circle.h"
#include "cylinder.h"
#include "point.h"
int main()
{
	Cylinder cyl(5.7, 2.5, 12, 23);
	cout << "Coordonata X :  " << cyl.getX() << "\nCoordonata Y :  " << cyl.getY() << "\n        Raza :  " << cyl.getRadius() << "\n   Inaltimea :  " << cyl.getHeight() << "\n\n";
	cyl.setHeight(10);
	cyl.setRadius(4.25);
	cyl.setPoint(2, 2);

	cout << "Noua pozitie, raza si inaltimea lui cyl sunt:\n" << cyl << '\n';
	cout << "Aria lui cyl este: " << cyl.area() << '\n';
	Point& pRef = cyl;
	cout << "\nCilindrul tiparit ca un Point este: " << pRef << "\n\n";
	Circle& circleRef = cyl;
	cout << "Cilindrul tiparit ca un Circle este:\n" << circleRef << "\nAria: " << circleRef.area() << endl;


	cout << "Functii apelate prin pointer la Circle:" << endl;
	Circle* circlePtr = new Circle(10, 20, 30);
	cout << circlePtr->area() << endl;

	cout << "\n**** Functii apelate prin pointer la Circle initializat prin pointer la Cylinder ****" << endl;
	Cylinder* cylinderPtr = new Cylinder(5.7, 2.5, 12, 23);
	circlePtr = cylinderPtr;


	cout << "\nComportament polimorfic: ";
	cout << circlePtr->area() << endl;

	cout << "Functii apelate prin obiect de tip Circle:" << endl;
	Circle circle(10, 20, 30);
	cout << circle.area() << endl;

	cout << "Functii apelate prin obiect de tip Cylinder:" << endl;
	Cylinder cylinder(5.7, 2.5, 12, 23);
	cout << cylinder.area() << endl;

	cout << "Functie nevirtuala apelata prin pointer la Circle:" << endl;
	circlePtr = &cylinder;
	cout << circlePtr->area() << endl;

	return 0;
}
