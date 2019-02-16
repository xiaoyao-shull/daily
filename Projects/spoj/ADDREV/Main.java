import java.util.*;
import java.util.*;
import java.io.*;
import java.util.stream.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int caseCount = in.nextInt();
        while (caseCount-- > 0) {
            String x = in.next();
            String y = in.next();
            int xlen = x.length();
            int ylen = y.length();
            int carry = 0;
            List<Character> characters = new ArrayList<>();
            for (int i = 0; i < xlen || i < ylen; ++i) {
                if (i >= xlen) {
                    carry += y.charAt(i) - '0';

                } else if (i >= ylen) {
                    carry += x.charAt(i) - '0';
                
                } else {
                    carry += x.charAt(i) - '0';
                    carry += y.charAt(i) - '0';
                }
                characters.add((char) (carry % 10 + '0'));
                carry /= 10;
            }
            if (carry > 0) {
                characters.add((char) (carry + '0'));
            }
            int index = 0;
            while (characters.get(index) == '0') {
                index++;
            }
            characters = characters.subList(index, characters.size());
            out.println(characters.stream().map(String::valueOf).collect(Collectors.joining()));
        }
        out.flush();
    }
}