import java.util.*;
import java.math.*;
import java.io.*;
import java.util.Objects;
import java.util.function.BiFunction;

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

class GrowingUnionFind<T> {
    ArrayList<Integer> p;
    HashMap<T, Integer> map;
    public GrowingUnionFind() {
        p = new ArrayList<Integer>();
        map = new HashMap<T, Integer>();
    }

    private int get(T key) {
        if (!map.containsKey(key)) {
            map.put(key, map.size());
            p.add(-1);
        }
        return map.get(key);
    }
    
    public int findKey(T xKey) {
        return find(get(xKey));
    }

    private int find(int x) {
        if (p.get(x) < 0) {
            return x;
        }
        p.set(x, find(p.get(x)));
        return p.get(x);
    }

    public boolean unite(T xKey, T yKey) {
        int xp = findKey(xKey);
        int yp = findKey(yKey);
        if (xp == yp) {
            return false;
        }
        if (p.get(xp) > p.get(yp)) {
            int tmp = yp;
            yp = xp;
            xp = tmp;
        }
        p.set(xp, p.get(xp) + p.get(yp));
        p.set(yp, xp);
        return true; 
    }

    public boolean united(T xKey, T yKey) {
        return findKey(xKey) == findKey(yKey);
    }

    public int size(T xKey) {
        int x = get(xKey);
        return -p.get(find(x)); 
    } 
}


public class arnar_100 {
    static Kattio io;
    static PrintWriter err;
    static long n, m, q;

    public static long ind(long x, long y) {
        return x*m+y;
    }

    public static void main(String[] args) throws Exception {
        io = new Kattio(System.in, System.out);
        err = new PrintWriter(System.err, false);

        q = io.getLong();
        n = io.getLong();
        m = io.getLong();

        long BOTTOM_RIGHT = ind(n, m);
        long TOP_LEFT = ind(n+1, m);
        
        GrowingUnionFind<Long> uf = new GrowingUnionFind<Long>();

        for (int i = 0; i < q; i++) {
            long x1 = io.getLong();
            long y1 = io.getLong();
            long x2 = io.getLong();
            long y2 = io.getLong();

            if(x2 < x1) {
                long temp = x1;
                x1 = x2;
                x2 = temp;
            }
            if(y2 < y1) {
                long temp = y1;
                y1 = y2;
                y2 = temp;
            }

            if(y1 == y2) {
                if(y1 == 0) {
                    uf.unite(ind(x1, y1), BOTTOM_RIGHT);
                }
                else if(y1 == m) {
                    uf.unite(ind(x1, y1-1), TOP_LEFT);
                }
                else {
                    uf.unite(ind(x1, y1-1), ind(x1, y1));
                }
            } else {
                if(x1 == 0) {
                    uf.unite(ind(x1, y1), TOP_LEFT);
                }
                else if(x1 == n) {
                    uf.unite(ind(x1-1, y1), BOTTOM_RIGHT);
                }
                else {
                    uf.unite(ind(x1 - 1, y1), ind(x1, y1));
                }
            }
            if(uf.united(BOTTOM_RIGHT, TOP_LEFT)) {
                io.printf("%d\n", i+1);
                io.flush();
                return;
            }
        }

        io.printf("-1\n");
        io.flush();
        io.flush();
    }
}
