package com.kuaishou.xiaoyao.adhoc.p0008;

import static java.lang.Character.isDigit;

/**
 * @author xiaoyao
 */
class Solution {
    public int myAtoi(String str) {
        char[] array = str.toCharArray();

        int i = 0;
        while (i < array.length && array[i] == ' ') {
            i++;
        }
        if (i == array.length) {
            return 0;
        }

        boolean isNegative;
        if (array[i] == '+') {
            isNegative = false;
            i++;

        } else if (array[i] == '-') {
            isNegative = true;
            i++;

        } else {
            isNegative = false;
        }

        long value = 0;
        while (i < array.length && isDigit(array[i])) {
            value *= 10;
            value += array[i] - '0';
            i++;

            if (isNegative && -value <= Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;

            } else if (!isNegative && value >= Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
        }

        return (int) (isNegative ? -value : value);
    }
}