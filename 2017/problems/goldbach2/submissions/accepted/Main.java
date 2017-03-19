import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);

        int bound = 5000;
        boolean[] prime = new boolean[bound];
        for (int i = 2; i < bound; i++) prime[i] = true;
        List<Integer> primes = new ArrayList<Integer>();
        for (int i = 2; i < bound; i++) {
            if (prime[i]) {
                for (int j = i+i; j < bound; j += i) {
                    prime[j] = false;
                }
                primes.add(i);
            }
        }

        int[] wit = new int[bound];
        for (int i = 0; i < primes.size(); i++) {
            for (int j = i; j < primes.size() && primes.get(i) + primes.get(j) < bound; j++) {
                wit[primes.get(i) + primes.get(j)] = primes.get(j);
            }
        }

        long n = in.nextLong(),
             k3 = n - 3;
        while (!BigInteger.valueOf(k3).isProbablePrime(20)) {
            k3--;
        }

        long k2 = wit[(int)(n - k3)],
             k1 = n - k2 - k3;

        out.printf("%d %d %d\n", k1, k2, k3);

        out.flush();
    }
}

