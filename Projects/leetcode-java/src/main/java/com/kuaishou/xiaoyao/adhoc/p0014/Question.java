package com.kuaishou.xiaoyao.adhoc.p0014;

import static java.lang.String.join;

/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 *
 *   Input: ["flower","flow","flight"]
 *   Output: "fl"
 *
 * Example 2:
 *
 *   Input: ["dog","racecar","car"]
 *   Output: ""
 *   Explanation: There is no common prefix among the input strings.
 *
 * Note:
 *
 *   All given inputs are in lowercase letters a-z.
 *
 * @author xiaoyao
 */
@SuppressWarnings("Duplicates")
public class Question {

    private static void test(String[] input, String expected) {
        String actual = new Solution().longestCommonPrefix(input);
        System.out.println("input   : " + join(", ", input));
        System.out.println("expected: " + expected);
        System.out.println("actual  : " + actual);
        System.out.println();
    }

    public static void main(String[] args) {
        test(new String[]{"flower", "flow", "flight"}, "fl");
        test(new String[]{"dog", "racecar", "car"}, "");
    }
}
