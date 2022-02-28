int computeXor(int n) {
    switch(n%4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        // case 3: n = 0; break;
    }
    // n%4 == 0
    // 为什么不能返回n
    return 0;
}

int xorOperation(int n, int start){
    int s = start >> 1; // s = start/2
    // 当n和start同时为1时, 最后一位才为1
    int b0 = n & start & 1;
    int ret = computeXor(s-1) ^ computeXor(s + n - 1);
    // return ret << 1 | b0;
    // 优先级
    return (ret << 1) + b0;
}