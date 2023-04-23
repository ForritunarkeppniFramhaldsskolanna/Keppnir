import java.lang.Math.*;
import java.math.*;
import java.util.*;
import java.io.*;

// Dear anyone who is reading this solution.
// Don't step here, the floor is made of java.
// Look into `dagur_logn_100.py`. Its actually readable.

public class dagur_logn_100 {

	public static String printArr(long[] arr) {
		PrintWriter out = new PrintWriter(System.out, false);
		String s = "[";
		for (int idx = 0; idx < 10; ++idx) {
			// out.print(arr[idx] + ' ');
			s += arr[idx];
			s += ", ";
		}
		s += "]";
		// out.println(s);
		return s;
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out, false);
		BigInteger TWO = BigInteger.valueOf(2);
		BigInteger TEN = BigInteger.valueOf(10);

		long m = 1_000_000_007; // mfw when no 1'000'000'007
		BigInteger mbi = BigInteger.valueOf(m); // mfw when no 1'000'000'007
		// BigInteger n = BigInteger.valueOf(in.nextInt());
		BigInteger n = new BigInteger(in.nextLine());
		if (n.compareTo(BigInteger.valueOf(3)) <= 0) {
			out.println(0);
			out.flush();
			return;
		}
		if (n.compareTo(BigInteger.valueOf(4)) == 0) {
			out.println(2);
			out.flush();
			return;
		}
		BigInteger nFloor = n.divide(TEN);
		// out.println("nFloor: " + nFloor);
		
		BigInteger deltabi = BigInteger.valueOf(4).modPow(nFloor, mbi); // delta = pow(4, nFloor, m)
		long delta = deltabi.multiply(TWO.modInverse(mbi)).mod(mbi).longValue(); // delta *= pow(2, -1, m)
		BigInteger guessbi = TWO.modPow(nFloor.multiply(TEN), mbi); // guess = pow(2, nFloor * 10, m)
																			// VV is not correct apparently
		// out.println("g0: " + guessbi);
		guessbi = guessbi.add(BigInteger.valueOf(4).multiply(TWO.modPow(nFloor.multiply(TWO), mbi))).mod(mbi); // guess += 4 * pow(2, nFloor * 2, m)
		// out.println("g4: " + BigInteger.valueOf(4).multiply(TWO.modPow(nFloor.multiply(TWO), mbi)));
		// out.println("g1: " + guessbi);
		long guess = guessbi.multiply(TEN.modInverse(mbi)).mod(mbi).longValue(); // guess *= pow(size, -1, m)

		// out.println("delta: " + delta);
		// out.println("guess: " + guess);

		long arr[] = new long[10];
		long arr2[] = new long[10];

		for (int idx = 0; idx < 10; ++idx) {
			if (idx % 5 == 0) {
				arr[idx] = guess;
				arr2[idx] = guess;
			} else {
				arr[idx] = (m + guess - delta) % m;
				arr2[idx] = (m + guess - delta) % m;
			}
		}

		// out.println("arr: "+  printArr(arr));

		for (int x = 1; x < (n.longValue() % 10) + 1; ++x) {
			for (int idx = 0; idx < 10; ++idx) {
				arr[(idx + x) % 10] += arr2[idx];	
				arr[(idx + x) % 10] %= m;	
			}
			for (int idx = 0; idx < 10; ++idx) {
				arr2[idx] = arr[idx];
			}
			// out.println(x + " " + printArr(arr));
		}

		out.println(arr[7]);
		out.flush();
	}
}
