package com.kuaishou.xiaoyao.adhoc.p0004;

/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Example 1:
 *
 *   nums1 = [1, 3]
 *   nums2 = [2]
 *
 *   The median is 2.0
 *
 * Example 2:
 *
 *   nums1 = [1, 2]
 *   nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 * @author xiaoyao
 */
public class Question {

    public static void main(String[] args) {
        testWithSamples();
        testWithEmptyArrays();
        testWithUnbalancedArrays();
        testWithBalancedArrays();
    }

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
}