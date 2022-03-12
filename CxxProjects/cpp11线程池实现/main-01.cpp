#include <vector>
#include <iostream>
#include <random>
#include <thread>
#include <future>
#include <algorithm>

int main(void)
{
       
    // define lambda function
    auto f = [](auto it1, auto it2, auto it3)
    {
        return std::inner_product(it1, it2, it3, 0.0);
    };

    std::vector<int> v1{3, 5, 10};
    std::vector<int> v2{4, 7, 2};

    auto dp1 = std::inner_product(std::begin(v1), std::end(v1), std::begin(v2), 0.0);
    std::cout << "dp1: " << dp1 << "\n"; // this part works fine

    // set up packaged task
    std::packaged_task<int(std::vector<int>::iterator, std::vector<int>::iterator, std::vector<int>::iterator)> pt1{f};
    auto f1 = pt1.get_future();                                                   // get future
    std::thread t1{std::move(pt1), std::begin(v1), std::end(v1), std::begin(v2)}; // move pt to thread

    auto dp2 = f1.get();
    std::cout << "dp2: " << dp2 << "\n";
    t1.join();

    return 0;
}