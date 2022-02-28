/* 动态规划 */

int longestCommonSubsequence(char * text1, char * text2){
        const int M = 1000;
        const int N = 1000;
        int m = strlen(text1);
        int n = strlen(text2);
        int dp[M][N];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = fmax(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
}