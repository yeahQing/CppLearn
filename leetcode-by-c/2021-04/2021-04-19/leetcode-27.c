#include <stdio.h>

// 把不为val的元素放进数组，替换原来的值
/*
int removeElement(int* nums, int numsSize, int val){
    int left = 0;
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] != val)
            nums[left++] = nums[right];
    }
    return left;
}
*/

/* 拿右边的值替换左边的值，直到左边的值没有val */
int removeElement(int * nums, int numsSize, int val) {
    int left = 0, right = numsSize;
    while (left < right) {
        if (nums[left] == val) {
            nums[left] = nums[right-1];
            right--;
        }
        else left++;
    }
    return left;
}


int main(int argc, char const *argv[])
{   
    int nums[] = {3, 2, 2, 3};
    int ret = removeElement(nums, sizeof(nums)/sizeof(int), 3);
    printf("%d\n", ret);
    return 0;
}
