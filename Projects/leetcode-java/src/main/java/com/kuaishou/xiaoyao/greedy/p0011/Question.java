package com.kuaishou.xiaoyao.greedy.p0011;

/**
 * Given n non-negative integers a_1, a_2, ..., a_n , where each represents a point at coordinate
 * (i, a_i). n vertical lines are drawn such that the two endpoints of line i is at (i, a_i) and
 * (i, 0). Find two lines, which together with x-axis forms a container, such that the container
 * contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 * <img src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg" />
 *
 * The above vertical lines are represented by array [1, 8, 6, 2, 5, 4, 8, 3, 7]. In this case, the
 * max area of water (blue section) the container can contain is 49.
 *
 * @author xiaoyao
 */
@SuppressWarnings("Duplicates")
public class Question {

    private static void test(int[] input, int expected) {
        int actual = new Solution().maxArea(input);
        System.out.println("input   : " + input);
        System.out.println("expected: " + expected);
        System.out.println("actual  : " + actual);
        System.out.println();
    }

    public static void main(String[] args) {
        test(new int[]{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49);
    }
}
