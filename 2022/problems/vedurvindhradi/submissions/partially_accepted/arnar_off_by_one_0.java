import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_off_by_one_0 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    double n = in.nextDouble();
    
    if (0 <= n && n <= 0.2) {
        out.println("Logn");
    }
    else if (0.3 <= n && n <= 1.5) {
        out.println("Andvari");
    }
    else if (1.6 <= n && n <= 3.3) {
        out.println("Kul");
    }
    else if (3.4 <= n && n <= 5.4) {
        out.println("Gola");
    }
    else if (5.5 <= n && n <= 7.9) {
        out.println("Stinningsgola");
    }
    else if (8.0 <= n && n <= 10.7) {
        out.println("Kaldi");
    }
    else if (10.8 <= n && n <= 13.8) {
        out.println("Stinningskaldi");
    }
    else if (13.9 <= n && n <= 17.1) {
        out.println("Allhvass vindur");
    }
    else if (17.2 <= n && n <= 20.7) {
        out.println("Hvassvidri");
    }
    else if (20.8 <= n && n <= 24.4) {
        out.println("Stormur");
    }
    else if (24.5 <= n && n <= 28.4) {
        out.println("Rok");
    }
    // ERROR IN THIS CATEGORY
    else if (28.5 <= n && n <= 32.7) {
        out.println("Ofsavedur");
    }
    else if (32.7 <= n && n <= 200.0) {
        out.println("Farvidri");
    }
    else {
        out.println("WTF");
    }
    out.flush(); } }
