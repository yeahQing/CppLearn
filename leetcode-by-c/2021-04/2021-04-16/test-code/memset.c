#include <stdio.h>
#include <string.h>
#define MAXN 10

/*

memset在string.h头文件中声明 
函数原型是extern void *memset(void *buffer, int c, int count) 
buffer：为指针或是数组,
c：是赋给buffer的值,
count：是buffer的长度.

*/
int main(int argc, char const *argv[])
{
    int arr[MAXN];
    printf("sizeof(arr)=%ld\n", sizeof(arr));
    // 给数组的n个长度初始化为指定字符
    // 初始化int类型数组值只能为-1或0，其他值取后8位都会导致错误
    // -1的二进制码为 11111111 11111111 11111111 11111111
    // 0的二进制码为 00000000 00000000 00000000 00000000
    memset(arr, 0, sizeof(arr));
    // 因为memset是按每一个字节赋值的，1的后8位是0000 0001, 在赋值时
    // arr数组的每一个值有4个字节, 则arr[0]会被赋值为
    // 00000001 00000001 00000001 00000001 这个二进制的值并不是1 转为%d以十进制输出为16843009
    // memset(arr, 1, sizeof(arr));
    /* 
        511和-1初始化arr数组结果数组都被赋值为-1,
        因为memset函数只取0~255 即只把后8位赋值给指定内存的字节 
    */
    // memset(arr, -1, sizeof(arr));
    // memset(arr, 511, sizeof(arr));
    for (size_t i = 0; i < MAXN; i++)
    {
        printf("arr[%ld]=%d, arr[%ld]=%p\n",i, arr[i], i, &arr[i]);
    }
    

    return 0;
}

/* 
arr[0]=  0x7fff9ab8bf70,
arr[n-1]=0x7fff9ab8bf94,
sizeof(arr)=40
 */
