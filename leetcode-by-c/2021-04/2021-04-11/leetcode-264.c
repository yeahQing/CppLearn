
int nthUglyNumber(int n){
    int p2=1, p3=1, p5=1;
    int* dp = (int *)malloc((n+1) * sizeof(int));
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int num1 = dp[p2] * 2, num2 = dp[p3] * 3, num3 = dp[p5] * 5;
        dp[i] = fmin( num1, fmin( num2, num3 ) );

        if ( dp[i] == num1 ) p2++;
        if ( dp[i] == num2 ) p3++;
        if ( dp[i] == num3 ) p5++;

    }

    return dp[n];
}