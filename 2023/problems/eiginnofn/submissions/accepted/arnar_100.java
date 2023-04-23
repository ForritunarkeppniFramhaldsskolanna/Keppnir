import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int n = in.nextInt();
    in.nextLine();
    HashMap<String, String> home = new HashMap<String, String>();
    for (int i = 0; i < n; i++) {
        String line = in.nextLine();
        String[] names = line.split(" ");
        if (names.length == 1) {
            home.put(line, "");
        }
        else {
            home.put(names[0], names[1]);
        }
    }

    int m = in.nextInt();
    in.nextLine();
    for (int i = 0; i < m; i++) {
        String name = in.next();
        if (home.containsKey(name)) {
            if (home.get(name).equals("")) {
                out.println("Jebb");
            }
            else {
                out.printf("Neibb en %s %s er heima\n", name, home.get(name));
            }
        }
        else {
            out.println("Neibb");
        }
    }

    out.flush(); 
  }
}
