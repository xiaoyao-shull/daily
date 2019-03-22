package com.kuaishou.xiaoyao.adhoc.p0001;

import java.util.HashMap;
import java.util.Map;

/**
 * Complexity: O(n).
 *
 * @author xiaoyao
 */
class Solution {

    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> value2Index = new HashMap<>();
        value2Index.put(nums[0], 0);
        for (int i = 1; i < nums.length; ++i) {
            if (value2Index.containsKey(target - nums[i])) {
                return new int[]{i, value2Index.get(target - nums[i])};
            }
            value2Index.put(nums[i], i);
        }
        throw new RuntimeException();
    }
}