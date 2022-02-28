/*
cmp()会有三种返回值（以qsort为例）:
1、返回一个正数：a排列在b之后；
2、返回0：a、b相等；
3、返回一个负数：a排在b之前；
*/
long cmp(int *x, int *y) {
    printf("x = %d, y = %d\n", *x, *y);
    long sx = 10, sy = 10;
    while (sx <= *x) {
        sx *= 10;
    }
    while (sy <= *y) {
        sy *= 10;
    }
    // 小于0 *x 应该放在*y的前面
    return sx * (*y) + (*x) - sy * (*x) - (*y);
}

char *largestNumber(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    if (nums[0] == 0) {
        char *ret = malloc(sizeof(char) * 2);
        ret[0] = '0', ret[1] = '\0';
        return "0";
    }
    char *ret = malloc(sizeof(char) * 1000);
    char *p = ret;
    for (int i = 0; i < numsSize; i++) {
        sprintf(p, "%d", nums[i]);
        p += strlen(p);
    }
    return ret;
}
