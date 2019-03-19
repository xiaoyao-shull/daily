package com.kuaishou.xiaoyao.adhoc.P0013;

import static java.util.stream.Collectors.toList;
import static java.util.Arrays.stream;
import static java.util.Comparator.comparingInt;

import java.util.List;

class Solution {

    enum RomanDigit {
        M("M", 1000), CM("CM", 900),
        D("D", 500), CD("CD", 400),
        C("C", 100), XC("XC", 90),
        L("L", 50), XL("XL", 40),
        X("X", 10), IX("IX", 9),
        V("V", 5), IV("IV", 4),
        I("I", 1),
        ;

        private final String digitLiteral;
        private final int digitValue;

        RomanDigit(String digitLiteral, int digitValue) {
            this.digitLiteral = digitLiteral;
            this.digitValue = digitValue;
        }

        public String getDigitLiteral() {
            return digitLiteral;
        }

        public int getDigitValue() {
            return digitValue;
        }
    }

    public int romanToInt(String s) {
        char[] a = s.toCharArray();
        List<RomanDigit> romanDigits = stream(RomanDigit.values())
                .sorted(comparingInt(RomanDigit::getDigitValue).reversed())
                .collect(toList());

        int n = 0;
        int i = 0;
        for (RomanDigit romanDigit : romanDigits) {
            while (i < a.length && startsWith(a, i, romanDigit)) {
                n += romanDigit.getDigitValue();
                i += romanDigit.getDigitLiteral().length();
            }
        }
        return n;
    }

    private boolean startsWith(char[] a, int i, RomanDigit romanDigit) {
        for (int j = 0; j < romanDigit.getDigitLiteral().length(); ++j) {
            if (i + j >= a.length || a[i + j] != romanDigit.getDigitLiteral().charAt(j)) {
                return false;
            }
        }
        return true;
    }
}
