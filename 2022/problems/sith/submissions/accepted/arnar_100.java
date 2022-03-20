import java.util.*;
import java.lang.Math;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    String name = in.nextLine();
    int a = in.nextInt();
    int b = in.nextInt();
    int val = in.nextInt();

    if(a - b < 0) {
        if(val == a-b) {
            out.println("JEDI");
        }
        else if (val == Math.abs(a-b)) {
            out.println("SITH");
        }
    }
    else {
        out.println("VEIT EKKI");
    }
    
    out.flush(); } }
