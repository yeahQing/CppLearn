// #include <thread>
// #include <cassert>
// #include <cstdarg>
// #include <cctype>
// #include <cerrno>
// #include <climits>
// #include <cmath>
// #include <filesystem>
// #include <regex>
// #include <mutex>
// #include <shared_mutex>
// #include <condition_variable>
// #include <atomic>
// #include <map>
// #include <queue>
// #include <typeinfo>
// #include <type_traits> /* 编译时类型信息 */
// #include <bitset>
// #include <functional>
// #include <utility>
// #include <tuple>

// C++20
// #include <semaphore>
// #include <latch>
// #include <barrier>
// constexpr.cpp
// Compile with: cl /EHsc /W4 constexpr.cpp
#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>

using namespace std;

// Pass by value
constexpr float exp(float x, int n)
{
    return n == 0 ? 1 : n % 2 == 0 ? exp(x * x, n / 2)
                                   : exp(x * x, (n - 1) / 2) * x;
}

// Pass by reference
constexpr float exp2(const float &x, const int &n)
{
    return n == 0 ? 1 : n % 2 == 0 ? exp2(x * x, n / 2)
                                   : exp2(x * x, (n - 1) / 2) * x;
}

// Compile-time computation of array length
template <typename T, int N>
constexpr int length(const T (&)[N])
{
    return N;
}

// Recursive constexpr function
constexpr int fac(int n)
{
    return n == 1 ? 1 : n * fac(n - 1);
}

// User-defined type
class Foo
{
public:
    constexpr explicit Foo(int i) : _i(i) {}
    constexpr int GetValue() const
    {
        return _i;
    }

private:
    int _i;
};

int main(int argc, char* argv[])
{
    // foo is const:
    constexpr Foo foo(5);
    // foo = Foo(6); //Error!

    // Compile time:
    constexpr float x = exp(5, 3);
    constexpr float y{exp(2, 5)};
    constexpr int val = foo.GetValue();
    constexpr int f5 = fac(5);
    const int nums[]{1, 2, 3, 4};
    const int nums2[length(nums) * 2]{1, 2, 3, 4, 5, 6, 7, 8};

    const char* s[2] = {"Hello", "World"};
    cout << s[0] << endl;
    cout << s[1] << endl;
    // Run time:
    cout << "The value of foo is " << foo.GetValue() << endl;
    int (*p)[3] = new int[10][3] {{1, 2, 3}, {4, 5, 6}};
    cout << sizeof(*p) << endl;
    unique_ptr<decltype(p)> uq = make_unique<decltype(p)>(p);
    cout << (*uq)[0] << endl;
    (*uq)[0][0] = 3;
    
    cout << (*uq)[0] << endl;
    // 将唯一指针uq所管理的堆对象的所有权移交给唯一指针q所管理
    unique_ptr<decltype(p)> q = move(uq);
    if (uq == nullptr)
    {
        cout << "uq is null" << endl;    
    }
    
    
    cout << (*q)[0] << endl;

    cout << typeid(q).name() << endl;

    if (q == nullptr)
    {
        cout << "q is call release()" << endl;
    }
    else
    {
        cout << (*q)[0] << endl;
    }

    cout << p[0][0] << endl;

    q.release();


    if (q == nullptr)
    {
        cout << "q is call release()" << endl;
    }
    else
    {
        cout << (*q)[0] << endl;
    }

    return 0;
}