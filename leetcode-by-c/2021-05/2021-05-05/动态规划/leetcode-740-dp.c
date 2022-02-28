#include <math.h>
#include <string.h>

int rob(int *nums, int n) {
    int first = nums[0], second = fmax(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        int temp = second;
        second = fmax(first+nums[i], second);
        first = temp;
    }
    return second;
}

int deleteAndEarn(int* nums, int numsSize){
    // 获得数组中的最大值
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        max = fmax(max, nums[i]);
    }

    int sum[max + 1];
    memset(sum, 0, sizeof(sum));

    for (int i = 0; i < numsSize; i++) {
        sum[nums[i]] += nums[i];
    }

    return rob(sum, max + 1);

}