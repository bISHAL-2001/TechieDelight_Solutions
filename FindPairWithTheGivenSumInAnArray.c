#include <stdio.h>
#include <stdlib.h>
void sort(int *arr, int size)
{
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void findPairs(int *arr, int size, int sum)
{
    int l = 0, u = size-1;
    while(l < u)
    {
        if(arr[l] + arr[u] == sum)
            printf("Pair Found: (%d, %d)\n", arr[l++], arr[u--]);
        else if(arr[u] + arr[u] < sum)
            l++;
        else
            u--;
    }
}
int main(void)
{
    int *arr = (int*)calloc(10, sizeof(int ));
    printf("Enter 10 numbers:\n");
    for(int i = 0; i<10; i++)
        scanf("%d", &arr[i]);
    sort(arr, 10);

    printf("Enter the sum for which you want to find pairs for:\n");
    int sum;
    scanf("%d", &sum);
    findPairs(arr, 10, sum);
    free(arr);
}