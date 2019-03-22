package com.kuaishou.xiaoyao.utils;

import static java.lang.String.format;
import static java.lang.System.arraycopy;
import static java.util.Arrays.sort;
import static java.util.Arrays.stream;
import static java.util.stream.Collectors.joining;

/**
 * @author xiaoyao
 */
public class ArrayUtils {

    public static int[] sorted(int[] array) {
        if (array == null) {
            return null;
        }
        int[] copy = new int[array.length];
        arraycopy(array, 0, copy, 0, array.length);
        sort(copy);
        return copy;
    }

    public static String print(int[] array) {
        if (array == null || array.length == 0) {
            return "[]";
        }
        return format("[%s]", stream(array).boxed().map(String::valueOf).collect(joining(", ")));
    }
}
