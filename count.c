#include <stdio.h>

void count_sort(int* A, int N, int k) {
    int counts[k+1];
    int sorted_copy[N];
    int j, t;

    for (j=0; j<=k; j++) {
        counts[j] = 0;
    }
    for (t=0; t<N; t++) {
        counts[A[t]]++;
    }
    for (j=1; j<=k; j++) {
        counts[j] = counts[j] + counts[j-1];
    }
    for (t=N-1; t>=0; t--) {
        counts[A[t]]--;
        sorted_copy[counts[A[t]]] = A[t];
    }
    for (t=0; t<N; t++) {
        A[t] = sorted_copy[t];
    }

}

int main() {
    int arr[] = {5, 8, 3, 9, 14, 21, 7, 2, 16};


    return 0;
}