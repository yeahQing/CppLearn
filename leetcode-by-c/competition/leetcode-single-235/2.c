#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define ROW 5
// #define COL 2

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(const void *a, const void *b)
{
    if ((*(int**)a)[0] == (*(int**)b)[0])
        return (*(int**)a)[1] - (*(int**)b)[1];
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int* findingUsersActiveMinutes(int** logs, int logsSize, int* logsColSize, int k, int* returnSize){
    int id, time; 
    int key;
    int *res = (int*)calloc(k, sizeof(int));

    //res = malloc(sizeof(int) * k);
    //memset(res, 0, sizeof(int) * k);

    qsort(logs, logsSize, sizeof(logs[0]), comp);

    int i = 0;
    while (i < logsSize) {
        id = logs[i][0];
        key = 0;
        while (i < logsSize && logs[i][0] == id) {
            time = logs[i][1];
            while (i < logsSize && logs[i][0] == id && logs[i][1] == time) {
                i++;
            }
            key++;
        }
        res[key - 1]++;
    }

    *returnSize = k;
    return res;
}

int main(int argc, char const *argv[])
{
    int **logs = NULL;
    int row, col;
    scanf("%d %d", &row, &col);
    // 行数, ROW个int *指针
    logs = (int **)malloc(row * sizeof(int *));
    // 列数，每一行都是一个COL长度的数组
    for (int i = 0; i < row; i++) {
        // 让int * 指针指向一块长度为2 * 4的内存
        logs[i] = (int *)malloc(col * sizeof(int));
    }
    // 直接使用二维数组不行，因为二维数组相当于传入logs(*)[2] != **logs
    // int a[][2] = {{0,5}, {1,2}, {0,2}, {0,5}, {1,3}};
    int k = 4;
    int *returnSize = (int *)malloc(sizeof(int));
    // printf("%ld\n", sizeof(a)/sizeof(a[0]));
    int ** ptr = logs;
    for (int i = 0; i < row; i++){
        // 为每一行的数组赋初值
        memset(logs[i], 0, sizeof(int) * col);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &logs[i][j]);
        }
    }

    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //         printf("%d ", logs[i][j]);
    //     }
    //     printf("\n");
    // }
    // logs = a;
    int * res = findingUsersActiveMinutes(logs, row, logs[0], k, returnSize);
    // printf("%p,%p\n", logs ,&logs);
    for (int i = 0; i < k; i++)
        printf("%d\n", res[i]);
    return 0;
}

