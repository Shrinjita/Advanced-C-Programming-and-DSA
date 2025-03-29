#include <stdio.h>
#include<stdlib.h>
// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
return -1;
}
int main() {
    int rows1;
    printf("Enter the number of elements: ");
    scanf("%d", &rows1);
    int* arr = (int*)malloc(rows1 * sizeof(int));
    printf("Enter %d elements:\n",rows1);
    for(int i=0;i<rows1;i++)
    {printf("Enter element %d: ",(i+1));
        scanf("%d",&arr[i]);}
    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);
    int result = binarySearch(arr, 0, rows1 - 1, target);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    return 0;
}
