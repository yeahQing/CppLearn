/* 滑动窗口 */

int longestOnes(int* nums, int numsSize, int k){
    int ret = 0, zero = 0, left = 0;
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == 0) zero++;
        while (zero > k) {
            if(nums[left++] == 0) zero--;
        }
        ret = fmax(ret, right-left+1);
    }
    return ret;
}