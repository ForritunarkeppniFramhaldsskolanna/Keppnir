import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    double v = in.nextDouble();
    double a = in.nextDouble();
    double t = in.nextDouble();
    
    out.println(String.format("%.9f", v*t + a*t*t/2));
    out.flush(); } }
