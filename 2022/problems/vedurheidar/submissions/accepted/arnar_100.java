import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int v = in.nextInt();
    int n = in.nextInt();

    for(int i = 0; i < n; i++) {
        String name = in.next();
        int bound = in.nextInt();
        String safe = "opin";
        if (v > bound) {
            safe = "lokud";
        }
        out.printf("%s %s\n", name, safe);
    }

    out.flush(); } }
