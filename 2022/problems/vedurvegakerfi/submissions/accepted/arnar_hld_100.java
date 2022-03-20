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

class SegmentTree<T> {
    // https://codeforces.com/blog/entry/64971
    private T[] a;
    private T[] tree;
    private BiFunction<T, T, T> function;
    public SegmentTree(T a[], BiFunction<T, T, T> function) {
        Objects.requireNonNull(function);
        this.a = a;
        int size = (1 << (int) Math.ceil((Math.log(a.length) / Math.log(2)) + 1));
        tree =  (T[])new Object[size];
        this.function =  (x1, x2) -> {
            if (x1 == null) return x2;
            if (x2 == null) return x1;
            return function.apply(x1, x2);
        };
        build(1, 0, a.length - 1);

    }

    private T build(int root, int l, int r) {
        if (l == r) {
            return tree[root] = a[l];
        } else {
            T left = build(root * 2, l, (l + r) / 2);
            T right = build(root * 2 + 1, ((l + r) / 2) + 1, r);
            return tree[root] = function.apply(left, right);
        }
    }
    public void update(int pos, T x) {
        a[pos] = x;
        update(pos, 1, 0, a.length - 1);
    }

    private T update(int pos, int root, int left, int right) {
        if (pos < left || pos > right) {
            return tree[root];
        } else if (left == right) {
            return tree[root] = a[pos];
        } else {
            int mid = (left + right) / 2;
            T leftResult = update(pos, 2 * root, left, mid);
            T rightResult = update(pos, 2 * root + 1, mid + 1, right);
            tree[root] = function.apply(leftResult, rightResult);
            return tree[root];
        }

    }

    public T query(int l, int r) {
        T res = query(1, 0, a.length - 1, l, r);
        return res;
    }

    private T query(int root, int l, int r, int lq, int rq) {
        if (rq < l || lq > r) return null;
        if (l == r) return tree[root];
        if (lq <= l && rq >= r  ) return tree[root];
        int mid = (l + r) / 2;
        T leftResult = query(root * 2, l, mid, lq, rq);
        T rightResult = query(root * 2 + 1, mid + 1, r, lq, rq);
        return function.apply(leftResult, rightResult);

    }
}

class HeavyLightDecomposition<T> {
    private int n, curhead, curloc;
    private int[] sizes, head, parent, loc;
    private ArrayList<ArrayList<Edge<T>>> adj;
    SegmentTree<T> values;
    private BiFunction<T, T, T> function;
    PrintWriter err;
    public HeavyLightDecomposition(int n, BiFunction<T, T, T> function, PrintWriter err) {
        Objects.requireNonNull(function);
        this.n = n;
        this.err = err;
        sizes = new int[n];
        head = new int[n];
        parent = new int[n];
        loc = new int[n];
        adj = new ArrayList<ArrayList<Edge<T>>>();
        T[] temp =  (T[])new Object[n];
        this.function =  (x1, x2) -> {
            if (x1 == null) return x2;
            if (x2 == null) return x1;
            return function.apply(x1, x2);
        };
        for(int i = 0; i < n; i++) {
            sizes[i] = 1;
            parent[i] = -1;
            head[i] = 0;
            loc[i] = 0;
            adj.add(new ArrayList<Edge<T>>());
        }
        values = new SegmentTree<T>(temp, function);
    }

    public void addEdge(int u, int v, T w) {
        //err.printf("Adding edge to HLD: %d %d %s\n", u, v, String.valueOf(w));
        //err.flush();
        adj.get(u).add(new Edge<T>(u, v, w));
        adj.get(v).add(new Edge<T>(v, u, w));
    }

    void updateCost(int u, T c) {
        //err.printf("Updating cost in HLD: %d %s\n", u, String.valueOf(c));
        //err.flush();
        values.update(loc[u], c);
    }

    int calcSize(int u) {
        //err.printf("Calculating size HLD: %d\n", u);
        for(Edge<T> child : adj.get(u)) {
            if(child.v != parent[u]) {
                parent[child.v] = u;
                sizes[u] += calcSize(child.v);
            }
        }
        //err.printf("Size: %d %d\n", u, sizes[u]);
        return sizes[u];
    }

