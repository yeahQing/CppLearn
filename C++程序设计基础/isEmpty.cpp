#include <iostream>

using namespace std;

class Empty{};
class NotEmpty{char a;};

class AnotherEmpty: Empty {};
class NotEmpty2: NotEmpty {};

template <class T>
class EmptyHepler: T {
    char b[10];
};

class EmptyHelper {
    char b[10];
};

void printBool(bool b)
{
    cout << b << endl;
}


template <typename T>
void isEmptyClass()
{
    printBool (sizeof(EmptyHelper) == sizeof(EmptyHepler<T>));
}


int main(int argc, char *argv[])
{
    isEmptyClass<Empty>(); // 1
    isEmptyClass<AnotherEmpty>(); // 1
    isEmptyClass<NotEmpty>(); // 0
    isEmptyClass<NotEmpty2>(); // 0
    return 0;
}