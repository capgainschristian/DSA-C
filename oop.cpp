#include<iostream>
#include<stdio.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;

void initialise(int l, int b)
{
    length=l;
    breadth=b;
}

int area()
{
    return length*breadth;
};

int perimeter()
{
    int p;
    p=2*(length+breadth);

    return p;
}
};

int main()
{
    Rectangle r={0,0};
    
    int l, b;
    printf("Enter length and breadth: ");
    cin>>l>>b;

    r.initialise(l, b);

    int ar=r.area();
    int peri=r.perimeter();

    printf("Area=%d\nPerimeter=%d\n", ar, peri);    

    return 0;
}
