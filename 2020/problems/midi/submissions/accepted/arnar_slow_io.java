import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_slow_io {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int n = in.nextInt();
    
    ArrayList<String> notes = new ArrayList<String>();
    for(int i = 0; i < n; i++) {
        notes.add(in.next());
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = notes.get(i).length()-1; j >= 0; j--) {
            out.print(notes.get(i).charAt(j));
        }
    }
    out.print("\n");
    out.flush(); } }
