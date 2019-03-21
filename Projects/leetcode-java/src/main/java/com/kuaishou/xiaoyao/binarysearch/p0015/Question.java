package com.kuaishou.xiaoyao.binarysearch.p0015;

import static java.util.Arrays.asList;
import static java.util.Arrays.stream;
import static java.util.stream.Collectors.joining;

import java.util.List;

/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 *
 *   The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 *   Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 *   A solution set is:
 *   [
 *     [-1, 0, 1],
 *     [-1, -1, 2]
 *   ]
 *
 * @author xiaoyao
 */
public class Question {

    private static void test(int[] input, List<List<Integer>> expected) {
        List<List<Integer>> actual = new Solution().threeSum(input);
        System.out.println("input: " + stream(input)
                .boxed()
                .map(String::valueOf)
                .collect(joining(", ")));

        System.out.println("expected: ");
        for (List<Integer> list : expected) {
            System.out.println("  " + list);
        }
        System.out.println("actual: ");
        for (List<Integer> list : actual) {
            System.out.println("  " + list);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        test(new int[]{-1, 0, 1, 2, -1, -4}, asList(
                asList(-1, -1, 2),
                asList(-1, 0, 1)
        ));
        test(new int[]{0, 1, 2, 3, 4, -1, -2, -3, -4}, asList(
                asList(-4, 0, 4),
                asList(-4, 1, 3),
                asList(-3, -1, 4),
                asList(-3, 0, 3),
                asList(-3, 1, 2),
                asList(-2, -1, 3),
                asList(-2, 0, 2),
                asList(-1, 0, 1)
        ));
    }
}
