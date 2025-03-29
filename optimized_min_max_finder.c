#include <stdio.h>

// Function to find min, max, second min, and second max in one pass
void findMinMaxSecondMinMax(int arr[], int n, int *min, int *max, int *second_min, int *second_max) {
    if (n < 2) {
        printf("Array should have at least two elements.\n");
        return;
    }

    // Initialize min, max, second_min, and second_max
    *min = *max = arr[0];
    *second_min = *second_max = __INT_MAX__;

    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *second_min = *min;
            *min = arr[i];
        } else if (arr[i] != *min && arr[i] < *second_min) {
            *second_min = arr[i];
        }

        if (arr[i] > *max) {
            *second_max = *max;
            *max = arr[i];
        } else if (arr[i] != *max && arr[i] > *second_max) {
            *second_max = arr[i];
        }
    }

    if (*second_min == __INT_MAX__ || *second_max == __INT_MAX__) {
        printf("No distinct second minimum or second maximum exists.\n");
    } else {
        printf("Second minimum: %d\n", *second_min);
        printf("Second maximum: %d\n", *second_max);
    }
}

int main() {
    int arr[] = {10, 5, 3, 8, 15, 7, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min, max, second_min, second_max;
    findMinMaxSecondMinMax(arr, n, &min, &max, &second_min, &second_max);

    return 0;
}
