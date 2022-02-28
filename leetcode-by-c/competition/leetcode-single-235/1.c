/* 截断句子 */
char * truncateSentence(char * s, int k){
    int i = 0;
    int flag = 0;
    while (k > 0) {
        if (s[i] == ' ') k--;
        i++;
        if (s[i] == '\0') {
            flag = 1;
            break;
        }
    }
    if (!flag) s[i-1] = '\0';
    return s;
}

char * truncateSentence(char * s, int k){
    int len = strlen(s);
    int cnt = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (s[i] == ' ' && (++cnt == k)) { /* 空格够了, 就添加结束符 */
            s[i] = '\0';
            break;
        }
    }
    return s;
}
