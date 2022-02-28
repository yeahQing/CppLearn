#include <stdio.h>
/* gcc leetcode-633.c -lm 链接数学库 */
#include <math.h>
// #include <stdbool.h>
#define true 1
#define false 0

typedef int bool;

bool judgeSquareSum(int c) {
    int n = (int)sqrt(c);
    for (int a = 0; a <= n; a++) {
        double b = sqrt(c - a * a);
        if (b == (int)b) return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    /* code */
    printf("ret = %d\n", judgeSquareSum(5));
    return 0;
}
