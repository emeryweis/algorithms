#include <stdio.h>

int binarySearch(int A[], int N, int val) {
    int left, right, middle;
    left = 0;
    right = N - 1;
    while(left <= right) {
        middle = left + ((right - left) / 2);   // int division in c
        if (A[middle] == val) {
            return middle;
        }
        else if (A[middle] < val) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return -1;
}

int main() {

    int A[10] = {2, 5, 7, 10, 20, 37};
    int N = sizeof(A)/sizeof(A[0]);
    printf("What number do you seek?\n");
    int val;
    scanf("%d", &val);
    int index = binarySearch(A, N, val);
    printf("%d\n", index);

    return 0;
}