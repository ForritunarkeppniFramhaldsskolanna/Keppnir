import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    String key = "ub";
    String vowels = "aeiouy";

    String mode = in.next();
    int n;
    n = in.nextInt();
    
    while(in.hasNext()) {
        String token = in.next().toLowerCase();
        if (mode.equals("D")) {
            for(int i = 0; i < token.length(); i++)
            {
                if(vowels.indexOf(token.charAt(i)) != -1) {
                    out.print(key);
                }
                out.print(token.charAt(i));
            }
        }
        else {
            for(int i = 0; i < token.length(); i++)
            {
                if(i < token.length() - key.length() && token.substring(i, i+key.length()).equals(key)) {
                    i += key.length();
                }
                out.print(token.charAt(i));
            }
        }
        out.print(' ');
    }
    out.println();
    out.flush(); } }
