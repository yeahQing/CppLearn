
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


/**
字符串匹配穷举算法

长度为n的文本串,长度为m的模式串,模式串要和文本串中长度为m的子串比较n-m+1次=n-(m-1)次
已知长度为n的文本串,长度为1的模式串，需要比较n次=n-(1-1)
已知长度为n的文本串,长度为2的模式串，需要比较n-1次=n-(2-1)
已知长度为n的文本串,长度为3的模式串，需要比较n-2次=n-(3-1)
那么长度为n的文本串,长度为m的模式串，需要比较n-(m-1)=n-m+1次

因此，需要遍历n-m+1次文本串，分别与模式串进行比较

*/

/**
 * 
 * @param text
 * @param pattern
 * 
*/

int patternCounting(string& text, string& pattern)
{
    int n = text.size();
    int m = pattern.size();
    int i = 0;
    int cnt = 0;

    for (; i < n-m+1; i++) // 遍历n-m+1, 因为i是从0开始的，因此不能有等号
    {
        int j = 0;
        for (; j < m; j++) // 每次都遍历整个模式串，j与i+j个字符作比较
        {
            if (text[i+j] != pattern[j])
            {
                break;
            }
        }
        if (j >= m) break; // 如果j==m代表m个字符都和文本串匹配
    }
    
    return i;

}

int patternMatching(const char* P, const char* T)
{
    size_t n = strlen(T), i = 0;
    size_t m = strlen(P), j = 0;

    while (j < m && i < n)
    {
        if (P[j] == T[i])
        {
            i++; j++;
        }
        else
        {
            i -= j-1;
            j = 0;
        }
    }
    return i - j;
}

int main()
{
    string text = "abab";
    string pattern = "abc";

    int ret = patternCounting(text, pattern);

    if (ret + pattern.size() > text.size())
    {
        cout << "false" << endl;    
    }
    else
    {
        cout << "true" << endl;
    }

    

    const char* t = "ababc";
    const char* p = "abc";

    cout << patternMatching(p, t) << endl;

    cout << text.find(pattern) << endl;

    return 0;
}