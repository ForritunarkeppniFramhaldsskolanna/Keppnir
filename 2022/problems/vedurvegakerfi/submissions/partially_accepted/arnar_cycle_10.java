import java.util.*;
import java.math.*;
import java.io.*;

public class arnar_cycle_10 {
    static Scanner in;
    static PrintWriter out;

    static int minOnPath(ArrayList<Integer> weights, int a, int b, boolean forward) {
        if(a == b) {
            return Integer.MAX_VALUE;
        }
        if(forward) {
            return Math.min(weights.get(a), minOnPath(weights, (a+1)%weights.size(), b, forward));
        }
        else { 
            return minOnPath(weights, b, a, true);
        }
    }

    static int query(ArrayList<Integer> weights, int a, int b) {
        return Math.max(minOnPath(weights, Math.min(a, b), Math.max(a, b), true),
                        minOnPath(weights, Math.min(a, b), Math.max(a, b), false));
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out, false);

        int n = in.nextInt();
        int m = in.nextInt();
        int q = in.nextInt();

        int jebb_count = 0;

        ArrayList<Integer> weights = new ArrayList<Integer>();
        for (int i = 0; i < m; i++) {
            int u = in.nextInt();
            int v = in.nextInt();
            int w = in.nextInt();
            weights.add(w);
        }

        for(int j = 0; j < q; j++)
        {
            int a = (in.nextInt() ^ jebb_count) - 1;
            int b = (in.nextInt() ^ jebb_count) - 1;
            int h = in.nextInt() ^ jebb_count;

            if (minOnPath(weights, Math.min(a, b), Math.max(a, b), true) < h && minOnPath(weights, Math.max(a, b), Math.min(a, b), true) < h) {
                // If the minimum threshold is less than the windspeed
                // then there is no path
                out.println("Neibb");
            }
            else {
                // Otherwise there is a path
                // All roads can handle windspeed h
                out.println("Jebb");
                jebb_count += 1;
            }
            out.flush();
        }

        out.flush();
    }
}
