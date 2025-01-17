#include <stdio.h>

int knapsack01(int W, int n, int* v, int* w) {
    int with_i, i, k;
    int sol[n + 1][W + 1];

    for (k = 0; k <= W; k++) {
        sol[0][k] = 0;
    }

    for (i = 1; i <= n; i++) {
        for (k = 0; k <= W; k++) {
            sol[i][k] = sol[i - 1][k];
            if (k > w[i]) {
                with_i = v[i] + sol[i - 1][k - w[i]];
                if (sol[i][k] < with_i) {
                    sol[i][k] = with_i;
                }
            }
        }
    }
    return sol[n][W];
}

//  TC = O(nW)
//  SC = O(nW)
