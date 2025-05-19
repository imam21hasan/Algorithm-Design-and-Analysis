#include <stdio.h>
int main()
{
    int i, n, target, stepCount = 0, pos = -1;
    int arr[] = {10, 20, 30, 40, 50, 60};
    n = sizeof(arr) / sizeof(arr[0]);

    printf("Enter your target : ");
    scanf("%d", &target);

    for (i = 0; i < n; i++)
    {
        stepCount++;
        if (target == arr[i])
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        printf("The target %d is not found !!!", target);
    }
    else
    {
        printf("The target %d is found at index %d.", target, pos);
    }

    printf("\nTotal steps: %d", stepCount);

    return 0;
}
