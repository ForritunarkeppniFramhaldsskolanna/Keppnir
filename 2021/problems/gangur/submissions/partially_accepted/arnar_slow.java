import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_slow {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    String c = in.next();
    long sm = 0L;
    for(int i = 0; i < c.length(); i++) {
        if(c.charAt(i) == '<') {
            for(int j = 0; j < i; j++)
            {
                if(c.charAt(j) == '>') {
                    sm++;
                }
            }
        }
    }
    out.println(sm);
    out.flush(); } }
