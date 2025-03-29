#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Swap function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for numbered array
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Selecting the first element as the pivot
    int i = low + 1, j = high;

    while (1) {
        while (i <= j && arr[i] < pivot) i++;
        while (i <= j && arr[j] > pivot) j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++; j--;
        } else {
            break;
        }
    }
    swap(&arr[low], &arr[j]); // Place pivot correctly
    return j;
}

// Quick Sort function for numbered array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Partition function for string array
int partitionStr(char *arr[], int low, int high) {
    char *pivot = arr[low];
    int i = low + 1, j = high;

    while (1) {
        while (i <= j && strcmp(arr[i], pivot) < 0) i++;
        while (i <= j && strcmp(arr[j], pivot) > 0) j--;
        if (i <= j) {
            char *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        } else {
            break;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

// Quick Sort function for string array
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
            int *num = (int*)malloc(n * sizeof(int));
            printf("Enter %d integers:\n", n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &num[i]);
            }

            quickSort(num, 0, n - 1);

            printf("\nSorted numbered array:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", num[i]);
            }
            printf("\n");
            free(num);
            break;
        }
        case 2: {
            char **str = (char**)malloc(n * sizeof(char*));
            printf("Enter %d strings:\n", n);
            for (int i = 0; i < n; i++) {
                str[i] = (char*)malloc(100 * sizeof(char));
                scanf("%s", str[i]);
            }

            quickSortStr(str, 0, n - 1);

            printf("\nSorted string array:\n");
            for (int i = 0; i < n; i++) {
                printf("%s ", str[i]);
                free(str[i]);
            }
            printf("\n");
            free(str);
            break;
        }
        default:
            printf("Invalid option selected.\n");
            break;
    }
    return 0;
}