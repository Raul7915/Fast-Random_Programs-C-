#include<iostream>
#include <string.h>

using namespace std;

int main()

{
    char s[30] = "23+42/4+1-5*3";
    char x[5] = {'*', '/', '+', '-' };

    int n, j, i, k;
    char a[30];


k=1;


    a[0] = atoi(strtok(s, x));

    for( i=1; i<n ; i++)

        a[i] = atoi( strtok(NULL, x) );



    for( i=0; i<6 ; i++)
        cout << (int)a[i]<< endl;

}

