#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Array inside stack
    int A[3][4]={{1,2,3,4}, {2,4,6,8}, {1,3,5,7}};

    int *B[3];
    int **C;

    // Rows created in the stack, columns created in the heap
    B[0]=(int *)malloc(4*sizeof(int));
    B[1]=(int *)malloc(4*sizeof(int));
    B[2]=(int *)malloc(4*sizeof(int));

    // Rows and columns are created in the heap
    C=(int **)malloc(3*sizeof(int *));
    C[0]=(int *)malloc(4*sizeof(int));
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));

    return 0;

}