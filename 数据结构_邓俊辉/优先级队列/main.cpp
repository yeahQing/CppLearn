#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void heapfipy(vector<int> &v)
{
    // 下滤
    /*
               9
             8   7
           5  1  6 4
          3 2

    */
    int n = v.size();
    // 如果节点的下标是从0开始的,那么最后一个有孩子的父节点就是floor(n/2)-1
    // 从最后一个有孩子的节点开始进行下滤
    // 为什么要小于n
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        int j = 2 * (i + 1) < n ? (max(v[i], v[2 * (i + 1)]) == v[i] ? i : 2 * (i + 1)) : i;
        j = 2 * i + 1 < n ? (max(v[j], v[2 * i + 1]) == v[j] ? j : 2 * i + 1) : j;

        // 3 != 7
        while (i != j)
        {
            // swap
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            i = j;
            j = 2 * (i + 1) < n ? (max(v[i], v[2 * (i + 1)]) == v[i] ? i : 2 * (i + 1)) : i;
            j = 2 * i + 1 < n ? (max(v[j], v[2 * i + 1]) == v[j] ? j : 2 * i + 1) : j;
        }
    }
}

int main()
{
    // 堆就是优先队列，优先队列的数据结构使用到了堆的性质
    // 优先队列只需要满足完全二叉树的结构性和堆的堆序性即可，不需要满足顺序性。而堆排序需要满足顺序性。
    // 大顶堆 {9, 8, 7, 5, 1, 6, 4, 3, 2} -> {1, 2, 3, 4, 5, 6, 7, 8, 9}
    // 使用一个建堆的方法来构造一个满足堆性质的向量
    // 假设当前的序列是{2, 1, 6, 3, 9, 7, 4, 8, 5}
    // 使用Floyd算法建堆
    vector<int> v{2, 1, 6, 3, 9, 7, 4, 8, 5};
    cout << v.size() << " " << v.capacity() << endl;

    heapfipy(v);
    int n = v.size();
    int i = 0;
    for_each(v.begin(), v.end(), [n = &n, i = &i](int num) -> void
             { cout << num << " "; });
    cout << endl;

    return 0;
}