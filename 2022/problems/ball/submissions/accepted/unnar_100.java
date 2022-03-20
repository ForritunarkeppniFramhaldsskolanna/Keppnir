import java.util.*;
import java.io.*;

public class unnar_100 {
    static class Kattio extends PrintWriter {
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
    public static void main(String[] args) throws Exception {
        Kattio io = new Kattio(System.in, System.out);

        int n = io.getInt();
        int x = 0, y = 0;
        List<Integer> arr = new ArrayList<Integer>(Collections.nCopies(n+1, 0));
        for (int i = 0; i <= n / 2; i++) {
            int a = io.getInt(), b = io.getInt();
            arr.set(a, arr.get(a)+1);
            arr.set(b, arr.get(b)+1);
            if (arr.get(a) == 2) {
                if (x == 0) x = a;
                else y = a;
            }    
            if (arr.get(b) == 2) {
                if (x == 0) x = b;
                else y = b;
            }    
        }
        // Af hverju er java ekki með built-in swap function fyrir primitives? >_<
        if (y > x)
            io.printf("%d %d\n", x, y);
        else
            io.printf("%d %d\n", y, x);
        io.close();
    }
}
