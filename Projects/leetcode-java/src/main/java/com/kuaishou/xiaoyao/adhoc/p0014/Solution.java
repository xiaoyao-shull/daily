package com.kuaishou.xiaoyao.adhoc.p0014;

/**
 * @author xiaoyao
 */
class Solution {

    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        StringBuilder stringBuilder = new StringBuilder();
        int i, j;
        for (i = 0; i < strs[0].length(); ++i) {
            for (j = 1; j < strs.length; ++j) {
                if (i >= strs[j].length() || strs[j].charAt(i) != strs[0].charAt(i)) {
                    break;
                }
            }
            if (j < strs.length) {
                break;
            }
            stringBuilder.append(strs[0].charAt(i));
        }
        return stringBuilder.toString();
    }
}