/**
 * @file leetcode-135.cpp
 * @name Candy (Hard)
 * @author YeahQing (yeahqing.cn)
 * @brief
 * @version 0.1
 * @date 2022-02-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <vector>
#include <numeric> /* accumulate */

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int size = ratings.size();

        if (size < 2)
            return size;

        vector<int> nums(size, 1);

        for (int i = 1; i < size; i++)
        {
            if (ratings[i] > ratings[i - 1])
                nums[i] = nums[i - 1] + 1;
        }

        for (int i = size - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i])
            {
                // compare the candy number
                if (nums[i - 1] <= nums[i])
                {
                    nums[i - 1] = nums[i] + 1;
                }
                // 左边孩子的糖果数如果已经大于等于右边孩子的糖果数+1，那么就不需要改变
                // if the number of candy which the left child have
                // more or equal the number of candy which the right child have
                // then nothing will do
                // otherwise left number of candy += right number of candy plus one
                // nums[i-1] = max(nums[i-1], nums[i] + 1);
            }
        }

        // default = sum()
        return accumulate(nums.begin(), nums.end(), 0);
    }
};