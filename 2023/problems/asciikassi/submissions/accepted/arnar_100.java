import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);
    
    int n = in.nextInt();

    for(int i = 0; i < n+2; i++)
    {
        boolean hline = i == 0 || i == n+1;
        for(int j = 0; j < n+2; j++)
        {
            boolean vline = j == 0 || j == n+1;
            if (hline && vline) out.print('+');
            else if (hline) out.print('-');
            else if (vline) out.print('|');
            else out.print(' ');
        }
        out.println();
    }
    out.flush(); 
  }
}
