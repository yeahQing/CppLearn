#include <string>

using namespace std;

class Solution {
public:
    int compare(string version1, string version2) {
        int len1 = 0, len2 = 0, n1 = version1.length(), n2 = version2.length();
        while(len1 < n1 || len2 < n2) {
            unsigned long long num1 = 0, num2 = 0;//初始化为0
            while(len1 < n1 && version1[len1] != '.') {
            //此时如果长度较短的字符串到了尽头，不进入循环，对应数字为0
                num1 = num1 * 10 + (version1[len1++] - '0');
            }
            while(len2 < n2 && version2[len2] != '.') {
                num2 = num2 * 10 + (version2[len2++] - '0');
            }
            if(num1 > num2) {
                return 1;
            } else if(num1 < num2) {
                return -1;
            }
            //指针后移
            ++len1;
            ++len2;
        }
        return 0;
    }
};