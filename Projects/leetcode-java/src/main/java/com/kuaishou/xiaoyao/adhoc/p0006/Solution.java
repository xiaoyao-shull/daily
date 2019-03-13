package com.kuaishou.xiaoyao.adhoc.p0006;

/**
 * @author xiaoyao
 */
class Solution {

    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return new String(s.toCharArray());
        }
        char[] a = s.toCharArray();
        char[] b = new char[a.length];

        int gap = numRows * 2 - 2;
        int i = 0;

        for (int j = 0; j < a.length; j += gap) {
            b[i++] = a[j];
        }

        for (int j = gap - 2, k = 1; j > 0; j -= 2, k++) {
            int x = k;
            while (true) {
                if (x >= a.length) {
                    break;
                }
                b[i++] = a[x];
                x += j;

                if (x >= a.length) {
                    break;
                }
                b[i++] = a[x];
                x += (gap - j);
            }
        }

        for (int j = numRows - 1; j < a.length; j += gap) {
            b[i++] = a[j];
        }

        return new String(b);
    }
}
