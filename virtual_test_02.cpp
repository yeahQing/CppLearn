#include <iostream>

using namespace std;


class Base0 {
public:
	int var0;
	void fun0() {
		cout << "this is a virtual base class and variable is " << var0 << endl;
	}
};

class Base1: virtual public Base0 {
public:
	int var1;
};

class Base2: virtual public Base0 {
public:
	int var2;
};

class Derived: public Base1, public Base2 {
public:
	int var;
	void fun()
	{
		cout << "this is a derived funtion and variable is: " << var << endl;
	}
};

int main()
{
	Derived d;
	d.var0 = 2;
	d.fun0();
	// sharing memory, Base0 Base1 Base2 have same memory
	d.Base1::var0 = 5;
	d.Base1::fun0();
	d.fun0();
	d.Base2::fun0();
	return 0;
}
