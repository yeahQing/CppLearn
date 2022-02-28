/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* 动态规划 */
int cmp(const void* a, const void* b) {
    return (*(int *)a - *(int *)b);
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    int len = numsSize;
    // 升序排列数组
    qsort(nums, numsSize, sizeof(int), cmp);

    int ans[len];
    // 以nums[i]为最大整数结尾的整除子集至少有其本身，长度至少为1
    for (int i = 0; i < len; i++) ans[i] = 1;
    // 第 1 步：动态规划找出最大子集的个数、最大子集中的最大整数
    int maxSize = 1;
    int maxVal = ans[0];

    // 以nums[i]为最大整数结尾的整除子集的最大长度
    for (int i = 1; i < len; i++) {
        // 0到i-1是已经求完最大整除子集的长度
        for (int j = 0; j < i; j++) {
            // 如果nums[i] 可以整除 nums[j] 证明nums[i] 大于 nums[j]
            // 那么也就表示nums[i]可以整除以nums[j]为最大元素的整除子集中的所有元素
            // 那么以nums[i]为最大元素的整除子集的长度也就是dp[j]+1
            // nums[j] 可能有多个都可以被nums[i]整除, 取最大的长度
            // 不一定j越大以nums[j]结尾的整除子集的长度也就越大, 
            // 比如以nums[2] = 8结尾的长度为ans[2]=4, 而以nums[3] = 12结尾的长度为ans[3]=2
            // 那么一开始nums[4] = 24, 24 % 8 == 0, ans[4] = max(ans[4]=1, ans[2]+1) = 5
            // 而24 % 12 == 0, ans[4] = max(ans[4]=5, ans[3]+1) = 5
            if (nums[i] % nums[j] == 0) {
                ans[i] = fmax(ans[i], ans[j]+1);
            }
        }
        // 如果ans[i]，以nums[i]为最大整数的整除子集的长度大于当前的最大长度了
        // 那么就更新最大长度和最大值
        if (ans[i] > maxSize) {
            maxSize = ans[i];
            maxVal = nums[i];
        }
    }

    // 第 2 步：倒推获得最大子集
    // 结果数组
    int* res = malloc(sizeof(int) * len);
    // 返回的数组的长度
    *returnSize = 0;
    // 如果长度为1, 那么上面的循环不会执行,直接返回数组的第一个元素
    if (maxSize == 1) {
        res[(*returnSize)++] = nums[0];
        return res;
    }

    // 如果以当前nums[i]为最大整数的整除子集的长度是求得的最长长度,
    // 并且nums[i]这个最大整数可以整除求得的最大值
    // 那么则将这个数添加到结果集, 并更新最大值和长度
    // i = 4 找nums[4] 之后找下一个满足条件的i 和 nums[i]

    for (int i = len - 1; i >= 0 && maxSize > 0; i--) {
        if (ans[i] == maxSize && maxVal % nums[i] == 0) {
            res[(*returnSize)++] = nums[i];
            maxVal = nums[i];
            maxSize--;
        }
    }
    return res;

}