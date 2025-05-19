#include <stdio.h>

int binarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    int mid;
    int stepCount = 0;

    while (left <= right)
    {
        stepCount++;
        mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            printf("Target found at index %d\n", mid);
            printf("Total steps taken: %d\n", stepCount);
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    printf("Target not found.\n");
    printf("Total steps taken: %d\n", stepCount);
    return -1;
}

int main()
{
    int arr[] = {5, 10, 15, 20, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("Enter your target : ");
    scanf("%d", &target);

    binarySearch(arr, n, target);

    return 0;
}