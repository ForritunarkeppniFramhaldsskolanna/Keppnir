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
    public static class Edge {
        public Vertex u, v;
        public int w;
        public Edge(Vertex u, Vertex v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }
    }

    public static class Vertex {
        public int id;
        public int distanceTo = 0;
        public ArrayList<Edge> edges;
        public Vertex(int id) {
            this.id = id;
            edges = new ArrayList<Edge>();
        }
        public int hashCode() {
            return Objects.hash(id);
        }
        public boolean equals(Object o) {
            if(o == this) {
                return true;
            }
            if(!(o instanceof Vertex)) {
                return false;
            }
            Vertex v = (Vertex)o;
            return Integer.compare(this.id, v.id) == 0;
        }
    }

    public static class VertexSorter implements Comparator<Vertex> {
        public int compare(Vertex a, Vertex b)
        {
            if(a.distanceTo < b.distanceTo) return -1;
            else if(a.distanceTo > b.distanceTo) return 1;
            else return 0;
        }
    }

    public static class Graph {
        int n;
        int m;
        public ArrayList<Vertex> V;
        ArrayList<Edge> E;
        public Graph(int n) {
            this.n = n;
            V = new ArrayList<Vertex>();
            for(int i = 0; i < n; i++) {
                V.add(new Vertex(i));
            }
            this.m = 0;
        }
        public void addEdge(int uid, int vid, int w)
        {
            Vertex u = V.get(uid);
            Vertex v = V.get(vid);
            u.edges.add(new Edge(u, v, w));
            v.edges.add(new Edge(v, u, w));
        }

        public void shortestPath(int start) {
            PriorityQueue<Vertex> q = new PriorityQueue<Vertex>(new VertexSorter());
            HashSet<Vertex> vis = new HashSet<Vertex>();
            for(Vertex v : V) v.distanceTo = Integer.MAX_VALUE;
            V.get(start).distanceTo = 0;

            q.add(V.get(start));
            while (q.size() > 0) {
                Vertex cur = q.poll();
                if(vis.contains(cur)) {
                    continue;
                }
                vis.add(cur);

                for (Edge e : cur.edges) {
                    Vertex nxt = e.v;
                    if (!vis.contains(nxt)) {
                        int newDist = cur.distanceTo + e.w;
                        if (newDist < nxt.distanceTo) {
                            nxt.distanceTo = newDist;
                        }
                        q.add(nxt);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Kattio io = new Kattio(System.in, System.out);

        int n = io.getInt();
        int m = io.getInt();
        ArrayList<Integer> g = new ArrayList<Integer>();
        for(int i = 0; i < n; i++) {
            g.add(io.getInt());
        }
        Graph A = new Graph(n);
        Graph B = new Graph(n);
        for(int i = 0; i < m; i++) {
            int u = io.getInt()-1;
            int v = io.getInt()-1;
            int a = io.getInt();
            int b = io.getInt();
            A.addEdge(u, v, a);
            B.addEdge(u, v, b);
        }

        A.shortestPath(0);
        B.shortestPath(n-1);
        int mn = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++)
        {
            mn = Math.min(mn, A.V.get(i).distanceTo + B.V.get(i).distanceTo + g.get(i));
        }


        io.println(mn);
        io.flush();
    }
}
