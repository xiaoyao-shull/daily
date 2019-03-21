package com.kuaishou.xiaoyao.binarysearch.p0016;

import static java.lang.Math.abs;
import static java.util.Arrays.stream;
import static java.util.stream.Collectors.toList;

import java.util.List;

/**
 * @author xiaoyao
 */
class Solution {
    private static int getLowerBound(List<Integer> sortedList, int value) {
        int lower = 0;
        int upper = sortedList.size() - 1;
        while (lower < upper) {
            int inter = (lower + upper) / 2;
            if (sortedList.get(inter) < value) {
                lower = inter + 1;

            } else {
                upper = inter;
            }
        }
        return upper;
    }

    private static int getUpperBound(List<Integer> sortedList, int value) {
        int lower = 0;
        int upper = sortedList.size() - 1;
        while (lower < upper) {
            int inter = (lower + upper + 1) / 2;
            if (sortedList.get(inter) > value) {
                upper = inter - 1;

            } else {
                lower = inter;
            }
        }
        return lower;
    }

    public int threeSumClosest(int[] array, int target) {
        List<Integer> sortedList = stream(array).boxed().sorted().collect(toList());
        int i;
        int j;
        int best = 0;
        int bestDiff = -1;
        for (i = 0; i < sortedList.size() - 2; ++i) {
            for (j = i + 1; j < sortedList.size() - 1; ++j) {
                int a = sortedList.get(i);
                int b = sortedList.get(j);
                int candidate = target - a - b;


                List<Integer> subList = sortedList.subList(j + 1, sortedList.size());
                int lower = getLowerBound(subList, candidate);
                int upper = getUpperBound(subList, candidate);

                if (lower != -1) {
                    int sum = subList.get(lower) + a + b;
                    if ((bestDiff == -1 || bestDiff > abs(target - sum))) {
                        best = sum;
                        bestDiff = abs(target - sum);
                    }
                }
                if (upper != -1) {
                    int sum = subList.get(upper) + a + b;
                    if ((bestDiff == -1 || bestDiff > abs(sum - target))) {
                        best = sum;
                        bestDiff = abs(sum - target);
                    }
                }
            }
        }
        return best;
    }
}