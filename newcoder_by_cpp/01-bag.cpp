#include <vector>
#include <iostream>

using namespace std;

class Solution {

public:
    // 滚动数组优化空间复杂度：第i次计算只会利用第i-1次计算，所以逆序滚动即可
    static int knapsack(int n, int V, vector<vector<int>>& vw)
    {
        vector<int> dp(V+1, 0);

        for (int i = 0; i < n; i++)
        {
            // 装这个物品最少用多少的体积
            for (int j = V; j >= vw[i][0]; j--)
            {
                // dp[j] = dp[j];
                cout << i << " " << j << endl;
                // 这里的dp[j - vw[i][0]]是i-1次算好的体积为j-vw[i][0]的背包的最大重量
                cout << dp[j] << " " << dp[j - vw[i][0]] << " " << dp[j - vw[i][0]] + vw[i][1] << endl;
                // 不能顺序而是逆序的原因是，如果
                // 顺序的话，后面的j是需要用的前面的j的，但是这里我们使用的dp[j-vw[i][0]]应该是
                // i-1次的，如果先更新了前面的j，dp[j-vw[i][0]]就变成第i次的而不是前一次的了。
                // 所以这里必须是逆序，从V开始。
                dp[j] = max(dp[j], dp[j - vw[i][0]] + vw[i][1]);
                    
                            
                    
            }
        }

        return dp[V];
    }

};

int main(int argc, char* argv[])
{
    int n = atoi(argv[1]);
    vector<vector<int>> content;
    int v, w;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        cin >> v >> w;
        tmp.push_back(v);
        tmp.push_back(w);
        content.push_back(tmp);
    }

    for (vector<vector<int>>::iterator it = content.begin(); it != content.end(); it++)
    {
        cout << (*it)[0] << " " << (*it)[1] << endl;
    }

    cout << Solution::knapsack(atoi(argv[1]), atoi(argv[2]), content) << endl;

    return 0;
}