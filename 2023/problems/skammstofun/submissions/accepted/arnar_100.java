import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);
    
    int n = in.nextInt();

    for (int i = 0; i < n; i++) {
        String word = in.next();
        char first = word.charAt(0);
        if (Character.isUpperCase(first)) {
            out.print(first);
        }
    }
    out.println();

    out.flush(); 
  }
}
