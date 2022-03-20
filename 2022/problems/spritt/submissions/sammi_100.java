import java.util.*;
import java.math.*;
import java.io.*;
public class sammi_100 {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);

        int n = in.nextInt();
        int x = in.nextInt();

        int sm = 0;

        for (int i = 0; i < n; i++){
            sm += in.nextInt();
        }


        if (x >= sm){
            out.println("Jebb");
        } else {
            out.println("Neibb");
        }
        out.flush(); 
    } 
}
