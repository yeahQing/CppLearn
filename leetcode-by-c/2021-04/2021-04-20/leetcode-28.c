#include <stdbool.h>

int strStr(char * haystack, char * needle){
    int n = strlen(haystack), m = strlen(needle);
    bool flag = true;
    for (int i = 0; i + m <= n; i++) {
        flag = true;
        for (int j = 0; j < m; j++) {
            if (haystack[i+j] != needle[j]) {
                flag = false;
                break;
            }
        }
        if (flag) return i;
    }
    return -1;
}