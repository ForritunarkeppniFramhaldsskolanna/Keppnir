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
        long B = io.getLong();
        int maxInd = 0;
        long max = -1;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            long cur = (io.getLong() + B - 1) / B;
            sum += cur;
            if (cur > max) {
                maxInd = i;
                max = cur;
            }
        }

        for (int i = 0; i < n; i++) {
            if (sum < 2 * max) {
                if (i == maxInd) {
                    io.printf("1 "); 
                }
                else {
                    io.printf("2 "); 
                }
            }
            else {
                io.printf("1 ");
            }
        }
        io.println();
        io.flush(); 
    }
}
