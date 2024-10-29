#include<stdio.h>
#include<stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nThe elements are: ");
    for(i=0;i<arr.length;i++)
        printf("%d", arr.A[i]);
    printf("\n"); 
};

int main()
{
    struct Array arr;
    int n, i;
    printf("\nEnter the size of the array:\n");
    scanf("%d", &arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;

    printf("\nEnter the number of numbers:\n");
    scanf("%d", &n);

    printf("\nEnter elements of the array:\n");
    for (i=0;i<n;i++)
        scanf("%d", &arr.A[i]);
    arr.length=n;

    Display(arr);

    return 0; 
}