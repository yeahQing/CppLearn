#include <iostream>

using namespace std;

union test
{
    // 共用同一个内存地址, 首地址相同
    // union变量所占用的内存长度等于最长的成员的内存长度。
    char mark;
    long num;
    float score;
};


/*

a = 123
big-endian 大端模式: 高位字节存储在内存低地址(起始地址) -> 123
little-endian 小端模式: 低位字节存储在内存低地址(起始地址) -> 321

低地址 ------------------------> 高地址
大端模式:
00000000 00000000 00000000 00000001 
int:  00000000 00000000 00000000 00000001 
char: 00000000
如果是大端, c=0
小端模式:
00000001 00000000 00000000 00000000 
int:  00000001 00000000 00000000 00000000 
char: 00000000
如果是小端, c=1
*/
void checkCPU()
{
    union MyUnion
    {
        int a;
        char c;
    } test;
    test.a = 1;
    if (test.c == 1)
        cout << "little endian" << endl;
    else
        cout << "big endian" << endl;
}

int main(int argc, char *argv[])
{
    union test t;
    std::cout << "sizeof(long) is: " << sizeof(long) << std::endl;
    std::cout << "sizeof(union test) is: " << sizeof(test) << std::endl;
    std::cout << "sizeof(t.mark) is: " << sizeof(t.mark) << std::endl;
    std::cout << "sizeof(t.num) is: " << sizeof(t.num) << std::endl;
    std::cout << "sizeof(t.score) is: " << sizeof(t.score) << std::endl;
    checkCPU();
    return 0;
}