package com.kuaishou.xiaoyao.adhoc.p0009;

/**
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the
 * same backward as forward.
 *
 *
 * Example 1:
 *
 *   Input: 121
 *   Output: true
 *
 * Example 2:
 *
 *   Input: -121
 *   Output: false
 *   Explanation: From left to right, it reads -121. From right to left, it becomes 121-.
 *                Therefore it is not a palindrome.
 * Example 3:
 *
 *   Input: 10
 *   Output: false
 *   Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 *
 * @author xiaoyao
 */
@SuppressWarnings("Duplicates")
public class Question {

    private static void test(int input, boolean expected) {
        boolean actual = new Solution().isPalindrome(input);
        System.out.println("input   : " + input);
        System.out.println("expected: " + expected);
        System.out.println("actual  : " + actual);
        System.out.println();
    }

    public static void main(String[] args) {
        test(121, true);
        test(-121, false);
        test(10, false);
    }
}
