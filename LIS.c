/*
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
*/

#include <stdio.h>
#include <string.h>

int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0; // Handle edge case of empty array

    int dp[numsSize];
    int maxLength = 1;

    // Initialize dp array with 1s (each element is its own LIS of length 1)
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
    }

    // Build dp array
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) { // Check if it's strictly increasing
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
        }
        // Update the maximum LIS length
        maxLength = maxLength > dp[i] ? maxLength : dp[i];
    }

    return maxLength;
}

int main() {
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = lengthOfLIS(nums, numsSize);
    printf("Length of Longest Increasing Subsequence: %d\n", result);
    return 0;
}

