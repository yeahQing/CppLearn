#include <stdio.h>
#include <stdbool.h>

bool frogJump(int* stones, int stonesSize, int index, int step) {
    for (int i = index+1; i < stonesSize; i++) {
        int gap = stones[i] - stones[index];
        if (gap <= step+1 && gap >= step-1) {
            if (frogJump(stones, stonesSize, i, gap)) return true;
        }
        if (gap > step+1) break;
        if (gap < step-1) continue;
    }
    if (index == stonesSize-1) return true;
    return false;
}

int main(int argc, char const *argv[])
{
    /* code */
    int stones[] = {0,1,3,5,6,8,12,17};
    printf("%d\n", frogJump(stones, sizeof(stones)/sizeof(int), 0, 1));

    return 0;
}
