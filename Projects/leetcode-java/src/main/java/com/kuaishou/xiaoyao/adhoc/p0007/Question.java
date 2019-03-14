package com.kuaishou.xiaoyao.adhoc.p0007;

/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *   Input: 123
 *   Output: 321
 *
 * Example 2:
 *
 *   Input: -123
 *   Output: -321
 *
 * Example 3:
 *
 *   Input: 120
 *   Output: 21
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers within the 32-bit
 * signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your
 * function returns 0 when the reversed integer overflows.
 * @author xiaoyao
 */
public class Question {

    private static void test(int x, int y) {
        System.out.println("Input   : " + x);
        System.out.println("Expected: " + y);
        System.out.println("Actual  : " + new Solution().reverse(x));
        System.out.println();
    }

    public static void main(String[] args) {
        test(0, 0);
        test(123, 321);
        test(-123, -321);
        test(1999999999, 0);
        test(120, 21);
        test(-2147483648, 0);
        test(2147483647, 0);
    }
}
