package com.kuaishou.xiaoyao.adhoc.p0012;

import static java.lang.String.join;
import static java.util.Arrays.stream;
import static java.util.Comparator.comparingInt;
import static java.util.stream.Collectors.toList;

import java.util.ArrayList;
import java.util.List;

/**
 * @author xiaoyao
 */
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

    public String intToRoman(int num) {
        List<RomanDigit> romanDigits = stream(RomanDigit.values())
                .sorted(comparingInt(RomanDigit::getDigitValue).reversed())
                .collect(toList());

        List<String> digitLiterals = new ArrayList<>();
        for (RomanDigit romanDigit : romanDigits) {
            while (num >= romanDigit.getDigitValue()) {
                num -= romanDigit.getDigitValue();
                digitLiterals.add(romanDigit.getDigitLiteral());
            }
        }
        return join("", digitLiterals);
    }
}