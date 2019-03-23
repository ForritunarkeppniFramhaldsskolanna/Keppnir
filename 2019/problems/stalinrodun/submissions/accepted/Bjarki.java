import java.util.*;
import java.math.*;
import java.io.*;

public class Bjarki {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);

        int n = in.nextInt();
        int[] arr = new int[n];
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            int lo = 0,
                hi = cnt,
                res = -1;
            while (lo <= hi) {
                int mid = (lo+hi)/2;
                if (x >= arr[mid]) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            cnt = Math.max(cnt, res+1);
            arr[res] = x;
        }
        out.println(cnt);

        out.flush();
    }
}

