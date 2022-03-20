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

class Edge<T> implements Comparable<Edge<T>> {
    int u, v;
    T w;
    public Edge(int u, int v, T w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }
    @Override
    public int compareTo(Edge<T> other) {
        if(w instanceof Comparable) {
            return ((Comparable)w).compareTo(other.w);
        }
        else {
            int res = Integer.compare(u, other.u);
            if(res == 0) {
                return Integer.compare(v, other.v);
            }
            return res;
        }
    }
}

class UnionFind {
    ArrayList<Integer> p;
    public UnionFind(int n) {
        p = new ArrayList<Integer>();
        for(int i = 0; i < n; i++) {
            p.add(-1);
        }
    }

    public int find(int x) {
        if (p.get(x) < 0) {
            return x;
        }
        p.set(x, find(p.get(x)));
        return p.get(x);
    }

    public boolean unite(int x, int y) {
        int xp = find(x);
        int yp = find(y);
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

    public int size(int x) {
        return -p.get(find(x)); 
    } 
}

public class arnar_uf_90 {
    static Kattio io;
    static PrintWriter err;

    public static ArrayList<Edge<Integer>> readEdges(int m) {
        ArrayList<Edge<Integer>> edges = new ArrayList<Edge<Integer>>();
        for(int i = 0; i < m; i++) {
            edges.add(new Edge<Integer>(io.getInt() - 1, io.getInt() - 1, io.getInt()));
        }
        return edges;
    }

    public static void main(String[] args) throws Exception {
        io = new Kattio(System.in, System.out);
        err = new PrintWriter(System.err, false);

        int n = io.getInt();
        int m = io.getInt();
        int q = io.getInt();

        int jebb_count = 0;


        ArrayList<Edge<Integer>> edges = readEdges(m);
        Collections.sort(edges);
        UnionFind uf = new UnionFind(n);

        int edgeIndex = m-1;
        for(int j = 0; j < q; j++)
        {
            int a = (io.getInt() ^ jebb_count) - 1;
            int b = (io.getInt() ^ jebb_count) - 1;
            int h = io.getInt() ^ jebb_count;
            
            while(edgeIndex >= 0 && edges.get(edgeIndex).w >= h) {
                Edge<Integer> e = edges.get(edgeIndex);
                uf.unite(e.u, e.v);
                edgeIndex--;
            }

            if (uf.find(a) != uf.find(b)) {
                io.println("Neibb");
            }
            else {
                io.println("Jebb");
                jebb_count += 1;
            }
            io.flush();
        }

        io.flush();
    }
}
