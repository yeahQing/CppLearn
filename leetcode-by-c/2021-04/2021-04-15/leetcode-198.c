/* 动态规划 时间复杂度: O(n) 空间复杂度: O(n) */
int rob(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int * dp = (int *)calloc(numsSize, sizeof(int));

    int dp[0] = nums[0];
    /* 有两间房屋就要比较两间房屋的钱谁多谁少 */
    int dp[1] = fmax(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++)
        dp[i] = fmax(dp[i-1], nums[i] + dp[i-2]);

    return dp[numsSize-1];
}

/* 动态规划 + 滚动数组 时间复杂度: O(n) 空间复杂度: O(1) */
int rob(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int first = nums[0];
    /* 有两间房屋就要比较两间房屋的钱谁多谁少 */
    int second = fmax(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        int temp = second;
        second = fmax(nums[i] + first, second);
        first = temp;
    }
        
    return second;
}