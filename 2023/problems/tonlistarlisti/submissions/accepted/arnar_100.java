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

class LazySegmentTree {
    private int listSize;
    private long[] tree;
    private long[] lazy;
    public LazySegmentTree(int listSize) {
        this.listSize = listSize;
        int size = (1 << (int) Math.ceil((Math.log(listSize) / Math.log(2)) + 1));
        tree =  new long[size];
        lazy =  new long[size];
        build(1, 0, listSize - 1);
    }

    private long build(int root, int l, int r) {
        if (l == r) {
            return tree[root] = 0;
        }
        long left = build(root * 2, l, (l + r) / 2);
        long right = build(root * 2 + 1, ((l + r) / 2) + 1, r);
        return tree[root] = tree[2 * root] + tree[2 * root + 1];
    }

    public void update(int pos, long x) {
        updateRange(pos, pos, x);
    }

    public void updateRange(int posL, int posR, long x) {
        update(posL, posR, x, 1, 0, listSize - 1);
    }

    private void updateLazy(int root, int left, int right) {
        if (lazy[root] != 0) {
            tree[root] += (right - left + 1) * lazy[root];
            if (left != right) {
                lazy[2 * root] += lazy[root];
                lazy[2 * root + 1] += lazy[root];
            }
            lazy[root] = 0;
        }
    }

    private void update(int posL, int posR, long x, int root, int left, int right) {
        updateLazy(root, left, right);
        if (left > right || left > posR || right < posL) {
            return;
        }

        if (left >= posL && right <= posR) {
            tree[root] += (right - left + 1) * x;
            if (left != right)
            {
                lazy[2 * root] += x;
                lazy[2 * root + 1] += x;
            }
            return;
        }

        int mid = (left + right) / 2;
        update(posL, posR, x, 2 * root, left, mid);
        update(posL, posR, x, 2 * root + 1, mid+1, right);
        tree[root] = tree[2 * root] + tree[2 * root + 1];
    }

    public long query(int pos) {
        return query(pos, pos);
    }
        
    public long query(int posL, int posR) {
        return query(posL, posR, 1, 0, listSize - 1);
    }

    private long query(int posL, int posR, int root, int left, int right) {
        updateLazy(root, left, right);
        if (left > right || left > posR || right < posL) {
            return 0;
        }
        if (left >= posL && right <= posR) {
            return tree[root];
        }
        int mid = (left + right) / 2;
        return query(posL, posR, 2*root, left, mid) + query(posL, posR, 2*root+1, mid+1, right);
    }
}


public class arnar_100 {
    static Kattio io;
    static PrintWriter err;

    public static void main(String[] args) throws Exception {
        io = new Kattio(System.in, System.out);
        err = new PrintWriter(System.err, false);

        int MAXSIZE = 500000;
        int q = io.getInt();

        long a[] = new long[MAXSIZE];
        long b[] = new long[MAXSIZE];

        HashMap<String, Integer> toId = new HashMap<String, Integer>();
        HashMap<String, Long> deleted = new HashMap<String, Long>();
        ArrayList<String> fromId = new ArrayList<String>();
        LazySegmentTree playCounts = new LazySegmentTree(MAXSIZE);
        LazySegmentTree songLengths = new LazySegmentTree(MAXSIZE);

        long totalLength = 0;


        int maxId = -1;

        for(int i = 0; i < q; i++)
        {
            String operation = io.getWord();
            if (operation.equals("P")) {
                long duration = io.getLong();
                long cycles = duration / totalLength;
                long remainder = duration % totalLength;
                playCounts.updateRange(0, maxId, cycles);

                int lo = 0, hi = maxId+1;
                int ans = maxId+1;
                while(lo <= hi) {
                    int mid = (lo+hi)/2;
                    if (songLengths.query(mid, maxId) <= remainder)
                    {
                        ans = mid;
                        hi = mid-1;
                    }
                    else
                    {
                        lo = mid+1;
                    }
                }
                playCounts.updateRange(ans, maxId, 1);
            }
            else if (operation.equals("L")) {
                String songName = io.getWord();
                long songLength = io.getLong();
                if (toId.containsKey(songName)) {
                    int oldId = toId.get(songName);
                    long length = songLengths.query(oldId);
                    songLengths.update(oldId, -length);
                    totalLength -= songLength;
                    deleted.put(songName, playCounts.query(oldId));
                    toId.remove(songName);
                    continue;
                }
                // add
                maxId++;
                if (deleted.containsKey(songName)) {
                    playCounts.update(maxId, deleted.get(songName));
                    deleted.remove(songName);
                }
                toId.put(songName, maxId);
                fromId.add(songName);
                songLengths.update(maxId, songLength);
                totalLength += songLength;
            }
            else if (operation.equals("Q")) {
                String songName = io.getWord();
                if (deleted.containsKey(songName)) {
                    io.printf("%d\n", deleted.get(songName));
                }
                else {
                    int id = toId.getOrDefault(songName, -1);
                    io.printf("%d\n", playCounts.query(id));
                }
            }
        }

        io.flush();
    }
}
