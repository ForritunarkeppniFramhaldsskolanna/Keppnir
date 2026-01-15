import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

class Kattio extends PrintWriter
{
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
                    if (line == null)
                        return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            }
            catch (IOException e) {
            }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}

public class atli_100 {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt(), k = io.getInt();
        long[] L = new long[n], D = new long[n];
        long S = 0, R = 0;
        for(int i = 0; i < n; ++i) {
            L[i] = io.getLong();
            D[i] = io.getLong();
            S += L[i];
            R += D[i];
        }
        long T = io.getLong();
        if(S <= T) {
            io.println(R);
            io.close();
            return;
        }
        long[] dp = new long[(int)(S + 1)];
        Arrays.fill(dp, 0);
        for(int i = n - 1; i >= 0; --i) {
            long cp[] = new long[(int)(S + 1)];
            Arrays.fill(cp, 0);
            for(int s = 0; s < S; ++s) {
                long sub1 = s < k ? 0 : dp[(int)(s - k)];
                long sub2 = s < L[i] ? 0 : dp[(int)(s - L[i])] + D[i];
                cp[s] = Math.max(sub1, sub2);
            }
            dp = cp;
        }
        io.println(dp[(int) T]);
        io.close();
    }
}
