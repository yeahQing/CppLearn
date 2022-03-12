#include <iostream>
#include "string.h"
#include <string>

using namespace std;

// kmp
// buildNext

/*
要求next数组（有些叫next-val数组）：
1.必须先求模式串S 每一个字符前面的那个字符串的最大公共前后缀长度(自匹配前后缀)，
将这一系列长度存成一个数组，求出来的每个长度其实就是和模式串每一个对应位置上做比较的下标
例如：模式串是ABACABC的最长公共前后缀长度数组为：
我们将最长公共前后缀长度记作LCPSF，
现在从模式串第一个字符A开始，A的前面字符串为null，所以A之前的子串的LCPSF是0；
来到B，B的前面字符串是A，A是单独的字符不存在公共前后缀，所以长度也是0；
来到A，A前面的子串是AB，LCPSF为0；
来到C，C前面的子串是ABA，LCPSF为1；
来到A，A前面的子串是ABAC，LCPSF为0；
来到B，B之前子串为ABACA，LCPSF为1；
来到C，C前面子串为ABACAB，LCPSF为2；
到此这个最长公共前后缀数组就出来了=【0,0,0,1,0,1,2】
因为下标是从1开始的，所以+1
将这个数组从第二个值开始每个值加1=【0,1,1,2,1,2,3】就是将要和子串对应位置比较的下标

2.求得模式串最长公共前后缀的数组T【n】后，把模式串每个位置上的字符与这个数组存的下标对应字符作比较：
上面求出了下标数组【0,1,1,2,1,2,3】现在来和模式串ABACABC每个位置作比较求最终next-val数组：
next-val数组第一个数直接为0。
next-val第二数：模式串第二个字符为B，对应的下标数组第二个数是1，
那就是将模式串的第1个字符和B相比较，A!=B,所以直接将下标数组第二个数1作为next-val数组第二个数的值
第三个数：模式串第三个字符为A，对应下标数组第三个数为1，取其作为下标，找到模式串第1个字符为A，A=A，
那取next-val的第一个数做为next-val第三个数的值，也就是0
。。。。。以此类推，模式串每一个位置的字符和对应下标位置的数相等就取next-val中对应的数填到next-val中当前位置，不等就直接取当前下标数组的值填到next-val当前位置中
注意，这里所有序号，包括模式串和下标数组的数，第一个位置都是1，而不是常用的0开始
序号：     1 2 3 4 5 6 7
模式串     A B A C A B C
下标数组   0 1 1 2 1 2 3
next-val  0 1 0 2 0 1 0

序号：     0 1 2 3 4 5 6
模式串     A B A C A B C
next      -1,0,0,1,0,1,2
next-val  -1,0,-1,1,-1,0,2

模式串     0 0 0 0 1 0
next      -1 0 1 2 3 0
next-val  -1 -1 -1 -1 3 -1

*/

int *buildNext(const char *P)
{
    size_t m = strlen(P);
    int *N = new int[m];
    int j = 0;
    // 模式串指针
    int t = N[0] = -1;

    while (j < m - 1)
    {
        if (t < 0 || P[j] == P[t])
        {
            j++;
            t++;
            // next[j] = t;
            // 如果不同t不变，如果相同t=next[t]
            N[j] = (P[t] != P[j] ? t : N[t]);
        }
        else
        {
            // t = next[t]
            t = N[t];
        }
    }
    return N;
}

int match(const char *P, const char *T)
{
    int *next = buildNext(P);
    int n = (int)strlen(T), i = 0;
    int m = (int)strlen(P), j = 0;

    while (j < m && i < n)
    {
        if (j < 0 || P[j] == T[i])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    delete[] next;
    return i - j;
}

int kmp(string s, string t)
{
    // write code here
    // s是模板串 t是文本串
    int n = s.size(), m = t.size();
    s = ' ' + s, t = ' ' + t;
    // next数组
    int ne[n + 10];
    memset(ne, 0, sizeof ne);
    // 根据模板串构建next表
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && s[j + 1] != s[i])
            j = ne[j];
        if (s[j + 1] == s[i])
            j++;
        ne[i] = j;
    }
    int ans = 0;
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[j + 1] != t[i])
            j = ne[j];
        if (s[j + 1] == t[i])
            j++;
        if (j == n)
            ans++;
    }
    return ans;
}


int kmp(const char* t, const char* p)
{
    int n = (int)strlen(t), m = (int)strlen(p);

    // 构建next表
    int* next = new int[m];
    // 首字符不相等为-1哨兵
    // 长度为0的模式串是空串，假设其中最大长度的相匹配的前缀和后缀为-1
    next[0] = -1;
    int i = 0, j = next[0]; 
    // 构建剩余的m-1个状态，j=1...m-1分别
    while (i < m-1)
    {
        if (j < 0 || p[i] == p[j]) {
            i++; j++;
            // next[i] = j;
            // N[j] = (P[t] != P[j] ? t : N[t]);
            // 构建nextval表，如果j下标对应的元素值等于当前i下标对应的元素值，就将当前next_val值替换为对应j下标的next_val值
            if (p[i] != p[j])
            {
                next[i] = j;
            }
            else
            {
                next[i] = next[j];
            }
        }
        else{
            j = next[j];
        }
    }

    for (int i  = 0; i < m; i++)
        cout << next[i] << " ";

    cout << endl;

    // 根据next表进行模式匹配
    // n是文本串的长度, m是模式串的长度
    i = 0, j = 0;
    int ans = 0;
    while (i < n)
    {

        if (j < 0 || t[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }

        if (j == m) {
            ans++;
            j = 0;
        }
    }
    
    delete [] next;


    return ans;

}

int main()
{

    const char *t = "cabcabcabc";
    const char *p = "abc";

    // cout << match(p, t) << endl;
    cout << kmp(t, p) << endl;

    return 0;
}