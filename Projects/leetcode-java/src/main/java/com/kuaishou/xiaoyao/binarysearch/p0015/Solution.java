package com.kuaishou.xiaoyao.binarysearch.p0015;

import static java.util.Arrays.asList;
import static java.util.Arrays.sort;
import static java.util.Optional.empty;
import static java.util.Optional.of;
import static java.util.stream.Collectors.toList;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

/**
 * @author xiaoyao
 */
class Solution {

    private static int getLowerBound(int[] sortedArray, int value) {
        int lower = 0;
        int upper = sortedArray.length - 1;
        while (lower < upper) {
            int inter = (lower + upper) / 2;
            if (sortedArray[inter] < value) {
                lower = inter + 1;

            } else {
                upper = inter;
            }
        }
        return sortedArray[lower] == value ? lower : -1;
    }

    private static int getUpperBound(int[] sortedArray, int value) {
        int lower = 0;
        int upper = sortedArray.length - 1;
        while (lower < upper) {
            int inter = (lower + upper + 1) / 2;
            if (sortedArray[inter] > value) {
                upper = inter - 1;

            } else {
                lower = inter;
            }
        }
        return sortedArray[upper] == value ? upper : -1;
    }

    private class PartialSum {
        private final int a;
        private final int b;

        public PartialSum(int a, int b) {
            if (a > b) {
                throw new RuntimeException();
            }
            this.a = a;
            this.b = b;
        }

        public int getA() {
            return a;
        }

        public int getB() {
            return b;
        }
    }

    private class Sum {
        private final int a;
        private final int b;
        private final int c;

        public Sum(int a, int b, int c) {
            if (a > b) {
                throw new RuntimeException();
            }
            if (b > c) {
                throw new RuntimeException();
            }
            this.a = a;
            this.b = b;
            this.c = c;
        }

        public List<Integer> toList() {
            return asList(a, b, c);
        }

        public int getA() {
            return a;
        }

        public int getB() {
            return b;
        }

        public int getC() {
            return c;
        }
    }

    public List<List<Integer>> threeSum(int[] nums) {
        sort(nums);
        return getDistinctPartialSums(nums).stream()
                .map(partialSum -> getSum(partialSum, nums))
                .filter(Optional::isPresent)
                .map(Optional::get)
                .map(Sum::toList)
                .collect(toList());
    }

    private Optional<Sum> getSum(PartialSum partialSum, int[] sortedArray) {
        int c = -(partialSum.getA() + partialSum.getB());
        if (c < partialSum.getB()) {
            return empty();
        }

        int lower = getLowerBound(sortedArray, c);
        if (lower == -1) {
            return empty();
        }
        int upper = getUpperBound(sortedArray, c);

        int count = upper - lower + 1
                - (partialSum.getA() == c ? 1 : 0)
                - (partialSum.getB() == c ? 1 : 0);

        return count <= 0
                ? empty()
                : of(new Sum(partialSum.getA(), partialSum.getB(), c));
    }

    private List<PartialSum> getDistinctPartialSums(int[] sortedArray) {
        List<PartialSum> partialSums = new ArrayList<>();
        for (int i = 0; i < sortedArray.length; ++i) {
            if (i > 0 && sortedArray[i] == sortedArray[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < sortedArray.length; ++j) {
                if (j > i + 1 && sortedArray[j] == sortedArray[j - 1]) {
                    continue;
                }
                partialSums.add(new PartialSum(sortedArray[i], sortedArray[j]));
            }
        }
        return partialSums;
    }
}