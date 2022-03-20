
import java.util.*;
import java.math.*;
import java.io.*;

class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int getInt() {
        return Integer.parseInt(nextToken());
    }

    public double getDouble() {
        return Double.parseDouble(nextToken());
    }

    public long getLong() {
        return Long.parseLong(nextToken());
    }

    public String getWord() {
        return nextToken();
    }



    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null)
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}

public class arnar_100 {
    public static void main(String[] args) throws Exception {
        Kattio io = new Kattio(System.in, System.out);

        int n = io.getInt();
        long m = io.getLong()+1;
        long[] t = new long[n];
        for (int i = 0; i < n; i++) {
            t[i] = io.getLong();
        }

        long lo = 0, hi = 1000000000000000000L;
        long best = -1;
        while (lo <= hi) {
            long mid = (lo + hi)/2;
            long total = 0;
            for (int i = 0; i < n; i++) {
                total += mid / t[i];
                if(total >= m) {
                    break;
                }
            }
            if (total >= m) {
                hi = mid - 1;
                best = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        io.println(best);

        io.flush(); 
    }
}
