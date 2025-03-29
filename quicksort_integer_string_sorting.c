#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Swap function for integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for integer array
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; 
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= j && arr[i] <= pivot) i++;
        while (i <= j && arr[j] > pivot) j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
        } else {
            break;
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}

// Partition function for string array
int partitionStr(char *arr[], int low, int high) {
    char *pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= j && strcmp(arr[i], pivot) <= 0) i++;
        while (i <= j && strcmp(arr[j], pivot) > 0) j--;
        if (i <= j) {
            char *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } else {
            break;
        }
    }

    char *temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

// Quick Sort for integers
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Quick Sort for strings
void quickSortStr(char *arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partitionStr(arr, low, high);
        quickSortStr(arr, low, pivotIndex - 1);
        quickSortStr(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n, option;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Select the type of array to sort:\n");
    printf("1. Numbered Array\n");
    printf("2. String Array\n");
    scanf("%d", &option);

    switch (option) {
        case 1: {
            int num[n];
            printf("Enter %d integers:\n", n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &num[i]);
            }

            quickSort(num, 0, n - 1);

            printf("\nSorted array:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", num[i]);
            }
            printf("\n");
            break;
        }
        case 2: {
            char *str[n];  // Array of pointers
            printf("Enter %d strings:\n", n);
            for (int i = 0; i < n; i++) {
                str[i] = (char *)malloc(100 * sizeof(char));
                scanf("%s", str[i]);
            }

            quickSortStr(str, 0, n - 1);

            printf("\nSorted array:\n");
            for (int i = 0; i < n; i++) {
                printf("%s ", str[i]);
                free(str[i]);  // Free allocated memory
            }
            printf("\n");
            break;
        }
        default:
            printf("Invalid option selected.\n");
            break;
    }

    return 0;
}
