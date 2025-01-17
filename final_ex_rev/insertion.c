#include <stdio.h>

void insertion_sort(int A[], int n) {
    int j, k, curr;
    for (j = 1; j < n; j++) {
        curr = A[j];
        k = j - 1;
        while ((k >= 0) && (A[k] > curr)) {
            A[k + 1] = A[k];
            k--;
        }
        A[k + 1] = curr;
    }
}

int main() {

    int A[] = {5, 16, 4, 9, 12, 2, 7};
    insertion_sort(A, sizeof(A)/sizeof(A[0]));

    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++) {
        printf(" %d,", A[i]);
    }
    printf("\n");

    return 0;
}