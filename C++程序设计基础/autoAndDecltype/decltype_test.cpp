#include <vector>
using namespace std;
template <typename T>
class Base {
public:
    void func(T& container) {
        m_it = container.begin();
    }
private:
    // typename T::iterator m_it;  //注意这里
    decltype(T().begin()) m_it;
    // T::iterator m;
};
int main()
{
    const vector<int> v;
    Base<const vector<int>> obj;
    obj.func(v);
    return 0;
}