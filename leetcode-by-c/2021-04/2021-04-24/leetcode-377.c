#include <limits.h>

/* 动态规划 */
int combinationSum4(int* nums, int numsSize, int target){
    int * dp = (int *)calloc(target+1, sizeof(int));
    
    dp[0] = 1;
    
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] <= i && dp[i-nums[j]] < INT_MAX - dp[i]) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    
    return dp[target];
}   