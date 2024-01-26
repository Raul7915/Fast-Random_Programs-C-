#include<iostream>
using namespace std;

int main()
{


    int v[50], n, i;

    for( i=1; i<=n ; i++)
        cin>> v[i];

    for( i=1; i<=n ; i++)
    {
        for(int j=1; j<=n; j++)
            if(i==j)
                v[1]= v[i];
    }
}
