/* alt + shift + A 多行注释 multiple line comment */
/* 前缀树 */
#include <stdio.h>   /* printf NULL */
#include <stdbool.h> /* bool */
#include <stdlib.h>  /* malloc */
#include <string.h> /* memset */

/* 只存储小写字母 */
#define MAX 26

typedef struct trie
{
    bool isWord;
    struct trie *next[MAX];
} Trie;

/** Initialize your data structure here. */

Trie *trieCreate()
{
    Trie *root = (Trie *)malloc(sizeof(Trie));
    memset(root, 0, sizeof(Trie));
    /* 
        for(int i=0;i<MAXN;i++)
            root->next[i]=NULL;
     */
    root->isWord = false;
    return root;
}

/** Inserts a word into the trie. */
void trieInsert(Trie *obj, char *word)
{
    while (*word)
    {
        /* 如果当前节点的子节点没有某个字母的分支，那么就创建这个分支 */
        if (!obj->next[*word - 'a'])
            obj->next[*word - 'a'] = trieCreate();
        /* 如果当前节点的某个字母的子节点存在，那么节点移动到子节点 */
        obj = obj->next[*word - 'a'];
        word++;
    }
    /* 单词遍历完成，设置存在单词为true */
    obj->isWord = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie *obj, char *word)
{
    while (*word)
    {
        /* code */
        if (!obj->next[*word - 'a'])
            return false;
        obj = obj->next[*word - 'a'];
        word++;
    }
    return obj->isWord;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie *obj, char *prefix)
{
    while (*prefix)
    {
        if (!obj->next[*prefix - 'a'])
            return false;
        obj = obj->next[*prefix - 'a'];
        prefix++;
    }
    return true;
}

void trieFree(Trie *obj)
{
    /* 如果节点为空就返回 */
    if (!obj) return;
    for (int i = 0; i < MAX; i++) {
        if (obj->next[i]) trieFree(obj->next[i]);
    }
    free(obj);
}

int main(void)
{
    Trie *obj = trieCreate();

    char word[] = "apple";
    char prefix[] = "sss";
    char res[6];
    
    trieInsert(obj, word);

    bool isExist;

    isExist = trieSearch(obj, word);
    (isExist) ? sprintf(res, "%s", "true") : sprintf(res, "%s", "false");
    printf("%s exist : %s\n", word, res);
    
    isExist = trieStartsWith(obj, prefix);
    (isExist) ? sprintf(res, "%s", "true") : sprintf(res, "%s", "false");
    printf("%s exist : %s\n", prefix, res);

    return 0;
}
