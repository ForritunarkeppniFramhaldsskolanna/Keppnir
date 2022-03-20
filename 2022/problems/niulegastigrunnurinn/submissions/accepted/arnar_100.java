import java.util.*;
import java.lang.Math;
import java.io.*;
public class arnar_100 {
    public static boolean is_sqrt(long val)
    {
        long x = (long)Math.sqrt(val);
        return x*x == val;
    }
    public static long jonas(long a, long b, long c)
    {
        long d = b*b - 4*a*c;
        if(d < 0) return -1;
        if(is_sqrt(d))
        {
            long num1 = -b + (long)Math.sqrt(d);
            long den1 = 2*a;
            long num2 = -b - (long)Math.sqrt(d);
            long den2 = 2*a;
            if (num1 % den1 == 0 && num1 / den1 > 0)
            {
                return num1/den1;
            }
            else if (num2 % den2 == 0 && num2 / den2 > 0)
            {
                return num2/den2;
            }
        }
        return -1;
    }
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);

        long n = in.nextLong();
        long d = in.nextLong();

        long mx = 0;
        for(long b = 2; (b-3)*(b-3)*(b-3) <= n+1; b++)
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

        // i*g^2 + d*g + d = n => i*g^2 + d*g + (d-n) = 0
        // d*g^2 + i*g + d = n => d*g^2 + i*g + (d-n) = 0
        // d*g^2 + d*g + i = n => d*g^2 + d*g + (i-n) = 0
        for(long i = 0; (i - 3) * (i - 3) * (i - 3) <= n; i++)
        {
            long b;
            if(i > 0) {
                b = jonas(i, d, d-n);
                if(b > 0 && i*b*b + d*b + d == n && mx < 2) mx = 2;
            }
            b = jonas(d, i, d-n);
            if(b > 0 && d*b*b + i*b + d == n && mx < 2) mx = 2;
            b = jonas(d, d, i-n);
            if(b > 0 && d*b*b + d*b + i == n && mx < 2) mx = 2;
        }

        if(n == d) mx = 1;
        if(d > n) mx = 0;


        out.println(mx);
        out.flush(); } }
