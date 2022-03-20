import java.util.*;
import java.math.*;
import java.io.*;

public class elvar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    String[] line1 = in.nextLine().split("\\|");
    String[] line2 = in.nextLine().split("\\|");
		
    out.printf("%s%s %s%s\n", line1[0], line2[0], line1[1], line2[1]);
    out.flush();
  }
}
