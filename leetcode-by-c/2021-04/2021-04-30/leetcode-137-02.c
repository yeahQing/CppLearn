#include <stdio.h>
#include <limits.h>
int singleNumber(int *nums, int numsSize) {
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
        int total = 0;
        for (int j = 0; j < numsSize; ++j) {
            // 右移i位，表示把二进制第i个位置移到个位，然后和1进行与运算，判断第i位是否为1
            total += ((nums[j] >> i) & 1);
        }
        if (total % 3) {
            ans |= (1u << i);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    int nums[] = {2, 2, 2, 3};
    printf("%d\n", singleNumber(nums, sizeof(nums)/sizeof(nums[0])));
    printf("%u\n", UINT_MAX); // 4294967295 = 2 * 2147483647 + 1;
    int x = 2;
    printf("x ^ 0 = %d x ^ 1 = %d\n", x ^ 0, x ^ 1);
    int y = -2;
    printf("y = %d ~y = %d y ^ 1 = %d(~y) y ^ 0 = %d(y) \n", y, ~y, y ^ 1, y ^ 0);
    printf("%d", 1<<31);
    return 0;
}
