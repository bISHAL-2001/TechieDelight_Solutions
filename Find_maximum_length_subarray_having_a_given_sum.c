#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int l, int u)
{
    printf("{ ");
    for(int i = l; i < u; i++)
    {
        if(i == u-1)
            printf("%d}", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
}

void calculate(int *arr, int size, int SUM)
{
    int u, l;
    int count = 0;
    for(int i = 0; i<size; )
    {
        int j = i, sum = 0;
        while(j < size)
        {
            sum += arr[j++];
            if(sum == SUM & j-i >= u-l)
            {
                l = i;
                u = j;
                count = u-l;
                print(arr, l, u);
                printf("   The limits: [%d, %d]\n", l, u-1);
            }
        }
        i++;
    }
    if(count != 0)
        printf("The Maximum Length of the subarray: %d", count);
}
int main(void)
{
    int size;
    printf("Enter the number of elements in the array:");
    scanf("%d", &size);


    printf("Enter the %d elements in the array:", size);
    int *arr = (int*)calloc(size, sizeof(int));
    for(int i = 0; i<size; i++)
        scanf("%d", &arr[i]);

    printf("The Array: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    int sum;
    printf("\nEnter the sum for which the subarrays are to be calculated:");
    scanf("%d", &sum);

    calculate(arr, size, sum);

    return(0);
}