int findMin(int* nums, int numsSize){
    int n = numsSize;
    int low = 0, high = n-1;
    while (low != high) {
        // int pivot = (low+high) >> 2;
        int pivot = low + (high - low) / 2;
        if (nums[pivot] < nums[high]) high = pivot;
        else if (nums[pivot] > nums[high]) low = pivot+1;
        else high--;
    }

    return nums[low];
}