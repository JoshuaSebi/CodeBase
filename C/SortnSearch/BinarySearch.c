#include <stdio.h>

int binsearch(int arr[], int n, int e) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == e)
            return mid;

        if (arr[mid] < e)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, arr[20], e;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements of sorted array: ");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d",&e);
    int result = binsearch(arr, n, e);
    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
