import java.util.*;
import java.io.*;
public class unnar_100 {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);

        String s = in.next();
        if (s.contains("COV")){
            out.println("Veikur!");
        }
        else {
            out.println("Ekki veikur!");
        }

        out.flush();
    }
}
