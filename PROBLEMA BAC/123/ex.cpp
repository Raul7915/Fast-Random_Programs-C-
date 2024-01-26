///Intractiune AI & character + objects

#include<iostream>
using namespace std;

int main ()
{
    int X[10], Y[10], h_objects = 0, n, k=0;

    cout<<"n="; cin>>n;


    for(int i=1; i<=n; i++)
        cout<<"X["<<i<<"]:"; cin>> X[i];


    for(i=1; i<=n; i++)
      {
          X[i] = Y[i+1];

        if (k=0)

        k++;
        else
            h_objects++;
    }

    //X - CC
    //Y - Ai
    //h_objects - random objects

    for( i=1; i<=n; i++)
        if(X[i] = k)
        {
            Y[i] = h_objects;
            k=0;
        }
        else
            X[i]= Y[i] + h_objects;


            for( i=1; i<=n; i++)
                cout<<"X["<<i<<"]: "<< X[i];


}
