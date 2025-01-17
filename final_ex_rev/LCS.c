#include <stdio.h>

int max(int x, int y) {
    return x > y ? x : y;
}

int lcs(char* s1, char* s2, int m, int n) {
    if (m == 0 || n == 0) return 0;

    if (s1[m - 1] == s2[n - 1]) {
        return 1 + lcs(s1, s2, m - 1, n - 1);
    }
    else {
        return max(lcs(s1, s2, m, n - 1), lcs(s1, s2, m - 1, n));
    }
}