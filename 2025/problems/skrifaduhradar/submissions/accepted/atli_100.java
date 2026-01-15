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
        int n = io.getInt();
        long T = io.getLong();
        long lo = 1, hi = 1;
        Long[] w = new Long[n];
        for(int i = 0; i < n; ++i) {
            w[i] = io.getLong();
            hi += w[i];
        }
        Arrays.sort(w);
        while(lo < hi) {
            long md = lo + (hi - lo) / 2;
            long cur_t = 0, left = md - 1, sm = 0;
            for(int i = 0; i < n; ++i) {
                long wi = w[i];
                if(left >= wi) {
                    left -= wi;
                } else {
                    wi -= left + 1;
                    cur_t += 1 + (wi / md);
                    wi %= md;
                    left = md - 1 - wi;
                }
                sm += cur_t;
            }
            if(sm >= T) lo = md + 1;
            else hi = md;
        }
        io.println(lo);
        io.close();
    }
}
