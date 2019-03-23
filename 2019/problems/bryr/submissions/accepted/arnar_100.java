import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static class Edge {
    public int dest, dist;
    public Edge(int dest, int dist) {
        this.dest = dest;
        this.dist = dist;
    }
  }

  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int n = in.nextInt();
    int m = in.nextInt();
    ArrayList<ArrayList<Edge> > adj = new ArrayList<ArrayList<Edge> >(n);
    ArrayList<Boolean> vis = new ArrayList<Boolean>(n);
    ArrayList<Integer> dist = new ArrayList<Integer>(n);
    for(int i = 0; i < n; i++) {
        adj.add(new ArrayList<Edge>());
        vis.add(false);
        dist.add(2*n);
    }
    for(int i = 0; i < m; i++) {
        int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
        a--;
        b--;
        adj.get(a).add(new Edge(b, c));
        adj.get(b).add(new Edge(a, c));
    }
    
    Deque<Integer> q = new ArrayDeque<Integer>();
    q.addLast(0);
    dist.set(0, 0);


    while(q.size() > 0) {
        int cur = q.pollFirst();
        if(vis.get(cur) == true) continue;
        vis.set(cur, true);
        for(Edge e : adj.get(cur)) {
            if(vis.get(e.dest) == true) continue;
            if(e.dist == 1) {
                dist.set(e.dest, Math.min(dist.get(e.dest), dist.get(cur)+e.dist));
                q.addLast(e.dest);
            } else {
                dist.set(e.dest, Math.min(dist.get(e.dest), dist.get(cur)+e.dist));
                q.addFirst(e.dest);
            }
        }
    }

    out.println(dist.get(n-1));

    out.flush(); } }
