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

public class atli_100 {
    public static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt(), q = io.getInt();
        int nonz = 1, range_sz = 1;
        int[] locs = new int[n];
        int[] ord_elem = new int[n];
        int[] sent = new int[n];
        int[] set_ind = new int[n];
        int[] ranges0 = new int[n];
        int[] ranges1 = new int[n];
        ranges0[0] = 0; ranges1[0] = n - 1;
        ArrayList<Integer> reuse = new ArrayList<Integer>();
        for(int i = 0; i < n; ++i) {
            locs[i] = i;
            ord_elem[i] = i;
            sent[i] = -1;
            set_ind[i] = 0;
        }
        for(int i = 0; i < q; ++i) {
            String op = io.getWord();
            if(op.equals("r")) {
                ArrayList<Integer> to_fix = new ArrayList<Integer>();
                int argnum = io.getInt();
                for(int j = 0; j < argnum; ++j) {
                    int it = io.getInt() - 1;
                    int ind = set_ind[it];
                    int sz = ranges1[ind] - ranges0[ind] + 1;
                    if(sz == 1 && sent[ind] == -1)
                        continue;
                    if(sent[ind] == -1) {
                        to_fix.add(ind);
                        int new_ind = range_sz;
                        nonz += 1;
                        if(reuse.size() > 0) {
                            new_ind = reuse.get(reuse.size() - 1);
                            reuse.remove(reuse.size() - 1);
                        } else {
                            ranges0[range_sz] = -1;
                            ranges1[range_sz] = -1;
                            range_sz += 1;
                        }
                        ranges0[new_ind] = ranges1[ind] + 1;
                        ranges1[new_ind] = ranges1[ind];
                        sent[ind] = new_ind;
                    }
                    ranges0[sent[ind]] -= 1;
                    ranges1[ind] -= 1;
                    if(ranges1[ind] < ranges0[ind]) {
                        reuse.add(ind);
                        nonz -= 1;
                    }
                    int to_swp = ord_elem[ranges0[sent[ind]]];
                    swap(locs, it, to_swp);
                    swap(ord_elem, locs[it], locs[to_swp]);
                    set_ind[it] = sent[ind];
                }
                for(Integer x : to_fix)
                    sent[x] = -1;
            } else if(op.equals("s")) {
                io.println(nonz);
            } else {
                int x = io.getInt() - 1;
                int s = set_ind[x];
                for(int y = ranges0[s]; y <= ranges1[s]; ++y) {
                    io.print(ord_elem[y] + 1);
                    if(y != ranges1[s])
                        io.print(" ");
                    else
                        io.println("");
                }
            }
        }
        io.close();
    }
}
