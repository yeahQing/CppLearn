#include <stdio.h>
#include <stdlib.h>

void test(int * x, int k) {
    *x = 1;
    printf("%d\n", *x);
}

int main(void) {
    // 如果指针不分配内存就传递给其他函数，则会导致 Segmentation fault
    // int *x;
    // int * x = (int *)malloc(sizeof(int));
    // test(x, 1);

    int b = 4;
    int **p = (int **)malloc(2 * sizeof(int *));
    *p = &b;
    // int a[][2] = {{1, 2}, {3, 4}};
    printf("%d", p[0][0]);


    return 0;
}
