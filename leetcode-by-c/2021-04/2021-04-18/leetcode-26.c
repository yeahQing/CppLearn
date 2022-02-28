#include <stdbool.h>

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t){
    if (numsSize == 0 || numsSize == 1) return false;
    int slow = 0, fast = 1;
    while ( fast <= numsSize ) {
        //printf("slow= %d,fast=%d\n", slow, fast);
        if (fast-slow > k || fast == numsSize) {
            slow++;
            fast = slow+1;
            continue;
        }
        if (abs(nums[slow] - nums[fast]) <= t ) {
            return true;
        }
        else fast++;

    }
    return false;
}