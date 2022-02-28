#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int numDecodings(char * s){
    int n = strlen(s);
    int f[n+1];
    memset(f, 0, sizeof(f));
    f[0] = 1;

    for (int i = 1; i <= n; i++) {
        if (s[i-1] - '0' != 0) {
            f[i] += f[i-1];
        }
        if (i > 1 && s[i-2] != '0' && 10*(s[i-2] - '0')+(s[i-1] - '0') <= 26) {
            f[i] += f[i-2];
        }
    }

    return f[n];
}

int main(int argc, char const *argv[])
{
    char *s = "226";


    int ret = numDecodings(s);
    
    printf("%d\n", ret);
    return 0;
}
