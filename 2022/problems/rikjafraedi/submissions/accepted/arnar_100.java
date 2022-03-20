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

class Vector3 {
    public long x, y, z;
    public Vector3(long x, long y, long z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    public Vector3 add(Vector3 o) {
        return new Vector3(x + o.x, y + o.y, z + o.z);
    }
    @Override
    public boolean equals(Object o) {
        if(o instanceof Vector3) {
            Vector3 v = (Vector3)o;
            return x == v.x && y == v.y && z == v.z;
        }
        return false;
    }
}

public class arnar_100 {
    static HashMap<Integer, Vector3> dist;
    static void dfs(int u, Vector3 loc, ArrayList<ArrayList<Edge<Vector3>>> adj) {
        dist.put(u, loc);
        for (Edge<Vector3> e : adj.get(u)) {
            Vector3 nextloc = loc.add(e.w);
            Vector3 existing = dist.get(e.v);
            if (existing == null) {
                dfs(e.v, nextloc, adj);
            }
        }
    }
    public static void main(String[] args) throws Exception {
        Kattio io = new Kattio(System.in, System.out);
        dist = new HashMap<Integer, Vector3>();
        int n = io.getInt(), m = io.getInt();
        ArrayList<ArrayList<Edge<Vector3>>> adj = new ArrayList<ArrayList<Edge<Vector3>>>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<Edge<Vector3>>());
        }
        
        for(int i = 0; i < m; i++) {
            int a = io.getInt() - 1;
            int b = io.getInt() - 1;
            long x = io.getLong();
            long y = io.getLong();
            long z = io.getLong();
            adj.get(a).add(new Edge(a, b, new Vector3(x, y, z)));   
            adj.get(b).add(new Edge(b, a, new Vector3(-x, -y, -z)));
        }

        for (int i = 0; i < n; i++) {
            if(dist.get(i) == null) {
                dfs(i, new Vector3(0, 0, 0), adj);
            }
        }        
        
        boolean result = true;
        for (int i = 0; i < n; i++) {
            for (Edge<Vector3> e : adj.get(i)) {
                Vector3 du = dist.get(e.u);
                Vector3 dv = dist.get(e.v);
                if(!du.add(e.w).equals(dv)) {
                    result = false;
                }
            }
        }
        if (result) {
            io.println("Jebb");
        }
        else {
            io.println("Neibb");
        }

        io.flush(); 
    }
}
