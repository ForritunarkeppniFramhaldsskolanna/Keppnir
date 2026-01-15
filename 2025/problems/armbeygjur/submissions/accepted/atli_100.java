import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

class Pair implements Comparable<Pair> {
    public final Long first;
    public final Long second;

    public Pair(Long first, Long second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Pair)) {
            return false;
        }
        Pair p = (Pair) o;
        return Objects.equals(p.first, first) && Objects.equals(p.second, second);
    }

    @Override
    public int hashCode() {
        return (first == null ? 0 : first.hashCode()) ^ (second == null ? 0 : second.hashCode());
    }

    public static Pair create(Long a, Long b) {
        return new Pair(a, b);
    }

    @Override
    public int compareTo(Pair o) {
        int result = first.compareTo(o.first);
        if (result == 0) {
            return second.compareTo(o.first);
        }
        return result;
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
    static long rho(long n) {
        long[] seeds = new long[]{ 2, 3, 5, 7, 11, 13, 1031 };
        for(int i = 0; i < 7; ++i) {
            BigInteger x = BigInteger.valueOf(seeds[i]);
            BigInteger y = BigInteger.valueOf(seeds[i]);
            BigInteger d = BigInteger.valueOf(1);
            BigInteger bn = BigInteger.valueOf(n);

            do {
                x = x.multiply(x).add(BigInteger.ONE).mod(bn);
                y = y.multiply(y).add(BigInteger.ONE).mod(bn);
                y = y.multiply(y).add(BigInteger.ONE).mod(bn);
                d = x.subtract(y).gcd(bn);
            } while ( d.compareTo(BigInteger.ONE) == 0 );
            
            if(d == bn) continue;
            return d.longValue();
        }
        return -1;
    }

    static int[] calceratos() {
        int[] eratos = new int[100000];
        for(int i = 0; i < 100000; ++i)
            eratos[i] = i;
        for(int i = 2; i * i < 100000; ++i) {
            if(eratos[i] == i) {
                for(long j = i * i; j < 100000; j += i) {
                    eratos[(int) j] = i;
                }
            }
        }
        return eratos;
    }

    static HashMap<Long,Long> factors(long x, int[] eratos) {
        HashMap<Long,Long> cnt = new HashMap<Long,Long>();
        for(long i = 2; i < 100000; ++i) {
            if(eratos[(int) i] != i) continue;
            while(x % i == 0) {
                x /= i;
                cnt.put(i, cnt.getOrDefault(i, 0L) + 1);
            }
        }
        ArrayList<Long> st = new ArrayList<Long>();
        st.add(x);
        while(st.size() > 0) {
            long y = st.get(st.size() - 1);
            st.remove(st.size() - 1);
            if(y == 1) continue;
            if(cnt.containsKey(y) || BigInteger.valueOf(y).isProbablePrime(10)) {
                cnt.put(y, cnt.getOrDefault(y, 0L) + 1);
            } else {
                long d = rho(y);
                st.add(d);
                st.add(y / d);
            }
        }
        return cnt;
    }

    static void divgen(ArrayList<Pair> facs, ArrayList<Long> res, long x, int i) {
        if(i == facs.size()) {
            res.add(x);
            return;
        }
        long curpow = x;
        for(int j = 0; j <= facs.get(i).second; ++j) {
            divgen(facs, res, curpow, i + 1);
            curpow *= facs.get(i).first;
        }
    }

    static ArrayList<Long> odd_divisors(long x) {
        int[] eratos = calceratos();
        HashMap<Long,Long> fac = factors(x, eratos);
        ArrayList<Pair> facvec = new ArrayList<Pair>();
        ArrayList<Long> res = new ArrayList<Long>();
        for(Map.Entry<Long,Long> entry : fac.entrySet()) {
            if(entry.getKey() != 2) {
                facvec.add(Pair.create(entry.getKey(), entry.getValue()));
            }
        }
        divgen(facvec, res, 1, 0);
        return res;
    }

    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        long x = io.getLong();
        ArrayList<Pair> outp = new ArrayList<Pair>();
        ArrayList<Long> odiv = odd_divisors(x);
        for(Long y : odiv) {
            long f = x / y - (y - 1) / 2;
            if(f < 1) {
                y -= -2 * f + 1;
                f = -f + 1;
            }
            outp.add(Pair.create(f, y));
        }
        Collections.sort(outp);
        for(Pair p : outp) {
            io.print(p.first);
            io.print(" ");
            io.print(p.second);
            io.print("\n");
        }
        io.close();
    }
}
