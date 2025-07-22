#include <stdio.h>

int comparison_count = 0;

void merge(int arr[], int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = 0;
    int temp[h - l + 1];

    while (i <= mid && j <= h)
    {
        comparison_count++;
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= h)
    {
        temp[k++] = arr[j++];
    }

    for (i = l, k = 0; i <= h; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void iterative_merge_sort(int arr[], int n)
{
    int curr_size;
    int left_start;

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
    {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
        {
            int mid = left_start + curr_size - 1;
            int right_end = (left_start + 2 * curr_size - 1 < n - 1) ? (left_start + 2 * curr_size - 1) : (n - 1);

            if (mid < right_end)
                merge(arr, left_start, mid, right_end);
        }
    }
}
int main()
{
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    iterative_merge_sort(arr, size);

    printf("Sorted array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Total number of comparisons : %d\n", comparison_count);

    return 0;
}