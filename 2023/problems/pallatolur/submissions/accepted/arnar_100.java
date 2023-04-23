import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int a = in.nextInt();
    int b = in.nextInt();

    if(a <= 2 && 2 <= b) {
        out.println(1);
        out.println(2);
    }
    else {
        out.println(":(");
    }
    
    out.flush(); } }
