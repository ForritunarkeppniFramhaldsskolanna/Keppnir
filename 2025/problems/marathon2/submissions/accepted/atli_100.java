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
    static final int FINISH = 42195;

    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt();
        int x = io.getInt();
        int y = io.getInt();
        int h = io.getInt();
        int s = io.getInt();
        int[] locs = new int[n + 2];
        Arrays.fill(locs, 0);
        for(int i = 0; i < n; ++i)
            locs[i + 1] = io.getInt();
        locs[n + 1] = FINISH;
        Arrays.sort(locs);
        int j = 0;
        for(int i = 0; i < n + 2; ++i) {
            if(i + 1 < n + 2 && locs[i] == locs[i + 1]) 
                continue;
            locs[j] = locs[i];
            j += 1;
        }
        n = j;
        double[] dp = new double[n];
        for(int i = n - 1; i >= 0; --i) {
            if(locs[i] + x >= FINISH) {
                dp[i] = ((double) (FINISH - locs[i])) / h;
            } else {
                double slowdist = FINISH - locs[i] - x;
                double slowtime = slowdist / s;
                double fasttime = ((double) x) / h;
                dp[i] = slowtime + fasttime;
            }
            int k = Arrays.binarySearch(locs, 0, n, locs[i] + x);
            if(k < 0) {
                k = -k - 1;
            }
            if(k < n) {
                double slowdist = locs[k] - locs[i] - x;
                double slowtime = slowdist / s;
                double fasttime = ((double) x) / h;
                double time = slowtime + fasttime;
                dp[i] = Math.min(dp[i], dp[k] + time + y);
            }
            if(k > 0) {
                double dist = locs[k - 1] - locs[i];
                double fasttime = dist / h;
                dp[i] = Math.min(dp[i], dp[k - 1] + fasttime + y);
            }
        }
        long ans = (long) Math.floor(dp[0] + 1e-9);
        long ansh = ans / 3600;
        long ansm = (ans % 3600) / 60;
        long anss = ans % 60;
        if(ansh < 10) io.print("0");
        io.print(ansh);
        io.print(":");
        if(ansm < 10) io.print("0");
        io.print(ansm);
        io.print(":");
        if(anss < 10) io.print("0");
        io.println(anss);
        io.close();
    }
}
