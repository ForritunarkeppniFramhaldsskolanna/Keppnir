import java.util.*;

public class bjarni_100
{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        final long INF = 12 * 100000000;

        long[] thresholds = {409986, 1151012, INF};
        double[] percentages = {31.45, 37.95, 46.25};

        double l = in.nextDouble();
        double s = in.nextDouble();

        long[] salary = new long[12];
        for (int i = 0; i < 12; i++) {
            salary[i] = in.nextInt();
        }

        long d = 59665;

        long discount_left = 0, ans = 0;
        for (int i = 0; i < 12; i++) {
            long amount = salary[i];
            discount_left += d;

            long pension = (long)(amount * l / 100.0);
            long saving = (long)(amount * s / 100.0);
            long tax_base = amount - pension - saving;

            double withholding = 0.0;
            long left = tax_base, last_threshold = 0;
            for (int j = 0; j < thresholds.length; j++) {
                if (left <= 0)
                    break;
                long a = thresholds[j];
                double p = percentages[j];
                long in_bracket = Math.min(left, a - last_threshold);
                withholding += in_bracket * p / 100.0;
                left -= in_bracket;
                last_threshold = a;
            }
            long withholding_rounded = (long)withholding;
            long discount_to_use = Math.min(discount_left, withholding_rounded);
            discount_left -= discount_to_use;
            long after_tax = tax_base - withholding_rounded + discount_to_use;
            ans += after_tax;
        }
        System.out.println(ans);
    }
}
