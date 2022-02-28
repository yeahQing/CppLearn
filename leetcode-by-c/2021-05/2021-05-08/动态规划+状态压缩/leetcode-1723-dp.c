#include <stdio.h>
#include <limits.h>

#define MIN(a, b) ((a < b) ? a : b)
#define MAX(a, b) ((a > b) ? a : b)

int minimumTimeRequired(int* jobs, int jobsSize, int k) {
    int n = jobsSize;
    int sum[1 << n];
    sum[0] = 0;
    for (int i = 1; i < (1 << n); i++) {
        int x = __builtin_ctz(i), y = i - (1 << x);
        sum[i] = sum[y] + jobs[x];
    }
    int dp[k][1 << n];
    for (int i = 0; i < (1 << n); i++) {
        dp[0][i] = sum[i];
    }

    for (int i = 1; i < k; i++) {
        for (int j = 0; j < (1 << n); j++) {
            int minn = INT_MAX;
            for (int x = j; x; x = (x - 1) & j) {
                minn = MIN(minn, MAX(dp[i - 1][j - x], sum[x]));
            }
            dp[i][j] = minn;
        }
    }
    return dp[k - 1][(1 << n) - 1];
}


int main(int argc, char const *argv[])
{
    // 复合字面量
    printf("%d\n", minimumTimeRequired((int[]){3, 2, 3}, 3, 3));
    return 0;
}

