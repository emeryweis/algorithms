#include <stdio.h>

int main() {

    int A[10] = {2, 5, 7, 10, 20, 37};
    int N = 6;
    int val = 7;

    for (int i = 0; i < N; i++) {
        if (A[i] == val) {
            printf("Value found at index %d\n", i);
            break;
        }
        continue;
    }
    return 0;
}