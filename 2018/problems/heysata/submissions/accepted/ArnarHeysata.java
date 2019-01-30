import java.util.*;
import java.math.*;
import java.io.*;
public class ArnarHeysata {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);
        int n = in.nextInt();
        String k = in.next();
        String s = in.next();
        out.println((s.contains(k) ? "Unnar fann hana!" : "Unnar fann hana ekki!"));
        out.flush(); 
    } 
}
