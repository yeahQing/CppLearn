#include <iostream>

using namespace std;

// char* echo()
// {
//     char *p = "Hello World";
//     return p;
// }

class A {
    // 对齐
    // int a;
    virtual void pa() {}
};

class B : virtual public A{
    // int a;
    // virtual void pa() override {}
    // virtual void pb() {}
};

class C {
    // int a;
    // virtual void pb() override {}
    // virtual void pc() {}
    C() {}
    ~C() {}
};


// namespace AN {
//     struct X {};
//     struct Y {};
//     void f(int) {std::cout << "A::f\n";}
//     void g(X) {std::cout << "A::g\n";} 
// }

// namespace BN{
//     void f(int i) {
//         f(i);
//     }

//     void g(AN::X x)
//     {
//         g(x);
//     }

//     void h(AN::Y y)
//     {
//         h(y);
//     }
// }

int main()
{
    typedef unsigned int uint32;

    uint32 c = 1;

    std::cout << c << std::endl;

    unsigned int x = 10;
    int y = -4;

    std::cout << x/y << std::endl;
    
    x = -10;
    y = 5;

    std::cout << x/y << std::endl;


    int a = 4;
    char b[4];

    std::cout << __FILE__ << std::endl;

    // std::cout << echo() << std::endl;

    std::cout << sizeof(A) << std::endl;
    std::cout << sizeof(B) << std::endl;
    std::cout << sizeof(C) << std::endl;
    
    // BN::f(1);

    return 0;

}