import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int n = in.nextInt();
    int m = in.nextInt();
    in.nextLine();
    ArrayList<Integer> x = new ArrayList<Integer>();
    ArrayList<Integer> y = new ArrayList<Integer>();
    for(int i = 0; i < n; i++) {
        String s = in.nextLine();
        for(int j = 0; j < m; j++) {
            if(s.charAt(j) == '*') {
                x.add(j);
                y.add(i);
            }
        }
    }

    out.println(x.size());
    for(int i = 0; i < x.size(); i++) {
        out.print(y.get(i)+1);
        out.print(" ");
        out.println(x.get(i)+1);
    }

    out.flush(); } }
