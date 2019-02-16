import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        PrintWriter printWriter = new PrintWriter(new BufferedOutputStream(System.out));
        while (true) {
            int number = scanner.nextInt();
            if (number == 42) {
                break;

            } else {
                printWriter.println(number);
            }
        }
        printWriter.flush();
    }
}
