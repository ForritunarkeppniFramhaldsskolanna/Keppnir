import java.util.*;
import java.math.*;
import java.io.*;

public class Rand {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);

        Random rand = new Random();
        long n = in.nextLong();

        while (true) {
            long a = rand.nextLong() % n;
            if (a < 2) continue;
            long b = rand.nextLong() % (n-a);
            if (b < 2) continue;
            if (BigInteger.valueOf(a).isProbablePrime(20) &&
                BigInteger.valueOf(b).isProbablePrime(20) &&
                BigInteger.valueOf(n-a-b).isProbablePrime(20)) {
                out.printf("%d %d %d\n", a, b, n-a-b);
                break;
            }
        }

        out.flush();
    }
}

