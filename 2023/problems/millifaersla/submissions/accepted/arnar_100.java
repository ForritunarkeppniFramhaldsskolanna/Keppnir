import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int a = in.nextInt();
    int b = in.nextInt();
    int c = in.nextInt();
    if (a < b && a < c)
    {
        out.println("Monnei");
    }
    else if (b < a && b < c)
    {
        out.println("Fjee");
    }
    else
    {
        out.println("Dolladollabilljoll");
    }
    out.flush(); 
  }
}
