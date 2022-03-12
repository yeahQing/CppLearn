#include <stdio.h>
#include "include/head.h"
/*
gcc main.c ./src/add.c ./src/div.c ./src/mult.c ./src/sub.c ./include/head.h -o app
静态库制作
cd src
将源文件编译成目标文件
gcc -c add.c div.c mult.c sub.c
之后会编译而不链接生成 add.o dic.o mult.o sub.o
使用ar命令构建静态库
注意libcalc.a在使用-l时,链接器会忽略lib和.a前缀和后缀，所以只需要-lcalc即可
ar rv ../lib/libcalc.a add.o div.o mult.o sub.o
显示打包文件的内容
ar t ../lib/libcalc.a

编译main.c
gcc -c main.c
链接静态库并编译目标文件main.o,这里需要指定连接静态库的目录和包含头文件的目录
gcc main.o -o app -lcalc -L ./lib/ -I ./include/
运行可执行文件(编译链接后的) ./app
*/
int main()
{
    int a = 2, b = 2;
    
    printf("%d\n", add(a, b));
    printf("%d\n", sub(a, b));
    printf("%d\n", mult(a, b));
    printf("%d\n", div(a, b));

    return 0;
}