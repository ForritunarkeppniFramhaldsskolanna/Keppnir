import java.util.*;
import java.math.*;
import java.io.*;
public class GreedyBruteSlow {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, true);

        long n = in.nextLong();

        long c = n-4;
        while (!BigInteger.valueOf(c).isProbablePrime(20)) {
            c--;
        }

        for (long a = 1; a <= n-c; a++) {
            for (long b = 1; b <= n-c; b++) {
                if (a + b + c == n && BigInteger.valueOf(a).isProbablePrime(20) && BigInteger.valueOf(b).isProbablePrime(20)) {
                    out.printf("%d %d %d\n", a, b, c);
                    return;
                }
            }
        }

        out.println("Neibb");
    }
}
