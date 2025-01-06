#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i + 1;
        }
    }
    return -1;
}

void main() {
    int n, i, target, result;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    
    for (i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to be searched: ");
    scanf("%d", &target);
    
    result = linearSearch(arr, n, target);
    if (result != -1) {
        printf("Element %d found at %d position.\n", target, result);
    } else {
        printf("Element %d not found in the list.\n", target);
    }
}
