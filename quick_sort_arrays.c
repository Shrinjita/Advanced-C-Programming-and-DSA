#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Swap two integers
void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Swap two strings
void swapString(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Print integer array
void printIntArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Print string array
void printStringArray(char *arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

// Partition function for integer array
int partitionInt(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swapInt(&arr[i], &arr[j]);
        }
    }
    swapInt(&arr[i + 1], &arr[high]);

    // Print step-wise sorting progress
    printIntArray(arr, high + 1);
    
    return i + 1;
}

// QuickSort function for integer array
void quickSortInt(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionInt(arr, low, high);
        quickSortInt(arr, low, pi - 1);
        quickSortInt(arr, pi + 1, high);
    }
}

// Partition function for string array
int partitionString(char *arr[], int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swapString(&arr[i], &arr[j]);
        }
    }
    swapString(&arr[i + 1], &arr[high]);

    // Print step-wise sorting progress
    printStringArray(arr, high + 1);
    
    return i + 1;
}

// QuickSort function for string array
void quickSortString(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partitionString(arr, low, high);
        quickSortString(arr, low, pi - 1);
        quickSortString(arr, pi + 1, high);
    }
}

int main() {
    int choice;
    printf("Choose the type of array to sort:\n");
    printf("1. Integer Array\n");
    printf("2. String Array\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: {
            int size;
            printf("Enter the size of the integer array: ");
            scanf("%d", &size);

            int *arr = (int *)malloc(size * sizeof(int));
            if (arr == NULL) {
                printf("Memory allocation failed!\n");
                return 1;
            }

            printf("Enter %d elements:\n", size);
            for (int i = 0; i < size; i++) {
                scanf("%d", &arr[i]);
            }

            printf("Original Array: ");
            printIntArray(arr, size);

            printf("Sorting Steps:\n");
            quickSortInt(arr, 0, size - 1);

            printf("\nSorted Array: ");
            printIntArray(arr, size);

            free(arr);
            break;
        }

        case 2: {
            int size;
            printf("Enter the size of the string array: ");
            scanf("%d", &size);

            char **arr = (char **)malloc(size * sizeof(char *));
            if (arr == NULL) {
                printf("Memory allocation failed!\n");
                return 1;
            }

            printf("Enter %d strings:\n", size);
            for (int i = 0; i < size; i++) {
                arr[i] = (char *)malloc(100 * sizeof(char));
                if (arr[i] == NULL) {
                    printf("Memory allocation failed for string!\n");
                    return 1;
                }
                scanf("%99s", arr[i]); // Prevents buffer overflow
            }

            printf("Original Array: ");
            printStringArray(arr, size);

            printf("Sorting Steps:\n");
            quickSortString(arr, 0, size - 1);

            printf("\nSorted Array: ");
            printStringArray(arr, size);

            // Free allocated memory
            for (int i = 0; i < size; i++) {
                free(arr[i]);
            }
            free(arr);
            break;
        }

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
