#include <iostream>


class Test{};

int main(int argc, char *argv[])
{
	Test a, b;
	Test c, d;
	
	int i1, i2;

	std::cout << "the addr of i1 is: " << &i1 << std::endl;
	std::cout << "the addr of i2 is: " << &i2 << std::endl;

	std::cout << "sizeof(test) is: " << sizeof(Test) << std::endl;
	std::cout << "the addr of a is: " << &a << std::endl;
	std::cout << "the addr of b is: " << &b << std::endl;
	
	std::cout << "the addr of c is: " << &c << std::endl;
	std::cout << "the addr of d is: " << &d << std::endl;

	return 0;
}


