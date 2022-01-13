#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void compute(int *A, int size)
{
    int zeroesCount = 0;
    for(int i  = 0; i<size; i++)
    {
        if(A[i] == 0)
            zeroesCount++;
    }

    int onesCount = size - zeroesCount;
    for(int i = 0; i<size;)
    {
        while(zeroesCount != 0)
        {
            A[i++] = 0;
            zeroesCount --;
        }
        while(onesCount != 0)
        {
            A[i++] = 1;
            onesCount--;
        }
    }
}
void print(int *A, int size)
{
    for(int i = 0; i<size; i++)
        printf("%d ", A[i]);
}

int main(void)
{
    int A[] = { 1, 0, 0, 0, 1, 0, 1, 1 };

    printf("Array before sorting: ");
    print(A, sizeof(A)/sizeof(A[0]));

    compute(A, sizeof(A)/sizeof(A[0]));

    printf("\nArray after sorting: ");
    print(A, sizeof(A)/sizeof(A[0]));
    return 0;
}