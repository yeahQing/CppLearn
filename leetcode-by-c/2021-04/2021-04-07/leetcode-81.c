#include <stdbool.h>

bool search(int* nums, int numsSize, int target) {
    if (numsSize == 0) {
        return false;
    }
    if (numsSize == 1) {
        return nums[0] == target;
    }
    int l = 0, r = numsSize - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
            ++l;
            --r;
        } else if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[numsSize - 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return false;
}
