#include <stdio.h>

int fib_iter(int i) {
    int F[i + 1];
    F[0] = 0;
    F[1] = 1;
    for (int k = 2; k <= i; k++) {
        F[k] = F[k - 1] + F[k - 2];
    }
    return F[i];
}

//  TC = O(i)
//  SC = O(i)