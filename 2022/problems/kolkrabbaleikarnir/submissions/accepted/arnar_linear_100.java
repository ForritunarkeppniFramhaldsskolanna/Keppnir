import java.util.*;
import java.lang.Math;
import java.io.*;
public class arnar_linear_100 {
    public static class kahan {
        private double sm, c;
        public kahan() {
            sm = 0.0;
            c = 0.0;
        }
        void add_val(double d) {
            double y = d - c;
            double t = sm + y;
            c = (t - sm) - y;
            sm = t;
        }
        public double get_sm() {
            return sm;
        }
    }
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);

        Integer n = in.nextInt();
        Integer m = in.nextInt();
        
        ArrayList<Double> fac_lg = new ArrayList<Double>();
        kahan sm = new kahan();
        fac_lg.add(sm.get_sm());
        for(int i = 1; i < n+1; i++) {
            sm.add_val(Math.log((double) i));
            fac_lg.add(sm.get_sm());
        }

        kahan result = new kahan();
        for(int i = 0; i <= Math.min(n, m); i++) {
            double n_choose_i_lg = fac_lg.get(n) - fac_lg.get(n-i) - fac_lg.get(i);
            double two_to_n_lg = n * Math.log(2.0);
            double paths = Math.exp(n_choose_i_lg - two_to_n_lg);
            result.add_val(paths * (m - i));
        }

        out.println(result.get_sm());
        out.flush();
    }
}
