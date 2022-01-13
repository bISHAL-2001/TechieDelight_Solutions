#include <stdio.h>

void print(int *arr, int l, int u, int *count)
{
    printf("SubArray %d. { ", (*count)++);
    for(int i = l; i < u; i++)
    {
        if(i == u-1)
            printf("%d}\n", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
}

void calculate(int *arr, int size)
{
    int u, l, count = 1;
    for(int i = 0; i<size; )
    {
        int j = i, sum = 0;
        while(j < size)
        {
            sum += arr[j++];
            if(sum == 0)
            {
                l = i;
                u = j;
                print(arr, l, u, &count);
            }
        }
        i++;
    }
    if(count > 0)
        printf("SubArray Exists with sum = 0");
}
int main(void)
{
    int arr[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
    calculate(arr, sizeof(arr)/sizeof(arr[0]));
}