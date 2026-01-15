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

class Ware {
    public final String name;
    public final Long cost;

    public Ware(String name, Long cost) {
        this.cost = cost;
        this.name = name;
    }
}

public class atli_100 {
    static class NameComparator implements Comparator<Ware> {
        public int compare(Ware w1, Ware w2) {
            return w1.name.compareTo(w2.name);
        }
    }

    static class CostComparator implements Comparator<Ware> {
        public int compare(Ware w1, Ware w2) {
            return w1.cost.compareTo(w2.cost);
        }
    }

    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int k = io.getInt(), n = io.getInt();
        Ware[] wares = new Ware[n];
        for(int i = 0; i < n; ++i) {
            String name = io.getWord();
            long cost = io.getLong();
            wares[i] = new Ware(name, cost);
        }
        Arrays.sort(wares, new CostComparator());
        int take = n / k;
        if(n % k != 0) {
            long sm1 = 0, sm2 = 0;
            for(int i = 0; i < n / k + 1; ++i)
                sm1 += wares[i].cost;
            for(int i = n / k + 1; i < 2 * (n / k) + 1; ++i)
                sm2 += wares[i].cost;
            if(sm1 < sm2) take += 1;
        }
        long cost = 0;
        for(int i = 0; i < take; ++i)
            cost += wares[i].cost;
        io.println(cost);
        Arrays.sort(wares, 0, take, new NameComparator());
        for(int i = 0; i < take; ++i)
            io.println(wares[i].name);
        io.close();
    }
}
