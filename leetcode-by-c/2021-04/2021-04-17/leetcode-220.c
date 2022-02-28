#include <stdio.h>
#include <stdbool.h>
#include "../uthash.h"

struct HashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

int getID(int x, long long w) {
    return x < 0 ? (x + 1ll) / w - 1 : x / w;
}

struct HashTable* query(struct HashTable* hashTable, int x) {
    struct HashTable* tmp;
    HASH_FIND_INT(hashTable, &x, tmp);
    return tmp;
}

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t) {
    struct HashTable* hashTable = NULL;
    for (int i = 0; i < numsSize; i++) {
        long long x = nums[i];
        int id = getID(x, t + 1ll);
        struct HashTable* tmp;
        tmp = query(hashTable, id - 1);
        if (tmp != NULL && fabs(x - tmp->val) <= t) {
            return true;
        }
        tmp = query(hashTable, id + 1);
        if (tmp != NULL && fabs(x - tmp->val) <= t) {
            return true;
        }
        tmp = query(hashTable, id);
        if (tmp != NULL) {
            return true;
        } else {
            tmp = malloc(sizeof(struct HashTable));
            tmp->key = id;
            tmp->val = x;
            HASH_ADD_INT(hashTable, key, tmp);
        }
        if (i >= k) {
            tmp = query(hashTable, getID(nums[i - k], t + 1ll));
            HASH_DEL(hashTable, tmp);
        }
    }
    return false;
}
