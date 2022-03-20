import java.util.*;
import java.math.*;
import java.io.*;

public class arnar_rounded_to_1_place_WA_0 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int n = in.nextInt();

    out.println(String.format("%.1f", n * 0.09144));
    out.flush();
  }
}
