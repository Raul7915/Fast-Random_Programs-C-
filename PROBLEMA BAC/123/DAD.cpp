#include<iostream>
using namespace std;

int main()
{

    int v[10], a[10], n, k=0, x, i;

    cout<< "\nNumarul este: ";
    cin>> n;
    x=n;


    while(n!=0)
    {
        n = n / 10;
        k++;
    }

    for( i = 0; i < k ; i++)
        v[i] = x / 10;

        for( i = 0; i < k-1 ; i++)
        {
        for( int j = k-1 ; i >= 0 ; j--)
            if(v[i+1] - v[i] == v[j] - v[j-1])
                return 1;
            else
                return 0;

}
}
