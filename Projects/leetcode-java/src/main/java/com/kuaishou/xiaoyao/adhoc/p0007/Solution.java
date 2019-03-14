package com.kuaishou.xiaoyao.adhoc.p0007;

/**
 * @author xiaoyao
 */
class Solution {
    public int reverse(int x) {
        if (x == 0 || x == Integer.MIN_VALUE) {
            return 0;
        }
        if (x < 0) {
            return -reverse(-x);
        }
        while (x % 10 == 0) {
            x /= 10;
        }
        long y = 0;
        while (x > 0) {
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        if (y > Integer.MAX_VALUE) {
            return 0;

        } else {
            return (int) y;
        }
    }
}