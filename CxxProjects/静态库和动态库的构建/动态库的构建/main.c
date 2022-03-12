#include <stdio.h>
#include "include/head.h"
/*
cd src
PIC表示位置无关代码的意思 -f表示设置PIC为true
gcc -c -fPIC add.c sub.c mult.c div.c
gcc -shared add.o sub.o mult.o div.o -o ../lib/libcalc.so

gcc main.c -o app -I ./include/ -l calc -L ./lib/
直接运行./app会报错，找不到动态库的路径
◼ 静态库：GCC 进行链接时，会把静态库中代码打包到可执行程序中
◼ 动态库：GCC 进行链接时，动态库的代码不会被打包到可执行程序中
◼程序启动之后，动态库会被动态加载到内存中，通过 ldd （list dynamic dependencies）命令检查动态库依赖关系
◼如何定位共享库文件呢？
当系统加载可执行代码时候，能够知道其所依赖的库的名字，但是还需要知道绝对路径。
此时就需要系统的动态载入器来获取该绝对路径。
对于elf格式的可执行程序，是 由ld-linux.so来完成的，
它先后搜索elf文件的
DT_RPATH段 ——> 环境变量 LD_LIBRARY_PATH ——> /etc/ld.so.cache文件列表 
——>/lib/，/usr/lib 目录找到库文件后将其载入内存。

通过ldd指令检查app的动态依赖关系如下，发现找不到所以来的动态链接库libcalc.so的绝对路径。
以下方法只在当前终端有效
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/yeahqing/git/CppLearn/CxxProjects/静态库和动态库的构建/动态库的构建/lib

以下方法永久有效
方法一：
修改当前用户的环境变量
vim ~/.bashrc
最后一行插入： export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/usr_name/linux/lession06/library/lib
source ~/.bashrc

修改系统环境变量
方法二： sudo vim /etc/profile
最后一行插入：export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/usr_name/linux/lession06/library/lib
source /etc/profile

方法三
配置/etc/ld.so.cache文件列表
sudo vim /etc/ld.so.conf
最后一行插入：/home/usr_name/linux/lession06/library/lib
sudo ldconfig

方法四
将所依赖度动态库复制到/lib或/usr/lib目录下也可，但不推荐，因为这两个目录下有大量的系统库文件

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