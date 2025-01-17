#include <stdio.h>

int fib(int i) {
    if (i < 1) return 0;
    if (i == 1) return 1;
    return fib(i - 1) + fib(i - 2);
}

//  TC = O(2^i)
//  SC = O(i)