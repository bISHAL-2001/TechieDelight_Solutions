#include <stdio.h>
#include <stdlib.h>

void check(int *arr, int size) {
    int u, l;
    for (int i = 0; i < size;) {
        int j = i, zeroes = 0, ones = 0;
        while (j < size) {
            if(arr[j] == 0)
                zeroes += 1;
            else if(arr[j] == 1)
                ones += 1;
            if (zeroes == ones && j-i >= u-l) {
                l = i;
                u = j;
            }
            j++;
        }
        i++;
    }
    if(u-l != 0)
        printf("The SubArray with maximum length with equal number of zeroes and ones = %d.", u+1 - l);
}

int main(void)
{
    int l;
    printf("Enter the expected length of the binary array:");
    scanf("%d", &l);

    int *arr = (int*)calloc(l, sizeof(int));
    printf("Enter %d binary digits(0s and 1s):", l);

    for(int i = 0; i < l;) {
        int temp;
        scanf("%d", &temp);
        if(temp == 0 || temp == 1)
            arr[i++] = temp;
        else
            printf("Wrong Input! Enter a binary digit: ");
    }

    check(arr, l);

    arr = NULL;
    free(arr);
}
