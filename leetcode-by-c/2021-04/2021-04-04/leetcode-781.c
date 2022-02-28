
int cmp(int* a, int* b){
    return *a - *b;
}

int numRabbits(int* answers, int answersSize){
    qsort(answers, answersSize, sizeof(answers[0]), cmp);
    int ans = 0;
    for (int i = 0; i < answersSize; i++) {
        int cnt = answers[i];
        ans += cnt + 1;
        int k = cnt;
        while (k-- > 0 && i+1 < answersSize && answers[i] == answers[i+1]) i++;
    }
    return ans;
}