import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);
    int n = in.nextInt();
    out.printf("0.");
    for(int i = 0; i < n-1; i++) {
        out.printf("0");
    }
    out.println("1");
    out.flush(); 
  }
}
