#include <vector>
#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n, 0);
    std::vector<int>::iterator it;
    int i;
    for (it = arr.begin(), i = 1; it != arr.end(); it++, i++)
    {
        *it += i;
    }

    std::vector<int> a(arr.begin(), arr.end());
    // a.erase(a.begin() + 2, a.end());
    it = a.begin();
    while (it != a.end())
    {
        a.erase(a.begin() + 2);
        std::cout << *it << " ";
        it++;
    }

    std::cout << std::endl;
    return 0;
}