import java.util.*;
import java.math.*;
import java.io.*;
public class ArnarStarWars {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);
        int n = in.nextInt();
        //ArrayList<Integer> arr = new ArrayList<Integer>(n);
        int[] arr = new int[n];
        for(int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }
        Arrays.sort(arr);
        for(int i = n/3; i < 2*n/3; i++) { out.print((i == n/3 ? "" : " ") + arr[i]); }
        for(int i = 0; i < n/3; i++) { out.print(" " + arr[i]); }
        for(int i = 2*n/3; i < n; i++) { out.print(" " + arr[i]); }
        out.println();
        out.flush(); 
    } 
}
