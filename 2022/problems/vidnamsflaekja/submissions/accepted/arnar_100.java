import java.util.*;
import java.math.*;
import java.io.*;
import java.util.concurrent.atomic.AtomicLong;

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
    public static long egcd(long a, long b, AtomicLong x, AtomicLong y)
    {
        if (a == 0L)
        {
            x.set(0L);
            y.set(1L);
            return b;
        }
 
        AtomicLong _x = new AtomicLong(), _y = new AtomicLong();
        long gcd = egcd(b % a, a, _x, _y);
 
        x.set(_y.get() - (b/a) * _x.get());
        y.set(_x.get());
 
        return gcd;
    }

    static long mod_inv(long a, long m) {
        AtomicLong x = new AtomicLong();
        AtomicLong y = new AtomicLong();
        long d = egcd(a, m, x, y);
        return d == 1 ? (x.get()%m+m)%m : -1; 
    }

    static class Mod extends Object {
        public long x;
        public Mod() {
            this(0L);
        }
        public Mod(long _x) {
            x = (_x % 1000000007L + 1000000007L) % 1000000007L;
        }
        public Mod add (Mod other) {
            return new Mod(x + other.x);
        }
        public Mod sub(Mod other) {
            return new Mod(x - other.x);
        }
        public Mod neg() {
            return new Mod(-x);
        }
        public Mod mul (Mod other) {
            return new Mod(x * other.x);
        }
        public Mod div(Mod other) {
            return new Mod(x * mod_inv(other.x, 1000000007L));
        }
        @Override
        public boolean equals(Object other) {
            if(other instanceof Mod) {
                Mod m = (Mod)other;
                return x == m.x;
            }
            return false;
        }
    };

    static class vMod extends ArrayList<Mod> {}
    static class vvMod extends ArrayList<vMod> {}

    static Mod matrix_rref(vvMod M) {
        Mod det = new Mod(1);
        int h = 0, k = 0;
        while(h < M.size() && k < M.get(0).size()) {
            int nonzind = -1;
            for(int i = h; i < M.size(); ++i) {
                if(!M.get(i).get(k).equals(new Mod(0))) {
                    nonzind = i;
                }
            }
            if(nonzind == -1) {
                k++;
                det = new Mod(0);
            } else {
                Collections.swap(M, h, nonzind);
                if(h != nonzind) det = det.neg();
                det = det.mul(M.get(h).get(h));
                for(int i = h + 1; i < M.size(); ++i) {
                    Mod f = M.get(i).get(k).div(M.get(h).get(k));
                    M.get(i).set(k, new Mod(0));
                    for(int j = k + 1; j < M.get(0).size(); ++j) {
                        M.get(i).set(j, M.get(i).get(j).sub(M.get(h).get(j).mul(f)));
                    }
                }
                h++;
                k++;
            }
        }
        return det;
    }

    static class Edge {
        public Mod first;
        public int second;
        public Edge(Mod first, int second) {
            this.first = first;
            this.second = second;
        } 
    }

    static class ModGraph extends ArrayList<ArrayList<Edge>> {}

    static Mod calculate_resistance_exact(ModGraph g, int x, int y) {
        if(x > y) {
            int t = x;
            x = y;
            y = t;
        }
        vvMod laplacian = new vvMod();
        for(int i = 0; i < g.size(); ++i) {
            laplacian.add(new vMod());
            for (int j = 0; j < g.size(); j++) {
                laplacian.get(i).add(new Mod(0));
            }
            for(Edge p : g.get(i)) {
                laplacian.get(i).set(p.second, laplacian.get(i).get(p.second).sub((new Mod(1)).div(p.first)));
            }
        }
        for(int i = 0; i < g.size(); ++i) {
            Mod sm = new Mod(0);
            for(int j = 0; j < g.size(); ++j) {
                if(i == j) {
                    continue;
                }
                sm = sm.sub(laplacian.get(i).get(j));
            }
            laplacian.get(i).set(i, sm);
        }
        vvMod cof11 = new vvMod();
        for(int i = 1; i < g.size(); ++i) {
            cof11.add(new vMod());
            for(int j = 1; j < g.size(); ++j) {
                cof11.get(i-1).add(laplacian.get(i).get(j));
            }
        }
        vvMod cofxy = new vvMod();
        for(int i = 0; i < g.size(); ++i) {
            if(i == x || i == y) {
                continue;
            }
            cofxy.add(new vMod());
            int ind1 = i < x ? i : (i < y ? i - 1 : i - 2);
            for(int j = 0; j < g.size(); ++j) {
                if(j == x || j == y) {
                    continue;
                }
                int ind2 = j < x ? j : (j < y ? j - 1 : j - 2);
                cofxy.get(ind1).add(laplacian.get(i).get(j));
            }
        }
        return matrix_rref(cofxy).div(matrix_rref(cof11));
    }

    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n, m, s, t, a, b, x;
        n = io.getInt();
        m = io.getInt();
        s = io.getInt();
        t = io.getInt();
        s--; t--;
        ModGraph g = new ModGraph();
        for(int i = 0; i < n; i++) g.add(new ArrayList<Edge>());
        for(int i = 0; i < m; ++i) {
            a = io.getInt();
            b = io.getInt();
            x = io.getInt();
            a--; b--;
            g.get(a).add(new Edge(new Mod(x), b));
            g.get(b).add(new Edge(new Mod(x), a));
        }
        io.println(calculate_resistance_exact(g, s, t).x);
        io.flush();
    }
}
