import java.util.*;
import java.math.*;
import java.io.*;

public class Bjarki {
    public static int[] arr;

    public static long count(long n) {
        long ans = 0;
        for (int s = 1; s < (1<<arr.length); s++) {
            long left = n;
            int res = -1;
            for (int i = 0; i < arr.length; i++) {
                if ((s & (1<<i)) != 0) {
                    left = left / arr[i];
                    res = -res;
                }
            }
            ans += left * res;
        }
        return ans;
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);

        long L = in.nextLong(),
             R = in.nextLong();
        int k = in.nextInt();

        arr = new int[k];
        for (int i = 0; i < k; i++) {
            arr[i] = in.nextInt();
        }

        out.println(count(R) - count(L-1));

        out.flush();
    }
}

