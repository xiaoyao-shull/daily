package com.kuaishou.xiaoyao.adhoc;

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

public class Problem4 {

    private static void report(
            int[] a, int[] b, double expected, double actual
    ) {
        if (a == null) {
            System.out.println("A = null");
        } else {
            System.out.print("A = [");
            for (int i : a) {
                System.out.print(" " + i);
            }
            System.out.println(" ]");
        }
        if (b == null) {
            System.out.println("B = null");
        } else {
            System.out.print("B = [");
            for (int i : b) {
                System.out.print(" " + i);
            }
            System.out.println(" ]");
        }
        System.out.println(String.format("expected = %f, actual = %f", expected, actual));
        System.out.println();
    }

    private static void testWithEmptyArrays() {
        int[] empty = {};
        int[] array = {1, 2, 3};
        report(null, array, 2, new Solution().findMedianSortedArrays(
                null, array
        ));
        report(array, null, 2, new Solution().findMedianSortedArrays(
                array, null
        ));
        report(array, empty, 2, new Solution().findMedianSortedArrays(
                array, empty
        ));
        report(empty, array, 2, new Solution().findMedianSortedArrays(
                empty, array
        ));
    }

    private static void testWithUnbalancedArrays() {
        int[] array1 = {1, 2, 3, 4};
        int[] array2 = {5, 6, 7, 8};
        int[] array3 = {1, 2, 3, 4, 5};
        int[] array4 = {6, 7, 8, 9};
        report(array1, array2, 4.5, new Solution().findMedianSortedArrays(array1, array2));
        report(array3, array4, 5, new Solution().findMedianSortedArrays(array3, array4));
    }

    private static void testWithBalancedArrays() {
        int[] array1 = {1, 3, 5, 7};
        int[] array2 = {2, 4, 6, 8};
        int[] array3 = {1, 3, 5, 7, 9};
        int[] array4 = {2, 4, 6, 8};
        report(array1, array2, 4.5, new Solution().findMedianSortedArrays(array1, array2));
        report(array3, array4, 5, new Solution().findMedianSortedArrays(array3, array4));
    }

    private static void testWithSamples() {
        int[] a1 = {1};
        int[] b1 = {2, 3};
        report(a1, b1, 2, new Solution().findMedianSortedArrays(a1, b1));
        report(b1, a1, 2, new Solution().findMedianSortedArrays(b1, a1));

        int[] a2 = {2};
        int[] b2 = {1, 3};
        report(a2, b2, 2, new Solution().findMedianSortedArrays(a2, b2));
        report(b2, a2, 2, new Solution().findMedianSortedArrays(b2, a2));

        int[] a3 = {3};
        int[] b3 = {1, 2};
        report(a3, b3, 2, new Solution().findMedianSortedArrays(a3, b3));
        report(b3, a3, 2, new Solution().findMedianSortedArrays(b3, a3));
    }

    public static void main(String[] args) {
        testWithSamples();
        testWithEmptyArrays();
        testWithUnbalancedArrays();
        testWithBalancedArrays();
    }
}