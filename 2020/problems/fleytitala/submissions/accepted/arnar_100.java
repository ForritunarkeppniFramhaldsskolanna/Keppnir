import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    double d = in.nextDouble();
    long k = in.nextLong();
    
    if(k > 40) out.println(2*d);
    else
    {
        double sm = d, nxt = d;
        for(int i = 0; i < k; i++)
        {
            nxt /= 2;
            sm += nxt;
        }
        out.println(sm);
    }
    out.flush(); } }
