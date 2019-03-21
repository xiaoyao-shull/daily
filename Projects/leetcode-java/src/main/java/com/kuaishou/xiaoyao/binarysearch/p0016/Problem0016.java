package com.kuaishou.xiaoyao.binarysearch.p0016;

import static java.util.Arrays.stream;
import static java.util.stream.Collectors.joining;

/**
 * 16. 3Sum Closest
 *
 * Given an array nums of n integers and an integer target, find three integers in nums such that
 * the sum is closest to target. Return the sum of the three integers. You may assume that each
 * input would have exactly one solution.
 *
 * Example:
 *
 *   Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 *   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 * @author xiaoyao
 */
public class Problem0016 {

    private static void test(int[] nums, int target, int expected) {
        int actual = new Solution().threeSumClosest(nums, target);
        System.out.println(
                "input nums: " + stream(nums).boxed().map(String::valueOf).collect(joining(", "))
        );
        System.out.println("input target: " + target);
        System.out.println("expected: " + expected);
        System.out.println("actual: " + actual);
        System.out.println();
    }

    public static void main(String[] args) {
        test(new int[]{-1, 2, 1, -4}, 1, 2);
        test(new int[]{-1, 0, 1, 1, 55}, 3, 2);
    }
}
