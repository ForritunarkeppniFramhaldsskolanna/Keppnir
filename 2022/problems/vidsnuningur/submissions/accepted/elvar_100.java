import java.util.*;
import java.math.*;
import java.io.*;

public class elvar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    String line = in.nextLine();
		
    out.printf("%s\n", new StringBuilder(line).reverse().toString());
    out.flush();
  }
}
