/* C++中的基类对象可以通过使用公有继承的派生类对象替代 */
#include <iostream>

using namespace std;

class Base1 {
public:
    void display() const {
        cout << "Base1::display()" << endl;
    }
};

class Base2: public Base1 {
public:
    void display() const {
        cout << "Base2::display()" << endl;
    }
}

class Derived: public Base2 {
public:
    void display() const {
        cout << "Derived::display()" << endl;
    }
}

void fun(Base1* ptr)
{
    // 始终调用的是Base1的display()函数
    // 因为指针的类型只能使用Base1基类的成员
    ptr->display();
}

int main()
{
    Base1 base1;
    Base2 base2;
    Derived derived;

    // 传给fun函数类对象的引用
    fun(&base1);
    fun(&base2);
    fun(&derived);

    return 0;
}
