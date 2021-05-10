import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int n = in.nextInt();
    
    for (int i = 0; i < n; i++)
    {
        String s = in.next();
        if (i == 12%n) {
            out.println(s);
        }
    }
    out.flush(); } }
