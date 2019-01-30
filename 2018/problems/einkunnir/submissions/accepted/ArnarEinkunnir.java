import java.util.*;
import java.math.*;
import java.io.*;
public class ArnarEinkunnir {
    public static double f(double n) {
        int i = (int)(n*20);
        if(i % 10 >= 5) return (double)(i+10-i%10)/20;
        else return (double)(i-i%10)/20;
    }
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);
        int s = in.nextInt(), n = in.nextInt();
        String[] correct = new String[s];
        for(int i = 0; i < s; i++) {
            correct[i] = in.next();
        }
        for(int i = 0; i < n; i++) {
            String name = in.next();
            String answer;
            int cnt = 0;
            for(int j = 0; j < s; j++) {
                answer = in.next();
                if(answer.equals(correct[j])) cnt++;
            }
            double grade = f((10.0*cnt)/s);
            out.println(String.format("%s: %.1f", name, grade));
        } 
        out.flush(); 
    } 
}
