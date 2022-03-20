import java.util.*;
import java.math.*;
import java.io.*;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;


public class sammi_100 {
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


	public static void main(String[] args) throws Exception {
		Kattio in = new Kattio(System.in, System.out);
		PrintWriter out = new PrintWriter(System.out, false);

		int oc = 0;
		int xc = 0;
		for (int j = 0; j < 3; j++){
			String s = in.getWord();
			for (int i = 0; i < 3; i++){
				if (s.charAt(i) == 'O') oc += 1;
				else if (s.charAt(i) == 'X') xc += 1;
			}
		}
		
		if (oc == xc){
			out.println("Jebb");
		}else{
			out.println("Neibb");
		}
		out.flush(); 
		} 
}
