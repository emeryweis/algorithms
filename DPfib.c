#include <stdio.h>

int memoized(int n, int* memo) {
    int result; 

    if (memo[n] != 0) return memo[n];

    if (n == 1 || n == 2) result = 1;
    else result = memoized(n-1, memo) + memoized(n-2, memo);

    memo[n] = result;
    return result;
}

int bottom_up(int n) {
    if (n == 1 || n == 2) return 1;

    int bottomUp[n + 1]; //4
    bottomUp[1] = 1;
    bottomUp[2] = 1;

    for (int i = 3; i <= n+1; i++) {
        bottomUp[i] = bottomUp[i - 1] + bottomUp[i - 2];
        // i = 3, bottomUp[3] = bottomUp[2] + bottomUp[1] == 2
    }
    return bottomUp[n];
}

int main() {

    int memo[20];

    for (int i = 0; i < sizeof(memo)/sizeof(memo[0]); i++) {
        memo[i] = 0;
    }

    printf("%d\n", memoized(3, memo));
    printf("%d\n", memoized(5, memo));
    printf("%d\n", memoized(7, memo));
    printf("%d\n\n", memoized(11, memo));
    
    printf("%d\n", bottom_up(3));
    printf("%d\n", bottom_up(5));
    printf("%d\n", bottom_up(10));

    printf("%d\n", bottom_up(11));

    
    

    return 0;
}