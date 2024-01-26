#include <iostream>
#include<fstream>

using namespace std;

int main()
{

    int n, a;


    ifstream f("bac");
        f>>a;

    for( int i=1; i<=15; i++)
        if(a % 2 == 0 && a!= (a+1))

        cout<< a;
}
