package com.kuaishou.xiaoyao.greedy.p0011;

import static java.lang.Math.min;

/**
 * @author xiaoyao
 */
class Solution {
    public int maxArea(int[] height) {
        int i = 0;
        int j = height.length - 1;
        int max = -1;
        while (i < j) {
            int k = min(height[i], height[j]) * (j - i);
            if (max < k) {
                max = k;
            }
            if (height[i] < height[j]) {
                i++;

            } else {
                j--;
            }
        }
        return max;
    }
}