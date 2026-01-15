import java.util.*;
import java.io.*;

public class no_kattio {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);
        int n = in.nextInt();
        HashSet<String> book = new HashSet<String>();
        for(int i = 0; i < n; ++i) {
            String op = in.next();
            String name = in.next();
            if(op.equals("+")) {
                book.add(name);
            } else if(op.equals("-")) {
                book.remove(name);
            } else if(op.equals("?")) {
                out.println(book.contains(name) ? "Jebb" : "Neibb");
            }
        }
        out.flush();
    }
}
