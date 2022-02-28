/* 动态规划 + 滚动数组 */

int robRange(int* nums, int start, int end) {
    int first = nums[start], second = fmax(nums[start], nums[start+1]);
    for (int i = start+2; i <= end; i++) {
        int temp = second;
        second = fmax(first + nums[i], second);
        first = temp;
    }
    return second;
}


int rob(int* nums, int numsSize){
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return fmax(nums[0], nums[1]);
    // [0, n-2] 偷第一个不偷最后一个 [1, n-1] 偷最后一个不偷第一个
    return fmax(robRange(nums, 0, numsSize-2), robRange(nums, 1, numsSize-1));

}