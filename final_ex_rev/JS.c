#include <stdio.h>

int js_iter(int* v, int* p, int n) {
    int j, with_j, without_j;
    int sol[n + 1];
    sol[0] = 0;

    for (j = 1; j <= n; j++) {
        with_j = v[j] + sol[p[j]];
        without_j = sol[j - 1];

        if (with_j >= without_j) {
            sol[j] = with_j;
        }
        else {
            sol[j] = without_j;
        }
    }
    return sol[n];
}