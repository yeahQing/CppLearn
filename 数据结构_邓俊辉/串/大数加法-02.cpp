#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn = 1000;
char str1[maxn], str2[maxn];
int  a[maxn], b[maxn];
void sum()
{
    //逆序存入
    for(int i = strlen(str1) - 1, j = 0; i >= 0; i--)
        a[j++] = str1[i] - '0';
    for(int i = strlen(str2) - 1, j = 0; i >= 0; i--)
        b[j++] = str2[i] - '0';
    //相加和进位
    for(int i = 0; i < maxn; i++)
    {
        b[i] += a[i];
        //进位操作
        if(b[i] >= 10)
        {
            b[i + 1] += b[i] / 10;
            b[i] %= 10;
        }
    }
    //输出结果
    int i;
    //过滤掉前置0
    for(i = maxn - 1; i >= 0 && b[i] == 0; i--);
    if(i >= 0)
        for( ; i >= 0; i--)
            cout << b[i];
    //如果保存结果的数组中全部为0，上面的操作会过滤掉所有的0，不会有输出，所以这里输出一个0
    else
        cout << 0;
    cout << endl;
}

int main()
{
    //清空数组和字符数组
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(str1, 0, sizeof(str1));
    memset(str2, 0, sizeof(str2));
    //输入
    cin >> str1 >> str2;
    //执行加法计算
    sum();
    system("pause");
    return 0;
}
