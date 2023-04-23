import java.util.*;
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

public class sammi_100 {
    static List<List<Integer>> ask = new ArrayList<List<Integer>>();

    public static void rec(int i, int l, int h){
        if (h - l <= 1){
            return;
        }

        int m = (l + h + 1)/2;

        for (int j = l; j < m; j++){
            ask.get(i).add(j + 1);
        }

        rec(i+1, l, m);
        rec(i+1, m, h);
    }
    public static void main(String[] args) throws Exception {
        Kattio io = new Kattio(System.in, System.out);

        int n = io.getInt();

        for (int i = 0; i < 30; i++){
            List<Integer> row = new ArrayList<Integer>();
            ask.add(row);
        }

        int[] ans = new int[n];

        rec(0, 0, n);

        for (int i = 0, s = ask.get(i).size(); s > 0; s = ask.get(++i).size()){
            io.print("? " + s + " ");

            for (int j = 0; j < s; j++){
                io.print(ask.get(i).get(j) + " ");
            }
            io.println();
            io.flush();

            for (int j = 0; j < n; j++){
                ans[j] <<= 1;
            }

            for (int j = 0; j < s; j++){
                int temp = io.getInt();
                ans[temp-1] += 1;
            }

        }

        int[] to_print = new int[2*n];

        for (int i = 0; i < 2*n; i++){
            to_print[i] = -1;
        }

        for (int i = 0; i < n; i++){
            to_print[ans[i]] = i + 1;
        }

        io.print("!");

        for (int i = 2 * n - 1; i >= 0; i--){
            if (to_print[i] != -1){
                io.print(" " + to_print[i]);
            }
        }

        io.println();
        io.flush();
    }
}