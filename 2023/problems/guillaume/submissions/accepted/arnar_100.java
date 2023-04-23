import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int n = in.nextInt();

    String s = in.next();
    
    int wins = 0, losses = 0, draws = 0;

    int bestwin = 0;
    int bestloss = 0;
    double best = -1;
    for(int i = n-1; i >= 0; i--) {
        char c = s.charAt(i);
        if (c == 'G') {
            wins++;
        }
        else if(c == 'A') {
            losses++;
        }
        else {
            draws++;
        }
        double cur = wins + losses == 0 ? 0.0 : 1.0 * wins / (wins + losses);
        if (cur > best) {
            best = cur;
            bestwin = wins;
            bestloss = losses;
        }
    }
    out.print(bestwin);
    out.print("-");
    out.println(bestloss);
    out.flush(); } }
