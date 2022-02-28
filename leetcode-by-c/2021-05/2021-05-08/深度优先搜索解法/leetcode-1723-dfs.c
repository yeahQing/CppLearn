#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX(a, b) ((a > b) ? a : b)
// 定义一个整数意义的无穷大
int ans = 0x3f3f3f3f;

void dfs(int idx, int *jobs, int n, int *workers, int k, int max);
void dfs2(int idx, int *jobs, int n, int *workers, int k, int max, int used);
int minimumTimeRequired(int *jobs, int jobsSize, int k);

void dfs(int idx, int *jobs, int n, int *workers, int k, int max)
{
    // 如果当前算出来的最大工作量比ans大，证明当前的max不是最小的，不用更新ans
    // 剪枝
    if (max >= ans)
        return;
    // 如果max < ans && 已经分配了全部的工作, 那就更新ans
    if (idx == n)
    {
        ans = max;
        return;
    }

    for (int i = 0; i < k; i++)
    {
        workers[i] += jobs[idx];
        dfs(idx + 1, jobs, n, workers, k, MAX(workers[i], max));
        // 把第idx个工作分配给这个工人后，要拿回这个工作，将这个工作再分配给其他工人，查看最优解
        workers[i] -= jobs[idx];
    }
}

void dfs2(int idx, int *jobs, int n, int *workers, int k, int max, int used)
{
    // 如果当前算出来的最大工作量比ans大，证明当前的max不是最小的，不用更新ans
    // 剪枝
    if (max >= ans)
        return;
    // 如果max < ans && 已经分配了全部的工作, 那就更新ans
    if (idx == n)
    {
        ans = max;
        printf("ans = %d\n", ans);
        return;
    }

    // 优先分配工作给空闲工人
    if (used < k) {
        workers[used] = jobs[idx];
        dfs2(idx+1, jobs, n, workers, k, MAX(workers[used], max), used+1);
        workers[used] = 0;
    }

    for (int i = 0; i < k; i++)
    {
        workers[i] += jobs[idx];
        dfs2(idx+1, jobs, n, workers, k, MAX(workers[i], max), used);
        // 把第idx个工作分配给这个工人后，要拿回这个工作，将这个工作再分配给其他工人，查看最优解
        workers[i] -= jobs[idx];
    }
}

int minimumTimeRequired(int *jobs, int jobsSize, int k)
{
    int workers[k];
    memset(workers, 0, sizeof(workers));
    dfs2(0, jobs, jobsSize, workers, k, 0, 0);
}

int main(int argc, char const *argv[])
{
    // 复合字面量
    printf("%d\n", minimumTimeRequired((int[]){1,2,4,7,8}, 5, 2));
    return 0;
}
