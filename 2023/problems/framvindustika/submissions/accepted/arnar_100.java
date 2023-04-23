import java.util.*;
import java.math.*;
import java.io.*;
import java.lang.StringBuilder;

public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int p = in.nextInt();
    int w = in.nextInt();

    int hashtags = p * w / 100;
    int dashes = w - hashtags;

    out.print("[");
    for (int i = 0; i < hashtags; i++) {
        out.print("#");
    }
    for (int i = 0; i < dashes; i++) {
        out.print("-");
    }
    out.print("] | ");
    if (p < 100) {
        out.print(" ");
    }
    if (p < 10) {
        out.print(" ");
    }
    out.print(p);
    out.println("%");
    out.flush(); 
  }
}
