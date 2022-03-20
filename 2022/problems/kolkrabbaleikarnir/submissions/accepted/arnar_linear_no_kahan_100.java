import java.util.*;
import java.lang.Math;
import java.io.*;
public class arnar_linear_no_kahan_100 {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);

        Integer n = in.nextInt();
        Integer m = in.nextInt();
        
        ArrayList<Double> fac_lg = new ArrayList<Double>();
        fac_lg.add(0.0);
        for(int i = 1; i < n+1; i++) {
            fac_lg.add(fac_lg.get(i-1) + Math.log(i));
        }

        double result = 0.0;
        for(int i = 0; i <= Math.min(n, m); i++) {
            double n_choose_i_lg = fac_lg.get(n) - fac_lg.get(n-i) - fac_lg.get(i);
            double two_to_n_lg = n * Math.log(2);
            double paths = Math.exp(n_choose_i_lg - two_to_n_lg);
            result += paths * (m - i);
        }

        out.println(result);
        out.flush();
    }
}
