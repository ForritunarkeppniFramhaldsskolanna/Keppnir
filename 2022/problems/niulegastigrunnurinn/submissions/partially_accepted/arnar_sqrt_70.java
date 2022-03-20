import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_sqrt_70 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    long n = in.nextLong();
    long d = in.nextLong();
    
    long mx = 0;
    for(long b = 2; (b-3)*(b-3) <= n+1; b++)
    {
        int cnt = 0;
        long m = n;
        while(m > 0) {
            if (m % b == d) cnt++;
            m /= b;
        }
        if(mx < cnt) mx = cnt;
    }

    
    if(n > 2*d && mx < 1) mx = 1;
    if(n % d == 0 && n/d - 1 > d && mx < 2) mx = 2;
    if(n == d) mx = 1;
    if(d > n) mx = 0;
    out.println(mx);
    out.flush(); } }
