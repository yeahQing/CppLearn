#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// arr: 原数组 order_case: 升序/降序
vector<int> countingSort(vector<int>& arr, bool order_asce)
{
    // int minNumber = INT32_MAX, maxNumber = INT32_MIN;
    int maxNumber = *(max_element(arr.begin(), arr.end()));
    int minNumber = *(min_element(arr.begin(), arr.end()));
    // 开辟max-min+1的数组
    vector<int> countArr(maxNumber-minNumber+1, 0);
    
    // 计数
    for (int num : arr)
    {   
        int index = order_asce ? num-minNumber : maxNumber-num;
        countArr[index] += 1;
    }
    // 计算在目标数组所在的下标
    for (int i = 1; i < arr.size(); i++)
    {
        countArr[i] += countArr[i-1];
    }
    // 开辟一个和arr一样的数组
    vector<int> targetArr(arr);
    // 逆序遍历保持稳定
    for (int i = arr.size()-1; i >= 0; i--)
    {
        int countIndex = order_asce ? arr[i] - minNumber : countIndex = maxNumber - arr[i];
        // 使得计数排序保持稳定, 即相同数的顺序与原数组保持一致
        targetArr[countArr[countIndex] - 1] = arr[i];
        countArr[countIndex] -= 1;
    }
    return targetArr;
}

int main()
{
    vector<int> arr{3, -1, 2, 3, 1};
    int order_asce = false; // 默认升序排列升序排列
    vector<int> res = countingSort(arr, order_asce);
    int sum = 0; // 校验和
    for_each(res.cbegin(), res.cend(), [&](const int& val)->void{
        cout << val << " ";
        sum += val;
    });
    cout << "\n";
    cout << sum << endl;

    return 0;
}