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
    static int get_new_num(PriorityQueue<Integer> avail) {
        int x = avail.poll();
        if(avail.size() == 0) {
            avail.add(x + 1);
        }
        return x;
    }
        
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt(), q = io.getInt();
        PriorityQueue<Integer> avail = new PriorityQueue<Integer>();
        avail.add(n);
        ArrayList<Boolean> working = new ArrayList<Boolean>(n);
        ArrayList<Integer> parent = new ArrayList<Integer>(n);
        ArrayList<Integer> index = new ArrayList<Integer>(n);
        ArrayList<Integer> number = new ArrayList<Integer>(n);
        for(int i = 0; i < n; ++i) {
            working.add(true);
            parent.add(io.getInt() - 1);
            index.add(i);
            number.add(i);
        }
        for(int i = 0; i < q; ++i) {
            String op = io.getWord();
            int x = io.getInt() - 1;
            if(op.equals("+")) {
                int y = get_new_num(avail);
                if(y >= index.size()) {
                    index.add(working.size());
                } else {
                    index.set(y, working.size());
                }
                working.add(true);
                parent.add(index.get(x));
                number.add(y);
            } else if(op.equals("-")) {
                avail.add(x);
                working.set(index.get(x), false);
            } else {
                x = index.get(x);
                int ans = parent.get(x);
                while(!working.get(ans)) {
                    ans = parent.get(ans);
                }
                int fix = parent.get(x);
                parent.set(x, ans);
                while(!working.get(fix)) {
                    int tmp = parent.get(fix);
                    parent.set(fix, ans);
                    fix = tmp;
                }
                io.println(number.get(ans) + 1);
            }
        }
        io.close();
    }
}
