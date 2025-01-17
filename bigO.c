#include <stdio.h>

/*
        How code slows as data grows.
        1. Describes performance of an algorithm as amount of data increases
        2. Machine independent (# of steps to completion)
        3. Ignore smaller operations O(N + 1) -> O(N)
            N is the amount of data passed in


*/
// Linear time O(N)
int addUpLinear(int N) {
    int sum = 0;
    for (int i = 0; i <= N; i++) {
        sum += i;
    }
    return sum;
}

//  Constant time O(1)
int addUpConstant(int N) {
    int sum = N * (N - 1) / 2;
    return sum;
}

int main(int argc, char* argv[]) {

    return 0;
}