    void part(int u, T value) {
        head[u] = curhead;
        loc[u] = curloc++;
        updateCost(u, value);
        int best = -1;
        T bestw = null;
        for(Edge<T> child : adj.get(u)) {
            if (child.v != parent[u]) {
                if (best == -1 || sizes[child.v] > sizes[best]) {
                    best = child.v;
                    bestw = child.w;
                }
            }
        }
        //err.printf("Best child: %d %d\n", u, best);
        //err.flush();
        if (best != -1) {
            part(best, bestw);
        }
        for(Edge<T> child : adj.get(u)) {
            if (child.v != parent[u] && child.v != best) {
                curhead = child.v;
                part(child.v, child.w);
            }
        }
    }

    public void build() {
        build(0);
    }

    void build(int r) {
        curloc = 0;
        curhead = r;
        calcSize(r);
        part(r, null);
    }

    int lca(int u, int v) {
        ArrayList<Integer> uat = new ArrayList<Integer>(),
            vat = new ArrayList<Integer>();
        int res = -1;
        while (u != -1) {
            uat.add(u);
            u = parent[head[u]];
        }
        while (v != -1) {
            vat.add(v);
            v = parent[head[v]];
        }
        u = uat.size()-1;
        v = vat.size()-1;
        while (u >= 0 && v >= 0 && head[uat.get(u)] == head[vat.get(v)]) {
            if (loc[uat.get(u)] < loc[vat.get(v)]) {
                res = uat.get(u);
            }
            else {
                res = vat.get(v);
            }
            u--;
            v--;
        }
        return res;
    }

    private T queryUpTo(int u, int v) {
        // Note that v must be an ancestor of u
        T res = null;
        while (head[u] != head[v]) {
            res = function.apply(res, values.query(loc[head[u]], loc[u]));
            u = parent[head[u]];
        }
        return function.apply(res, values.query(loc[v] + 1, loc[u]));
    }

    public T query(int u, int v, T def) {
        int l = lca(u, v);
        T res = function.apply(queryUpTo(u, l), queryUpTo(v, l));
        if (res == null) {
            return def;
        }
        return res;
    }
}

public class arnar_hld_100 {
    static Kattio io;
    static PrintWriter err;

    public static ArrayList<Edge<Integer>> readEdges(int m) {
        ArrayList<Edge<Integer>> edges = new ArrayList<Edge<Integer>>();
        for(int i = 0; i < m; i++) {
            edges.add(new Edge<Integer>(io.getInt() - 1, io.getInt() - 1, io.getInt()));
        }
        return edges;
    }

    public static ArrayList<Edge<Integer>> maximumSpanningTree(int n, ArrayList<Edge<Integer>> edges) {
        ArrayList<Edge<Integer>> mst = new ArrayList<Edge<Integer>>();
        UnionFind uf = new UnionFind(n);
        Collections.sort(edges);
        for(int i = edges.size()-1; i >= 0; i--) {
            if (uf.unite(edges.get(i).u, edges.get(i).v)) {
                mst.add(edges.get(i));
            }
        }
        return mst;
    }

    public static void main(String[] args) throws Exception {
        io = new Kattio(System.in, System.out);
        err = new PrintWriter(System.err, false);

        int n = io.getInt();
        int m = io.getInt();
        int q = io.getInt();

        int jebb_count = 0;


        ArrayList<Edge<Integer>> edges = readEdges(m);

        // We can ignore any edges not in the maximum spanning tree
        // since they are redundant for reachability
        ArrayList<Edge<Integer>> mst = maximumSpanningTree(n, edges);

        // Build heavy light decomposition so we can query the minimum
        // edge threshold on each path.
        HeavyLightDecomposition<Integer> hld = new HeavyLightDecomposition<Integer>(n, Math::min, err);
        for(Edge<Integer> e : mst) {
            hld.addEdge(e.u, e.v, e.w);
        }
        hld.build();

        for(int j = 0; j < q; j++)
        {
            int a = (io.getInt() ^ jebb_count) - 1;
            int b = (io.getInt() ^ jebb_count) - 1;
            int h = io.getInt() ^ jebb_count;

            if (hld.query(a, b, Integer.MAX_VALUE) < h) {
                // If the minimum threshold is less than the windspeed
                // then there is no path
                io.println("Neibb");
            }
            else {
                // Otherwise there is a path
                // All roads can handle windspeed h
                io.println("Jebb");
                jebb_count += 1;
            }
        }

        io.flush();
    }
}
