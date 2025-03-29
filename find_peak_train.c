#include <stdio.h>

int findPeak(int arr[], int n) {
    for (int i = 1; i < n - 1; i++) {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            return i;
        }
    }
    return -1; // This line should not be reached as the array is definitely a TRAIN
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int peak = findPeak(arr, n);
    printf("%d\n", peak);
    return 0;
}