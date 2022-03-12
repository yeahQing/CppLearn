#include <iostream>

class Base
{
public:
    void doSomething() const
    {
        std::cout << "I did something " << dontChangeMe() << std::endl;
    }

private:
    // virtual int dontChangeMe() const final = 0;
    virtual int dontChangeMe() const = 0;
};

class ChildOfBase : public Base
{
private:
    // int dontChangeMe() const final override { return 419; }
    int dontChangeMe() const override { return 419; }
};

class BadChildOfChild : public ChildOfBase
{
    int dontChangeMe() const override
    {
        return 61;
    }
};

int main()
{
    BadChildOfChild badLittleChild;
    badLittleChild.doSomething(); //结果是61
    ChildOfBase childOfBase;
    childOfBase.doSomething();

    return 0;
}