#include <iostream>

using namespace std;

class Base1 {
public:
    // Base1 has a none parameter constructor and one para,eter constructor
    Base1() {
        // inline
        cout << "default constructor called" << endl;
    }
    Base1(int x): x(x) {
        cout << "one parameter constructor called" << endl;
    }
    // get function
    int getX() {return x;}

private:
    int x = 0;
};

class Derived: public Base1 {
public:
    Derived(int x, int y): Base1(), y(y) {
        cout << "Derived constuctor called" << endl;
    }
    
    int getY() {return y;}

private:
    int y; // inner object
};

int main()
{
    Derived obj(1, 2);
    cout << obj.getX() << " " << obj.getY() << endl;
    return 0;
}

