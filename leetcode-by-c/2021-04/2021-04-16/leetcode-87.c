#include <stdio.h>
#include <stdbool.h>
#include "../uthash.h"


struct HashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

void modifyHashTable(struct HashTable** hashTable, int x, int inc) {
    struct HashTable* tmp;
    HASH_FIND_INT(*hashTable, &x, tmp);
    if (tmp == NULL) {
        tmp = malloc(sizeof(struct HashTable));
        tmp->key = x;
        tmp->val = inc;
        HASH_ADD_INT(*hashTable, key, tmp);
    } else {
        tmp->val += inc;
    }
}

bool checkHashTable(struct HashTable** hashTable) {
    struct HashTable *iter, *tmp;
    HASH_ITER(hh, *hashTable, iter, tmp) {
        if (iter->val) {
            return false;
        }
    }
    return true;
}

void freeHashTable(struct HashTable** hashTable) {
    struct HashTable *iter, *tmp;
    HASH_ITER(hh, *hashTable, iter, tmp) {
        HASH_DEL(*hashTable, iter);
        // HASHTABLE不会自动free, 需要自行free
        free(iter);
    }
}

/* 
great
rgeat
 */
bool equals(char* s1, char* s2, int i1, int i2, int len) {
    for (int i = 0; i < len; i++) {
        if (s1[i + i1] != s2[i + i2]) {
            return false;
        }
    }
    return true;
}

// 记忆化搜索存储状态的数组
// -1 表示 false，1 表示 true，0 表示未计算
int memo[30][30][31];

// 第一个字符串从 i1 开始，第二个字符串从 i2 开始，子串的长度为 length，是否和谐
bool dfs(char* s1, char* s2, int i1, int i2, int length) {
    // memo[0][0][5] = 0 false
    if (memo[i1][i2][length]) {
        return memo[i1][i2][length] == 1;
    }

    // 判断两个子串是否相等
    // i1 = 0, i2 = 0, length = 5 
    if (equals(s1, s2, i1, i2, length)) {
        memo[i1][i2][length] = 1;
        return true;
    }

    // 判断是否存在字符 c 在两个子串中出现的次数不同
    struct HashTable* hashTable = NULL;

    for (int i = i1; i < i1 + length; ++i) {
        modifyHashTable(&hashTable, s1[i], 1);
    }
    for (int i = i2; i < i2 + length; ++i) {
        modifyHashTable(&hashTable, s2[i], -1);
    }
    if (!checkHashTable(&hashTable)) {
        memo[i1][i2][length] = -1;
        return false;
    }
    freeHashTable(&hashTable);

    // 枚举分割位置
    for (int i = 1; i < length; ++i) {
        // 不交换的情况
        if (dfs(s1, s2, i1, i2, i) && dfs(s1, s2, i1 + i, i2 + i, length - i)) {
            memo[i1][i2][length] = 1;
            return true;
        }
        // 交换的情况
        if (dfs(s1, s2, i1, i2 + length - i, i) && dfs(s1, s2, i1 + i, i2, length - i)) {
            memo[i1][i2][length] = 1;
            return true;
        }
    }

    memo[i1][i2][length] = -1;
    return false;
}

bool isScramble(char* s1, char* s2) {
    // memo数组初始化为0
    memset(memo, 0, sizeof(memo));
    // 递归深度优先搜索
    return dfs(s1, s2, 0, 0, strlen(s1));
}

int main(int argc, char const *argv[])
{
    char s1[] = "great";
    char s2[] = "rgeat";
    char ret[5];
    strcpy(ret, isScramble(s1, s2) == 1 ? "true" : "false");
    printf("%s\n", ret);
    return 0;
}
