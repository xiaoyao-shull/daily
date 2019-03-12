package com.kuaishou.xiaoyao.dp.p0005;

/**
 * Given a string s, find the longest palindromic substring in s.
 * You may assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *   Input: "babad"
 *   Output: "bab"
 *   Note: "aba" is also a valid answer.
 *
 * Example 2:
 *
 *   Input: "cbbd"
 *   Output: "bb"
 *
 * @author xiaoyao
 */
public class Question {
    public static void main(String[] args) {
        test("aacdefcaa");
        //testWithSamples();
    }

    private static void testWithSamples() {
        test("babad");
        test("cbbd");
    }

    private static void test(String string) {
        System.out.println("Input: " + string);
        System.out.println("Output: " + new Solution().longestPalindrome(string));
        System.out.println();
    }
}
