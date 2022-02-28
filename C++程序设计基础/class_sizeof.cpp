#include <iostream>

using namespace std;


class A {};

class C {

public:
	int a;

};


struct B {};


int main(int argc, char *argv[])
{
	
	printf("%ld\n", sizeof(A));
	printf("%ld\n", sizeof(B));
	printf("%ld\n", sizeof(C));
	
	return 0;
}
