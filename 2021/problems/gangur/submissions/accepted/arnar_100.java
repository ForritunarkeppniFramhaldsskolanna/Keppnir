import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    String c = in.next();
    long right = 0L;
    long sm = 0L;
    for(int i = 0; i < c.length(); i++) {
        if(c.charAt(i) == '<') {
            sm += right;
        }
        else if(c.charAt(i) == '>') {
            right += 1L;
        }
    }
    out.println(sm);
    out.flush(); } }
