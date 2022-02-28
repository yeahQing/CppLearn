int findMin(int* nums, int numsSize){
    int n = numsSize;
    int low = 0, high = n-1;

    /*
        最小值左侧的点都比high大，最小值右侧的点都比high小
        如果nums[pivot] > high, 证明nums[pivot]在最小值的左侧，缩小左侧区间
        如果nums[pivot] < high, 证明nums[pivot]在最小值的右侧，缩小右侧区间
    */

    while (low < high) {
        int pivot = (low + high) >> 1;
        if (nums[pivot] > nums[high]) low = pivot+1;
        else high = pivot;
        printf("%d %d", low, high);
    }

    return nums[low];

}