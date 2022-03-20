import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int n = in.nextInt(), m = in.nextInt();
    
    int a = n/3+1;
    int b = a;
    int c = a;
    a++;
    if (n % 3 == 2) b++;
    boolean win = false;
    if (b+c > m) win = true;
    if(win) out.println("Arnar");
    else out.println("Unnar");

    out.flush(); } }
