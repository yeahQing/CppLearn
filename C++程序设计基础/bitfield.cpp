#include <iostream>

struct Date
{
    unsigned short nWeekDay : 3;  // 0...7
    unsigned short nMonthDay : 6; // 0...31
    unsigned short nMonth : 5;    // 0...12
    unsigned short nYear : 8;     // 0...100
};

struct Foo
{
    char a: 8; // max = 8 bit = 1 Byte warning while exceed max  
    char b: 2; // 2 bit
    int i: 15; // 15 bit
};

struct Foo1
{
    /* data */
    unsigned a: 4; // 4
    unsigned : 0; // 4+28 = 32 bit fill the memory unit, next variable move to next memory unit
    unsigned b: 4; // 4 new memory unit 
    unsigned c: 4; // 4
};

struct Foo2
{
    int i: 8; // 8 bit
    int j: 4; // 4 bit
    double b; // 64 bit the first memory unit out of range, so move to next 
    int a: 3; // the second memort unit out of range, so move to next
}; // total three memory units

int main(int argc, char *argv[])
{
    std::cout << "sizeof(unsigned int) is: " << sizeof(unsigned int) << std::endl;
    std::cout << "sizeof(unsigned short) is: " << sizeof(unsigned short) << std::endl;
    std::cout << "sizeof(struct Date) is: " << sizeof(struct Date) << std::endl;
    std::cout << "sizeof(Date) is: " << sizeof(Date) << std::endl;
    std::cout << "sizeof(Foo) is: " << sizeof(Foo) << std::endl;
    std::cout << "sizeof(Foo1) is: " << sizeof(Foo1) << std::endl;
    std::cout << "sizeof(Foo2) is: " << sizeof(Foo2) << std::endl;
    return 0;
}