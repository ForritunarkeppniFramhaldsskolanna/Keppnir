import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
    static class Kattio extends PrintWriter {
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

    private static long res = 0;
    public static void merge_sort(ArrayList<Integer> arr) {
        ArrayList<Integer> work = new ArrayList<Integer>(arr);
        split_merge(work, 0, work.size()-1, arr);
    }

    public static void split_merge(ArrayList<Integer> work, int l, int r, ArrayList<Integer> arr) {
        if(r <= l) return;
        int m = (r+l)/2;
        split_merge(arr, l, m, work);
        split_merge(arr, m+1, r, work);
        merge(work, l, m, r, arr);
    }
    public static void merge(ArrayList<Integer> arr, int l, int m, int r, ArrayList<Integer> work) {
        int lat = l, rat = m+1;
        
        for(int k = l; k <= r; k++) {
            if (lat <= m && (rat > r || arr.get(lat) <= arr.get(rat))) {
                res += (rat - (m+1));
                work.set(k, arr.get(lat));
                lat++;
            }
            else {
                work.set(k, arr.get(rat));
                rat++;
            }
        }
    }
    public static void main(String[] args) throws Exception {
        Kattio io = new Kattio(System.in, System.out);

        int n = io.getInt();

        ArrayList<Integer> houses = new ArrayList<Integer>();
        ArrayList<Integer> garages = new ArrayList<Integer>();

        for(int i = 0; i < n; i++) {
            houses.add(io.getInt()-1);
        }

        ArrayList<Integer> inv_houses = new ArrayList<Integer>();
        for(int i = 0; i < n; i++) {
            inv_houses.add(0);
        }
        for(int i = 0; i < n; i++) {
            inv_houses.set(houses.get(i), i);
        }
        for(int i = 0; i < n; i++) {
            garages.add(inv_houses.get(io.getInt()-1));
        }

        res = 0;

        merge_sort(garages);

        io.println(res);
        io.close(); 
    } 
}
