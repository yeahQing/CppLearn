#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[])
{

    char buf[10] = "";
    // fd = 0 文件描述符为0是标准输入 stdin 1是stdout 2是stderr
    read(0, buf, 9); // /* 从标准输入 0 读入字符 */
    fprintf(stderr, "%s", buf); /* 向标准错误输出 stderr 写字符 */
    write(1, buf, strlen(buf)); ///* 向标准输出 stdout 写字符 */

    return 0;
}