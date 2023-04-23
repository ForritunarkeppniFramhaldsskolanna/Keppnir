import java.util.*;
import java.math.*;
import java.io.*;
public class atli_step_translated_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);
    
    double EPS = 1e-9;
    int n = in.nextInt();
    double sx = 0, sy = 0;
    ArrayList<String> colour = new ArrayList<String>();
    ArrayList<Double> xs = new ArrayList<Double>();
    ArrayList<Double> ys = new ArrayList<Double>();
    for (int i = 0; i < n; i++) {
        String s = in.next();
        double x = in.nextDouble();
        double y = in.nextDouble();
        colour.add(s);
        xs.add(x);
        ys.add(y);
        if (s.equals("white")) {
            sx = x;
            sy = y;
        }
    }
    String target = in.next();
    double vx = in.nextDouble();
    double vy = in.nextDouble();
    for(int stp = 0; stp < 1000005; stp++) {
        sx += vx * 1e-6;
        sy += vy * 1e-6;
        if(sx < 1 - EPS) {
            vx = -vx;
            sx = 2 - sx;
        }
        if(sx > 69 + EPS) {
            vx = -vx;
            sx = 138 - sx;
        }
        if(sy < 1 - EPS) {
            vy = -vy;
            sy = 2 - sy;
        }
        if(sy > 139.5 + EPS) { 
            vy = -vy;
            sy = 279 - sy;
        }
        for(int i = 0; i < n; ++i) {
            if(colour.get(i).equals("white")) continue;
            if((xs.get(i) - sx) * (xs.get(i) - sx) + (ys.get(i) - sy) * (ys.get(i) - sy) < 4) {
                if(colour.get(i).equals(target)) out.println("HIT");
                else out.println("FOUL");
                out.flush();
                return;
            }
        }
    }
    out.println("MISS");
    out.flush();

  }
}


