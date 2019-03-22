package com.kuaishou.xiaoyao.adhoc.p0001;

import static com.kuaishou.xiaoyao.utils.ArrayUtils.print;
import static com.kuaishou.xiaoyao.utils.ArrayUtils.sorted;

/**
 * 1. Two Sum
 *
 * Given an array of integers, return indices of the two numbers such that they add up to a
 * specific target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same
 * element twice.
 *
 * Example:
 *
 *   Given nums = [2, 7, 11, 15], target = 9,
 *
 *   Because nums[0] + nums[1] = 2 + 7 = 9,
 *   return [0, 1].
 *
 * @author xiaoyao
 */
public class Problem0001 {

    private static void test(int[] nums, int target, int[] expected) {
        int[] actual = new Solution().twoSum(nums, target);
        System.out.println("input nums: " + print(sorted(nums)));
        System.out.println("input target: " + target);
        System.out.println("expected:" + print(expected));
        System.out.println("actual: " + print(sorted(actual)));
        System.out.println();
    }

    public static void main(String[] args) {
        test(new int[]{2, 7, 11, 15}, 9, new int[]{0, 1});
        test(new int[]{3, 2, 4}, 6, new int[]{1, 2});
        test(new int[]{2, 7, 11, 15}, 9, new int[]{0, 1});
    }
}
