import java.util.*;
import java.math.*;
import java.io.*;
public class ArnarMork {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);
        int n = in.nextInt();
        int m = in.nextInt();
        if(m == 0 || (m == 2 && n == 2)) {
            out.println("Jebb");
        }
        else {
            out.println("Neibb");
        }
        out.flush();
    } 
}
