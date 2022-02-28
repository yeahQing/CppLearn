#include <stdbool.h>

bool isUgly(int n){
    
    if (n <= 0) return false;

    int a[3] = {2, 3, 5};

    for (int i = 0; i < 3; i++) {
        //a[i] = 2
        while(n % a[i] == 0) n = n /a[i];
    }
    
    return n == 1;
}