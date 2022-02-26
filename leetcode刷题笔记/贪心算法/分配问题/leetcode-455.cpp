/**
 * @file leetcode-455.cpp
 * @name Assign Cookies (Easy)
 * @author YeahQing (yeahqing.cn)
 * @brief 
 * @version 0.1
 * @date 2022-02-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 先按照饥饿度排序
        sort(g.begin(), g.end());
        // 按照饼干大小从小到大，升序排序
        sort(s.begin(), s.end());
        
        int child = 0, cookie = 0;
        
        while (child < g.size() & cookie < s.size())
        {
            if (g[child] <= s[cookie]) child++;
            cookie++;
        }
        
        return child;
    }
};