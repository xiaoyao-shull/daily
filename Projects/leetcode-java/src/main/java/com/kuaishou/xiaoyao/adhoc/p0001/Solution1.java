package com.kuaishou.xiaoyao.adhoc.p0001;

import static java.util.Comparator.comparingInt;
import static java.util.stream.Collectors.toList;
import static java.util.stream.IntStream.range;

import java.util.List;

/**
 * The complexity for sorting dominates.
 *
 * @author xiaoyao
 */
public class Solution1 {

    public int[] twoSum(int[] nums, int target) {
        List<Item> items = range(0, nums.length)
                .boxed()
                .map(i -> new Item(i, nums[i]))
                .sorted(comparingInt(Item::getValue))
                .collect(toList());

        int lower = 0;
        int upper = items.size() - 1;
        while (lower < upper) {
            if (items.get(lower).getValue() + items.get(upper).getValue() > target) {
                upper--;
                continue;
            }
            if (items.get(lower).getValue() + items.get(upper).getValue() < target) {
                lower++;
                continue;
            }
            return new int[]{items.get(lower).getIndex(), items.get(upper).getIndex()};
        }
        throw new RuntimeException();
    }

    private class Item {
        private final int index;
        private final int value;

        public Item(int index, int value) {
            this.index = index;
            this.value = value;
        }

        public int getIndex() {
            return index;
        }

        public int getValue() {
            return value;
        }
    }
}
