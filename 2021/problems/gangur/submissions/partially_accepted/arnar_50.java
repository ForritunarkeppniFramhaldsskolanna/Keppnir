import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_50 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    String c = in.next();
    long right = 0L;
    long left = 0L;
    for(int i = 0; i < c.length(); i++) {
        if(c.charAt(i) == '<') {
            left += 1L;
        }
        else if(c.charAt(i) == '>') {
            right += 1L;
        }
    }
    out.println(left*right);
    out.flush(); } }
