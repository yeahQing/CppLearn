#include <stdio.h>
#include <stdlib.h>
#include "../uthash.h"

typedef struct HashTable {
    int key;
    int val;
    struct UT_hash_handle hh;
} HashTable;

int singleNumber(int* nums, int numsSize){
    HashTable * hashTable = NULL;

    for (unsigned int i = 0; i < numsSize; i++) {
        HashTable * tmp;
        HASH_FIND_INT(hashTable, &nums[i], tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(HashTable));
            tmp->key = nums[i];
            tmp->val = 1;
            /* HASH_ADD_INT之前需要先使用HASH_FIND_INT判断有没有这个键 */
            HASH_ADD_INT(hashTable, key, tmp);
        }
        else tmp->val++;
    }

    int ans = 0;

    HashTable *iter, *tmp;
    HASH_ITER(hh, hashTable, iter, tmp) {
        if (iter->val == 1) {
            ans = iter->key;
            break;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    int nums[] = {2, 2, 2, 3};
    printf("%d\n", singleNumber(nums, sizeof(nums)/sizeof(nums[0])));
    return 0;
}
