/* 删除有序数组中的重复项 II */
int removeDuplicates(int* nums, int numsSize){
    if (numsSize < 2) return numsSize;
    int p1 = 2, p2 = 2;
    while(p2 < numsSize) {
        if (nums[p1-2] != nums[p2]) {
            nums[p1] = nums[p2];
            p1++;
        }
        p2++;
    }
    return p1;
}