package com.kuaishou.xiaoyao.adhoc.p0006;

/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 *
 *   P   A   H   N
 *   A P L S I I G
 *   Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 *   string convert(string s, int numRows);
 *
 * Example 1:
 *
 *   Input: s = "PAYPALISHIRING", numRows = 3
 *   Output: "PAHNAPLSIIGYIR"
 *
 * Example 2:
 *
 *   Input: s = "PAYPALISHIRING", numRows = 4
 *   Output: "PINALSIGYAHRPI"
 *   Explanation:
 *
 *   P     I    N
 *   A   L S  I G
 *   Y A   H R
 *   P     I
 *
 * @author xiaoyao
 */
public class Question {

    private static void test(String input, int rowCount, String expected) {
        String actual = new Solution().convert(input, rowCount);
        System.out.println("Input:    " + input + " (" + rowCount + ")");
        System.out.println("Expected: " + expected);
        System.out.println("Actual:   " + actual);
        System.out.println();
    }

    public static void main(String[] args) {
        test("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
        test("PAYPALISHIRING", 4, "PINALSIGYAHRPI");
        test("A", 1, "A");
    }
}
