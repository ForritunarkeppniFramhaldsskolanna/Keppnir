import java.util.*;
import java.math.*;
import java.io.*;
public class GreedyBruteMed {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, true);

        long n = in.nextLong();

        long c = n-4;
        while (!BigInteger.valueOf(c).isProbablePrime(20)) {
            c--;
        }

        for (long a = 1; a <= n-c; a++) {
            long b = n - c - a;
            if (BigInteger.valueOf(a).isProbablePrime(20) && BigInteger.valueOf(b).isProbablePrime(20)) {
                out.printf("%d %d %d\n", a, b, c);
                return;
            }
        }

        out.println("Neibb");
    }
}
