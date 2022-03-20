import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_naive_40 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    long n = in.nextLong();
    long d = in.nextLong();
    
    int mx = 0;
    for(long b = 2; b <= n+1; b++)
    {
        int cnt = 0;
        long m = n;
        while(m > 0) {
            if (m % b == d) cnt++;
            m /= b;
        }
        if(mx < cnt) mx = cnt;
    }

    out.println(mx);
    out.flush(); } }
