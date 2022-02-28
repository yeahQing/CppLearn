#include <stdio.h>
#include <limits.h>
#include "../uthash.h"

/* 哈希表做法 */
typedef struct GAP {
    int key;
    int val;
    UT_hash_handle hh;
}GAP;

int leastBricks(int** wall, int wallSize, int* wallColSize){
    GAP * gap = NULL; 
    for (int i = 0; i < wallSize; i++) {
        int len = 0;
        for (int j = 0; j < wallColSize[i]-1; j++) {
            len += wall[i][j];
            GAP * tmp;
            HASH_FIND_INT(gap, &len, tmp);
            if (tmp == NULL) {
                tmp = (GAP *)malloc(sizeof(GAP));
                tmp->key = len;
                tmp->val = 1;
                HASH_ADD_INT(gap, key ,tmp);
            } else {
               tmp->val++; 
            }
        }
    }

    GAP *iter, *tmp;
    int max = 0;
    HASH_ITER(hh, gap, iter, tmp){
        max = fmax(max, iter->val);
    }
    return wallSize-max;
}

// 这个方法时间复杂度过高，超时
/* int sum(int *wall, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += wall[i];
    }
    return total;
}

int leastBricks(int** wall, int wallSize, int* wallColSize){
    int len = 0;
    int width = sum(wall[0], wallColSize[0]);
    int height = wallSize;

    if (width < 2) return height;
    
    int gap[height][width];
    for (int row = 0; row < height; row++) {
        len = 0;
        for (int col = 0, i = 1; col < wallColSize[row]; i++) {
            len += wall[row][col];
            if (i == len) {
                gap[row][i-1] = 0;
                col++;
            } else {
                gap[row][i-1] = 1;
                len -= wall[row][col];
            }
        }
    }

    int min = INT_MAX;

    for (int col = 0; col < width-1; col++) {
        int cur = 0;
        for (int row = 0; row < height; row++) {
            cur += gap[row][col];
        }       
        min = fmin(min, cur);
    }
    return min;
} */
