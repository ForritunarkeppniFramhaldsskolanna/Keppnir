import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);
    
    long K = in.nextLong();
    long a = in.nextLong();
    long b = in.nextLong();
    
    ArrayList<Long> xs = new ArrayList<Long>(), ys = new ArrayList<Long>();
    long x = 0;
    while (x*a <= K) {
        long remainder = K - x*a;
        if (remainder % b == 0) {
            long y = remainder / b;
            xs.add(x);
            ys.add(y);
        }
        x += 1;
    }

    out.printf("%d\n", xs.size());
    for(int i = 0; i < xs.size(); i++) {
        out.printf("%d %d\n", xs.get(i), ys.get(i));
    }
    out.flush(); 
  }
}
