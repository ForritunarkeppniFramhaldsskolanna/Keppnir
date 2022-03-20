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

class Sandwich implements Comparable<Sandwich> {
    public int quality, expiration;
    public Sandwich(int q, int e) {
        quality = q;
        expiration = e;
    }

    @Override
    public int compareTo(Sandwich other) {
        return Integer.compare(expiration, other.expiration);
    }
}

public class arnar_100 {
    static Kattio io;
    public static boolean solve() {
        io = new Kattio(System.in, System.out);

        int n = io.getInt(), k = io.getInt();
        ArrayList<Sandwich> sandwiches = new ArrayList<Sandwich>();
        ArrayList<Sandwich> low = new ArrayList<Sandwich>();
        ArrayList<Sandwich> high = new ArrayList<Sandwich>();
        for (int i = 0; i < n; i++) {
            Sandwich cur = new Sandwich(io.getInt(), 0);
            sandwiches.add(cur);
        }
        for (int i = 0; i < n; i++) {
            Sandwich cur = sandwiches.get(i);
            cur.expiration = io.getInt();
            // Good sandwiches
            if(cur.quality > 4) high.add(cur);
            // ok sandwiches
            else if(cur.quality == 4) low.add(cur);
        }

        // sort by expiry date in ascending order
        Collections.sort(low);
        Collections.sort(high);
        
        int i = k;
        int a = high.size()-1, b = low.size()-1;
        // then loop backwards through sandwiches,
        // taking the longest lasting good sandwich first
        while(i > 0) {
            if (a < 0) {
                // nothing to eat
                return false;
            }
            Sandwich s1 = high.remove(a);
            a--;
            if (s1.expiration < i) {
                // the longest lasting good sandwich is expired
                //  at this day, all others are as bad or worse
                return false;
            }
            // otherwise Atli eats this sandwich
            // Atli then wants to use an ok 
            // sandwich if possible, since he can
            if (b >= 0 && low.get(b).expiration >= i) {
                low.remove(b);
                b--;
            }
            else if(a >= 0 && high.get(a).expiration >= i) {
                high.remove(a);
                a--; 
            }
            else {
                // neither ok nor good sandwich eaten
                return false;
            }

            i--;
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        if(solve()) io.println("Jebb");
        else io.println("Neibb");
        io.flush(); 
    }
}
