#include <stdio.h>
int main()
{
    int arr[] = {5, 1, 4, 2, 8, 3};
    int n, i, j, comCount = 0, swapCount = 0;
    n = sizeof(arr) / sizeof(arr[0]);

    printf("The Main array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            comCount++;
            if (arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount++;
            }
        }
    }

    printf("\nThe bubble sorted array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\nTotal comparisons : %d", comCount);
    printf("\nTotal swaps : %d", swapCount);
    printf("\nTotal step taken : %d", comCount + swapCount);

    return 0;
}