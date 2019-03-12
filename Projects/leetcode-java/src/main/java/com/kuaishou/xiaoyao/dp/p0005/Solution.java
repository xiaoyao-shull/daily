package com.kuaishou.xiaoyao.dp.p0005;

/**
 * @author xiaoyao
 */
class Solution {
    public String longestPalindrome(String s) {
        char[] a = s.toCharArray();
        char[] b = new char[a.length];
        for (int i = 0; i < a.length; ++i) {
            b[b.length - 1 - i] = a[i];
        }

        int[][] state = new int[a.length][a.length];
        int p = 0;
        int q = 0;
        int r = 0;
        for (int i = 0; i < a.length; ++i) {
            for (int j = 0; j < b.length; ++j) {
                if (a[i] == b[j]) {
                    if (i == 0 || j == 0) {
                        state[i][j] = 1;

                    } else {
                        state[i][j] = 1 + state[i - 1][j - 1];
                    }

                    if (r < state[i][j] && i + j + 2 - state[i][j] == a.length) {
                        r = state[i][j];
                        p = i - r + 1;
                        q = i + 1;
                    }

                } else {
                    state[i][j] = 0;
                }
            }
        }
        return s.substring(p, q);
    }
}
