#include <iostream>

using namespace std;

class Base0 {
public:
	int var0;
	void fun0() {
		cout << "this is a fun0 function" << endl;
	}
};

class Base1: public Base0 {
public:
	int var1;	
};

class Base2: public Base0 {
public:
	int var2;
};

class Derived: public Base1, public Base2 {
public:
	int var;
	void fun() { 
		cout << "this is a fun function has variable: " << Base1::var0 <<  endl;
	}

};

int main()
{
	Derived d;
	//will call an exception amiguous
//	d.fun();
//	d.fun0();
//	d.var0 = 2;
	d.Base1::var0 = 5;
	d.Base1::fun0();
	d.Base2::fun0();
	d.fun();
	return 0;
}
