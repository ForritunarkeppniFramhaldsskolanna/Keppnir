import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int n = in.nextInt();
    
    if (n % 10 == 0) {
        out.println("Jebb");
    }
    else {
        out.println("Neibb");
    }
    out.flush(); } }
