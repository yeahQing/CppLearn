#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int *pt;
    int (*pa)[3]; // 数组指针
    int arr1[2][3];
    int arr2[3][2];

    int **p2;
    int *a[3];
    int *a5 = arr1[-1];
    int *a1 = arr1[0];
    int *a2 = arr1[1];
    int *a3 = arr1[2];
    // int *a4 = arr1[3];

    a[0] = a1;
    a[1] = a2;
    a[2] = a3;
    a[3] = a5;
    // a[3] = a4;
    // for (int i = 0; i < 4; i++) {
    //     *a[i] = i;
    //     printf("%p %d\n", a[i], *a[i]);
    // }
    int arr3[] = {1, 2, 3, 4};
    arr3[4] = 0;
    printf("%d,%d\n", arr3[4], arr3[0]);
    
    return 0;
}
