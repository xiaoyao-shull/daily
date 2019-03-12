package com.kuaishou.xiaoyao.adhoc.p0004;

import static java.lang.Math.max;
import static java.lang.Math.min;

/**
 * @author xiaoyao
 */
class Solution {

    public double findMedianSortedArrays(int[] a, int[] b) {
        int aLength = getLength(a);
        int bLength = getLength(b);
        if (aLength == 0 && bLength == 0) {
            throw new RuntimeException();
        }
        if (aLength == 0) {
            return getMedian(b);
        }
        if (bLength == 0) {
            return getMedian(a);
        }

        if (aLength > bLength) {
            int[] t = a;
            a = b;
            b = t;
            int tLength = aLength;
            aLength = bLength;
            bLength = tLength;
        }

        int length = (aLength + bLength + 1) / 2;
        int aCountMin = 0;
        int aCountMax = aLength;
        boolean isOdd = (aLength + bLength) % 2 == 1;
        while (true) {
            int aCount = (aCountMin + aCountMax) / 2;
            int bCount = length - aCount;
            if (aCount > 0 && a[aCount - 1] > b[bCount]) {
                aCountMax = aCount;
                continue;
            }
            if (aCount < aLength && b[bCount - 1] > a[aCount]) {
                aCountMin = aCount + 1;
                continue;
            }
            if (aCount == 0) {
                if (bCount < bLength) {
                    return isOdd
                            ? b[bCount - 1]
                            : (b[bCount - 1] + min(b[bCount], a[0])) / 2.0;

                } else {
                    return isOdd
                            ? b[bCount - 1]
                            : (b[bCount - 1] + a[0]) / 2.0;
                }
            }
            if (aCount == aLength) {
                if (bCount > 0) {
                    return isOdd
                            ? max(a[aCount - 1], b[bCount - 1])
                            : (max(a[aCount - 1], b[bCount - 1]) + b[bCount]) / 2.0;

                } else {
                    return isOdd
                            ? a[aCount - 1]
                            : (a[aCount - 1] + b[0]) / 2.0;
                }
            }
            int x = a[aCount - 1];
            int y = b[bCount - 1];
            int xx = a[aCount];
            int yy = b[bCount];
            return isOdd ? max(x, y) : (max(x, y) + min(xx, yy)) / 2.0;
        }
    }

    private double getMedian(int[] a) {
        return a.length % 2 == 0
                ? (a[a.length / 2] + a[a.length / 2 - 1]) / 2.0
                : a[a.length / 2];
    }

    private int getLength(int[] a) {
        return a == null ? 0 : a.length;
    }
}
