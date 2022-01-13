#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void print(int *a, int size)
{
    for(int i =0; i<size; i++)
    {
        printf("%d ", a[i]);
    }
}
int main(void)
{
    int arr[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    int l = 0;
    int u = arr_size - 1;
    int middle = 0;

    printf("The condition of array before sort: ");
    print(arr, arr_size);
    while(middle <= u)
    {
        switch(arr[middle])
        {
            case 0:
                swap(&arr[l ++], &arr[middle ++]);
                break;
            case 1:
                middle ++;
                break;
            case 2:
                swap(&arr[middle], &arr[u --]);
                break;
        }
    }
    printf("\nThe condition of array after sort: ");
    print(arr, arr_size);
}