/* leetcode 面试题 17.21. 直方图的水量 */

/* 动态规划 时间复杂度 O(n) 空间复杂度 O(n) */
int trap(int* height, int heightSize) {
    int n = heightSize;
    if (n == 0) {
        return 0;
    }
    int leftMax[n];
    memset(leftMax, 0, sizeof(leftMax));
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = fmax(leftMax[i - 1], height[i]);
    }

    int rightMax[n];
    memset(rightMax, 0, sizeof(rightMax));
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = fmax(rightMax[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += fmin(leftMax[i], rightMax[i]) - height[i];
    }
    return ans;
}

/* 单调栈 时间复杂度 O(n) 空间复杂度 O(n) */
int trap(int* height, int heightSize) {
    int n = heightSize;
    if (n == 0) {
        return 0;
    }
    int ans = 0;
    int stk[n], top = 0;
    for (int i = 0; i < n; ++i) {
        while (top && height[i] > height[stk[top - 1]]) {
            int stk_top = stk[--top];
            if (!top) {
                break;
            }
            int left = stk[top - 1];
            int currWidth = i - left - 1;
            int currHeight = fmin(height[left], height[i]) - height[stk_top];
            ans += currWidth * currHeight;
        }
        stk[top++] = i;
    }
    return ans;
}

/* 双指针 时间复杂度 O(n) 空间复杂度 O(1) */
int trap(int* height, int heightSize) {
    int ans = 0;
    int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0;
    while (left < right) {
        leftMax = fmax(leftMax, height[left]);
        rightMax = fmax(rightMax, height[right]);
        if (height[left] < height[right]) {
            ans += leftMax - height[left];
            ++left;
        } else {
            ans += rightMax - height[right];
            --right;
        }
    }
    return ans;
}

