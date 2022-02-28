#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false = 0,
    true = !false
} bool;


bool bakctrack(int *jobs, int n, int *workers, int k, int idx, int limit) {
    if (idx >= n) return true;
    // 取出当前的工作
    int cur = jobs[idx];
    // 分配工作
    for (int i = 0; i < k; i++) {
        // 如果当前工作可以分配给这个工人
        if (workers[i] + cur <= limit) {
            workers[i] += cur;
            if (bakctrack(jobs, n, workers, k, idx+1, limit)) {
                return true;
            }
            // 不懂这个地方
            workers[i] -= cur;
        }
        // 如果当前工作不能分配给这个工人,那么其他工人也一定不能分配
        if (workers[i] == 0 || workers[i]+cur == limit) break;
    }
    return false;
}


bool check(int *jobs, int jobsSize, int k, int limit) {
    // 定义一个VLA变长数组, 表示第k个工人的工作时间
    int workers[k];
    // 0x3f3f3f3f memset按字节初始化数组, int有4个字节, 那每个字节的8位都会赋值相同的值
    memset(workers, 0, sizeof(workers)); 
    return bakctrack(jobs, jobsSize, workers, k, 0, limit);
}

int sum(int* jobs, int n) {
    int ret = 0;
    for (int i = 0; i < n; i++) ret += jobs[i];
    return ret;
}   

int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int minimumTimeRequired(int* jobs, int jobsSize, int k){
    // 从大到小排序，优先处理工作量的工作，防止最后处理不了工作量的任务
    qsort(jobs, jobsSize, sizeof(jobs[0]), cmp);
    // 二分的边界 最小值是最大的工作， 最大值是全部工作的和
    int l = jobs[0], r = sum(jobs, jobsSize);
    // 二分
    while (l < r) {
        int mid = (l+r) >> 1;
        // 如果中值可以分配，那么就继续找有没有更小的分配方案
        if (check(jobs, jobsSize, k, mid)) {
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    return l;
}

int main(int argc, char const *argv[])
{
    // 复合字面量
    printf("%d\n", minimumTimeRequired((int[]){3, 2, 3}, 3, 3));
    return 0;
}
