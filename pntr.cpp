#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int a=10;
    int *b;
    b=&a;

    cout<<a<<endl;
    printf("using pointer %d\n", *b);

    int A[5]={2,4,6,8,10};
    int *p;
    p=A;

    for(int i=0;i<5;i++)
        cout<<p[i]<<endl;

    return 0;
}
