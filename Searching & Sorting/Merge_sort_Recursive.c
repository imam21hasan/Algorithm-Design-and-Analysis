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
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (i = l, k = 0; i <= h; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
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
    merge_sort(arr, 0, size - 1);
    printf("Sorted array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Total number of comparisons : %d\n", comparison_count);

    return 0;
}