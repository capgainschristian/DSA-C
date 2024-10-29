#include<iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r1={10,5};
    
    r1.length=15;
    r1.breadth=7;

    printf("%ld\n", sizeof(r1)); 
    cout<<r1.length<<endl;
    cout<<r1.breadth<<endl;
    return 0;
}
