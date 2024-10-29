#include<iostream>
#include<stdio.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int area(struct Rectangle r)
{
    return r.length*r.breadth;
};

int perimeter(struct Rectangle r)
{
    int p;
    p=2*(r.length+r.breadth);

    return p;
};

int main()
{
    Rectangle r={0,0};

    printf("Enter length and breadth: ");
    cin>>r.length>>r.breadth;

    int ar=area(r);
    int peri=perimeter(r);

    printf("Area=%d\nPerimeter=%d\n", ar, peri);    

    return 0;
}
