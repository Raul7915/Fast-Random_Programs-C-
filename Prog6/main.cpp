#include <iostream>

using namespace std;

class Punct
{
public:
    Punct(double x, double y) //x=0 y=0
    {
        setX(x);
        setY(y);
    }
    Punct(Punct& pt)
    {
        x=pt.x;
        y=pt.y;
    }
    double getX()
    {
        return x;
    }
    void setX(double x)
    {
        this->x = x;
    }
    double getY()
    {
        return y;
    }
    void setY(double y)
    {
        this->y=y;
    }
private:
    double x;
    double y;
};


class Dreapta{
public:

    Dreapta(Punct pct1, Punct pct2) : p1(pct1), p2(pct2){
    }

    Punct getP1(){return p1;}
    Punct getP2(){return p2;}
private:
    Punct p1;
    Punct p2;
};




    int main()
    {
        Punct p1(5,5),p2(6,6);

        cout << p1.getX() << ";" << p1.getY() << endl;
        p1.setX(8);
        p1.setY(9);
        cout << p1.getX() << ";" << p1.getY() << endl;

        Dreapta d1(p1,p2);
        cout << "Afisarea obiectului:" << d1.getP1().getX() << "" << d1.getP1().getY() << "si" << d1.getP2().getX() << ";" << d1.getP2().getY() << "dreapta d1" << endl;
    }
