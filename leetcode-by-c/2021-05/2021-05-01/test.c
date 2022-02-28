#include <stdio.h>

int main(int argc, char const *argv[])
{
    int zippo[2][2] = {1, 2, 3, 4};
    int a[2] = {1, 2};
    printf("a = %p, &a = %p, &a[0] = %p\n", a, &a, &a[0]);
    printf("zippo=%p\n&zippo[0]=%p\n", zippo, &zippo[0]);
    printf("zippo[0]=%p\n&zippo[0][0]=%p\n", zippo[0], &zippo[0][0]);
    printf("zippo+1 = %p\nzippo[0]+1=%p\n", zippo+1, zippo[0]+1);
    return 0;
}
