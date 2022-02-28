#include <stdio.h>
#include <string.h>
#include "../uthash.h"

typedef struct HashTable {
    int key; /* key 键 */
    char val[10]; /* val 值 */
    UT_hash_handle hh;
} HashTable;

void delete_all(HashTable ** hashTable) {
    HashTable *item, *tmp;
    HASH_ITER(hh, *hashTable, item, tmp) {
        HASH_DEL(*hashTable, item);
        free(item);
    }
}

void add_item(HashTable ** hashTable, int key, char * val) {
    HashTable *tmp;
    HASH_FIND_INT(*hashTable, &key, tmp); // 执行HASH_ADD 时必须先执行这个，确保键唯一
    /* 不存在则返回NULL, 如果不存在则把键值对加入HashTable */
    if (tmp == NULL) {
        tmp = malloc(sizeof(HashTable));
        tmp->key = key;
        strcpy(tmp->val, val);
        // hashTable是结构体指针
        // 执行完函数后会自动free临时结构体
        HASH_ADD_INT(*hashTable, key, tmp);
    }
}

void print_item(HashTable ** hashTable) {
    HashTable *tmp;

    for (tmp = *hashTable; tmp != NULL; tmp = tmp->hh.next) {
        printf("user id %d: name %s\n", tmp->key, tmp->val);
    }

}

int main(int argc, char const *argv[])
{
    HashTable* hashTable = NULL;
    int id = 1;
    char name[] = "Jack";
    add_item(&hashTable, id, name);
    print_item(&hashTable);
    delete_all(&hashTable);
    return 0;
}
