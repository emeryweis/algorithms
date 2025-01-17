/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?
*/

#include <stdio.h>

int climbStairs(int n) {
    if (n <= 1) return 1; // Base cases

    int dp[n + 1];
    dp[0] = 1; // 0 steps
    dp[1] = 1; // 1 step

    // Fill the DP array
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 5; // Number of steps
    printf("Number of distinct ways to climb %d steps: %d\n", n, climbStairs(n));
    return 0;
}


