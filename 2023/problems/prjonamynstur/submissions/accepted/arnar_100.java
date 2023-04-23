import java.util.*;
import java.io.*;

public class arnar_100 {
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

        int n = io.getInt(), m = io.getInt();
        int result = 0;
        for (int i = 0; i < n; i++) {
            String line = io.getWord();
            for (int j = 0; j < m; j++) {
                char c = line.charAt(j);
                if (c == '.') {
                    result += 20;
                }
                else if (c == 'O') {
                    result += 10;
                }
                else if (c == '\\') {
                    result += 25;
                }
                else if (c == '/') {
                    result += 25;
                }
                else if (c == 'A') {
                    result += 35;
                }
                else if (c == '^') {
                    result += 5;
                }
                else if (c == 'v') {
                    result += 22;
                }
            }
        }

        io.printf("%d\n", result);
        io.close();
    }
}
