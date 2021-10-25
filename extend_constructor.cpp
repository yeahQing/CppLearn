#include <iostream>

using namespace std;

class Base1 {
public:
	Base1() {}
	Base1(int x): x(x) {}

	int getX() const { return x; }
private:
	int x;
};

class Derived: public Base1 {
public:
	Derived(int x, int y): Base1(x), y(y){
	}

	int getY() const { return y; }
private:
	int y;
};

int main()
{
	Derived d(2, 5);
	cout << "x is " << d.getX();
	cout << ", y is " << d.getY() << endl;
	return 0;
}
