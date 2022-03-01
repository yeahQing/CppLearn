#include <list>
#include <vector>
#include <iostream>

class Q {
public:
    typedef int SubType;
};

template <class T>
class MyClass {
    // 不加tpyename是编译错误
    typename T::SubType *ptr;
};

MyClass<Q> q;

std::list<int> changeList(std::list<int> &l)
{
    std::list<int> l2;
    l.push_back(1);
    l.push_front(10);
    l.pop_front();
    l.pop_front();
    // 重新赋值
    l2.assign(l.begin(), l.end());
    // 清空l2
    l2.erase(l2.begin());
    // 在pos处插入elem
    l2.insert(l2.begin(), 4);
    return l2;
}

void printList(const std::list<int> &l)
{
    std::list<int>::const_iterator it;
    for (it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printVector(std::vector<T> &v)
{
    std::vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    // std::list<int> lt;
    std::list<int> arrList(a, a+5);
    printList(arrList);
    std::list<int> l2 = changeList(arrList);
    printList(l2);
    // 创建2个100
    std::list<int> lt(2, 100);
    printList(lt);
    // 创建2个10
    std::vector<int> v(2, 10);
    printVector(v);

    return 0;
}