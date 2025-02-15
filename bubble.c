#include <stdio.h>
#include <stdbool.h>

void bubblesort(int arr[], int n) {
    int i, j, temp;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}

void printarray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}


int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]); // num of array elements
    
    bubblesort(arr, n);
    printf("Sorted array: \n");
    printarray(arr, n);

    return 0;
}