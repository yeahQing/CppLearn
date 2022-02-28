#include <stdio.h>
#include <time.h>

int n, pd[100], used[100];
clock_t start, end;


void print() {
    for (int i = 1; i <= n; i++) printf("%d", used[i]);
    printf("\n");
}

void dfs(int k) {

    if (k == n) {
        // print();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!pd[i]) {
            pd[i] = 1;
            used[k+1] = i;
            dfs(k+1);
            pd[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    start = clock();
    printf("程序启动，start_t = %ld\n", start);
    dfs(0);
    end = clock();
    printf("程序启动，end = %ld\n", end);
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("CPU 占用的总时间：%fs\n", duration);
    printf("程序退出...\n");
    // 3 * 60 + 52 = 180 + 52 = 232s
    return 0;
}
