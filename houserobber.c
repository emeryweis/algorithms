/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security systems connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money 
of each house, return the maximum amount of money you can rob 
tonight without alerting the police.
*/

#include <stdio.h>
#include <string.h>

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0; // No houses to rob
    if (numsSize == 1) return nums[0]; // Only one house

    // dp is maximum amount of money that can be robbed from the first i houses.
    int dp[numsSize]; 
    dp[0] = nums[0]; // Base case for the first house
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1]; // Base case for the first two houses

    for (int i = 2; i < numsSize; i++) {
        dp[i] = dp[i - 1] > (nums[i] + dp[i - 2]) ? dp[i - 1] : (nums[i] + dp[i - 2]);
    }

    return dp[numsSize - 1];
}

int main() {
    int nums[] = {2, 7, 9, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Maximum amount of money robbed: %d\n", rob(nums, numsSize));
    return 0;
}
