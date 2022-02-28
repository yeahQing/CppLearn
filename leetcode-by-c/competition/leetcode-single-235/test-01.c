#include <stdio.h>

void foo(int **a, int m, int n) {
    int i = 1;
    int j = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]=%d\n", i, j, a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // 一个指针，它指向一个有10个int元素的数组
    // int (* arrPtr)[10] = NULL;   
    // 如果没有括号，则声明 int*arrPtr[l0]；表示 arrPtr 是一个具有 10 个 int 类型指针的数组。
    int a[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    printf("%p\n", a[0]);
    printf("%p\n", a[1]);
    int * p[3]; // 指针数组 3个int *类型的指针数组
    // int (*p)[3] = NULL // 数组指针, 指针用NULL或分配内存来初始化
    // char (*pa)[4]  -> char a[4]; pa = &a; // 数组指针 pa是一个指针指向一个char [4]的数组

    // 数组指针接收a int (*P)[4]
    // 指针数组 int * p[3] 接收**a char **pp
    p[0] = a[0];
    p[1] = a[1];
    p[2] = a[2];
    foo(p, 2, 3);
}