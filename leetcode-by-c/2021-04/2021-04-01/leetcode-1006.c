#include <stdio.h>

/*
int clumsy(int N) {
    int stk[N], top = 0;
    stk[top++] = N;
    N--;

    int index = 0; // 用于控制乘、除、加、减
    while (N > 0) {
        if (index % 4 == 0) {
            stk[top - 1] *= N;
        } else if (index % 4 == 1) {
            stk[top - 1] /= N;
        } else if (index % 4 == 2) {
            stk[top++] = N;
        } else {
            stk[top++] = -N;
        }
        index++;
        N--;
    }

    // 把栈中所有的数字依次弹出求和
    int sum = 0;
    while (top) {
        sum += stk[--top];
    }
    return sum;
}
*/

// 数学方法
int clumsy(int N) {
    if (N == 1) {
        return 1;
    } else if (N == 2) {
        return 2;
    } else if (N == 3) {
        return 6;
    } else if (N == 4) {
        return 7;
    }

    if (N % 4 == 0) {
        return N + 1;
    } else if (N % 4 <= 2) {
        return N + 2;
    } else {
        return N - 1;
    }
}


int main(int argc, char const *argv[])
{   
    /* 
        input: 4 output: 7
     */
    printf("%d\n", clumsy(4));
    return 0;
}

