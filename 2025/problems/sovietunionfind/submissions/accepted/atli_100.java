import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

class Soviet {
    public int[] p;
    public int[] nxt;
    public int[] fst;
    public int[] lst;

    public Soviet(int n) {
        this.p = new int[n];
        this.nxt = new int[n];
        this.fst = new int[n];
        this.lst = new int[n];
        Arrays.fill(this.p, -1);
        Arrays.fill(this.nxt, -1);
        for(int i = 0; i < n; ++i) {
            this.fst[i] = i;
            this.lst[i] = i;
        }
    }
    
    public int find(int x) {
        if(p[x] < 0) {
            return x;
        } else {
            p[x] = find(p[x]);
            return p[x];
        }
    }

    public void unite(int x, int y) {
        int xp = find(x);
        int yp = find(y);
        if(xp == yp) return;
        boolean swp = false;
        if(p[xp] > p[yp]) {
            int tmp = xp;
            xp = yp;
            yp = tmp;
            swp = true;
        }
        p[xp] += p[yp];
        p[yp] = xp;
        if(swp) {
            nxt[lst[yp]] = fst[xp];
            fst[xp] = fst[yp];
        } else {
            nxt[lst[xp]] = fst[yp];
            lst[xp] = lst[yp];
        }
    }

    void balkanise(int x) {
        int xp = find(x);
        ArrayList<Integer> todo = new ArrayList<Integer>();
        todo.add(fst[xp]);
        while(nxt[todo.get(todo.size() - 1)] != -1) {
            todo.add(nxt[todo.get(todo.size() - 1)]);
        }
        for(Integer y : todo) {
            p[y] = -1;
            fst[y] = y;
            lst[y] = y;
            nxt[y] = -1;
        }
    }
}

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
        int n = io.getInt(), q = io.getInt();
        Soviet suf = new Soviet(n);
        for(int i = 0; i < q; ++i) {
            String op = io.getWord();
            if(op.equals("a")) {
                int x = io.getInt() - 1;
                int y = io.getInt() - 1;
                suf.unite(x, y);
            } else if(op.equals("b")) {
                int j = io.getInt() - 1;
                suf.balkanise(j);
            } else {
                int j = io.getInt() - 1;
                int p = suf.find(j);
                io.println(suf.fst[p] + 1);
            }
        }
        io.close();
    }
}
