#include <iostream>

class Base {
public:
    virtual ~Base() {}
    // 虚函数实现多态
    virtual void run() {
        std::cout << "Base run..." << std::endl;
    }
};

// 默认继承方式是private
class Derived1: public Base {
// 默认访问修饰符是private
public:
    virtual void run() override {
        std::cout << "Derived1 run..." << std::endl;
    }

};

class Derived2: public Base {
public:
    virtual void run() override {
        std::cout << "Derived2 run..." << std::endl;
    }

};

int main(int argc, char* argv[])
{
    Base* b1 = new Derived1();
    Base* b2 = new Derived2();

    b1->run();
    b2->run();

    delete b1;
    delete b2;

    return 0;
}