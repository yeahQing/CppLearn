/**
 * @file leetcode-435.cpp
 * @author YeahQing(yeahqing.cn)
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

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        int n = intervals.size();

        if (n < 2)
        {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        int total = 0, prev = intervals[0][1];
        for (int i = 1; i < n; ++i)
        {
            // 当前区间的开头小于前一个区间的结尾，表示相交
            if (intervals[i][0] < prev)
            {
                // 移除的区间
                ++total;
            }
            else
            {
                prev = intervals[i][1];
            }
        }
        return total;
    }
};