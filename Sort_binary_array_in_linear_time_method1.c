#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, int size)
{
    int pivot = 1;
    int j = 0;

    for(int i = 0; i<size; i++)
    {
        if(arr[i] < pivot)
        {
            swap(&arr[i], &arr[j]);
            j++;
        }
    }
}

void print(int *arr, int size)
{
    for(int i = 0; i<size; i++)
        printf("%d ", arr[i]);
}
int main(void)
{
    int A[] = { 0, 0, 1, 0, 1, 1, 0, 1, 0, 0 };
    int size = sizeof(A)/sizeof(A[0]);
    printf("Array in unsorted order: ");
    print(A, sizeof(A)/sizeof(A[0]));
    sort(A, size);

    printf("\nArray in sorted order: ");
    print(A, sizeof(A)/sizeof(A[0]));
    return 0;
}