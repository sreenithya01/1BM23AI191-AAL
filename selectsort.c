#include <stdio.h>

void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;
    
  
    for(i = 0; i < n-1; i++) {
        min_idx = i;

        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        

        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void print_array(int arr[], int size) {
	int i;
    for( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr,n;
    n = 5;
    
    
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    
    arr[0] = 64;
    arr[1] = 25;
    arr[2] = 12;
    arr[3] = 22;
    arr[4] = 11;
    
    printf("Original array: \n");
    print_array(arr, n);
    
    selection_sort(arr, n);
    
    printf("Sorted array: \n");
    print_array(arr, n);
    
    return 0;
}

