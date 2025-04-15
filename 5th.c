#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int n) {
    int sorted[n], unsorted[n];
    int sortedcount = 0, unsortedcount = n;
    int i, j;

    for (i = 0; i < n; i++) {
        unsorted[i] = arr[i];
    }

    while (unsortedcount > 0) {
        int key = unsorted[0];
        
        for (i = sortedcount - 1; i >= 0 && sorted[i] > key; i--) {
            sorted[i + 1] = sorted[i];
        }
        sorted[i + 1] = key;
        sortedcount++;

        for (j = 0; j < unsortedcount - 1; j++) {
            unsorted[j] = unsorted[j + 1];
        }
        unsortedcount--;

        printf("Sorted array: ");
        for (i = 0; i < sortedcount; i++) {
            printf("%d ", sorted[i]);
        }
        printf("\n");

        printf("Unsorted array: ");
        for (i = 0; i < unsortedcount; i++) {
            printf("%d ", unsorted[i]);
        }
        printf("\n\n");
    }
}

int main() {
    int i;
    int arr[] = {20, 10, 40, 30, 60, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    insertionSort(arr, n);

    return 0;
}

