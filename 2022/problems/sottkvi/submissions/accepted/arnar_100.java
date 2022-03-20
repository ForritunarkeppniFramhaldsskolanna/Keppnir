import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {

  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int n = in.nextInt();
    int k = in.nextInt();
    int d = in.nextInt();
    int birthday = k+d;

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int start = in.nextInt();
        if (birthday >= start && birthday < start+14) {
            cnt++;
        }
    }

    out.println(n-cnt);
    out.flush(); } }
