import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);
    
    int m = in.nextInt();
    int n = in.nextInt();
    double sm = 0;
    for (int i = 0; i < n; i++) {
        String s = in.next();
        for(int j = 0; j < m; j++) {
            if (s.charAt(j) == '.') {
                sm += 1;
            }
        }
    }
    out.printf("%.9f", sm/(m*n));

    out.flush(); 
  }
}
