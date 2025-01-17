#include <stdio.h>

void insertion(int arr[], int n) {
    int j, k, curr;
    for (j = 1; j < n; j++) {
        curr = arr[j];
        k = j - 1;
        while ((k >= 0) && (arr[k] > curr)) {
            arr[k + 1] = arr[k];
            k--;
        }
        arr[k + 1] = curr;
    }

}

void numandsum(int arr[], int n) {
    int i, even = 0, evensum = 0, odd = 0, oddsum = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even++;
            evensum += arr[i];
        }
        else {
            odd++;
            oddsum += arr[i];
        }
    }
    printf("Number of evens: %d\n", even);
    printf("Sum of evens: %d\n", evensum);
    printf("Number of odds: %d\n", odd);
    printf("Sum of odds: %d\n", oddsum);
}

int get_min(int *arr, int n) {
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int get_max(int *arr, int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {5, 18, 4, 23, 65, 26, 32, 15, 75, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Min function before sorting: %d\n\n", get_min(arr, n));
    printf("Max function before sorting: %d\n\n", get_max(arr, n));

    //sorting array
    insertion(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //finding min and max values
    int min = arr[0];
    int max = arr[n - 1];

    printf("Min = %d\n", min);
    printf("Max = %d\n", max);

    //finding number of even and odd ints and summing them
    numandsum(arr, n);

    

    return 0;
}