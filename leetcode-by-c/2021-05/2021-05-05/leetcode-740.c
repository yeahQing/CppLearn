#define MAXN 10005
int memo[MAXN];

int dfs(int num, int cnt[]) {
    if (num <= 0) return 0;
    if (cnt[num] == 0) return dfs(num - 1, cnt);
    if (memo[num] != 0) return memo[num];

    int res = cnt[num] * num;
    
    // 如果存在num-1，那么要对两种结果分别进行记忆化递归，然后取最大值结果
    if (cnt[num - 1] != 0) res = fmax(dfs(num - 1, cnt), res + dfs(num - 2, cnt));
    else res += dfs(num - 2, cnt);

    memo[num] = res;

    return res;
}

int deleteAndEarn(int* nums, int n){
    int cnt[10005];
    memset(cnt, 0, sizeof(cnt));
    // 统计每个数字出现的次数
    for (int i = 0; i < n; i++) {
        ++cnt[nums[i]];
    }

    for (int i = 10000; i >= 1; i--) {
        if (cnt[i] != 0) return dfs(i, cnt);
    }
    return 0;
}



