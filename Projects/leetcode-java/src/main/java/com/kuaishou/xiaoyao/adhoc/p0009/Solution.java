package com.kuaishou.xiaoyao.adhoc.p0009;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

/**
 * @author xiaoyao
 */
class Solution {

    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        List<Integer> digits = new ArrayList<>();
        for (int i = x; i > 0; i /= 10) {
            digits.add(i % 10);
        }
        for (int i = 0, j = digits.size() - 1; i < j; ++i, --j) {
            if (!Objects.equals(digits.get(i), digits.get(j))) {
                return false;
            }
        }
        return true;
    }
}