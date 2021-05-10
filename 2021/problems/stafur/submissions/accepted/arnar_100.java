import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    String c = in.next();
    String vowels = "AEIOU";
    if (c.equals("Y")) {
        out.println("Kannski");
    }
    else if(vowels.contains(c)) {
        out.println("Jebb");
    }
    else {
        out.println("Neibb");
    }
    out.flush(); } }
