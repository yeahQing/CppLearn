int shipWithinDays(int* weights, int weightsSize, int D) {
    // 确定二分查找左右边界
    int left = 0, right = 0;
    for (int i = 0; i < weightsSize; i++) {
        left = fmax(left, weights[i]);
        right += weights[i];
    }
    while (left < right) {
        int mid = (left + right) / 2;
        // need 为需要运送的天数
        // cur 为当前这一天已经运送的包裹重量之和
        int need = 1, cur = 0;
        for (int i = 0; i < weightsSize; i++) {
            if (cur + weights[i] > mid) {
                ++need;
                cur = 0;
            }
            cur += weights[i];
        }
        if (need <= D) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}