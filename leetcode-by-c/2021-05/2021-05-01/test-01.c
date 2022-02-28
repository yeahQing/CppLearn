#include <stdio.h>

int main(int argc, char const *argv[])
{   
    int *a, *b;
    int * p[2] = {a, b};
    printf("%p %p\n", p[0], p[1]);
    return 0;
}
