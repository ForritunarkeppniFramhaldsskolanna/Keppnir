import java.util.*;
import java.io.*;
public class sammi_100 {
  static long mod = (long) Math.pow(10, 9) + 7;
  public static long[][] matrix_mul(long[][] A, long[][] B){
    long[][] res = new long[A.length][B[0].length];

    for (int i = 0; i < A.length; i++){
      for (int j = 0; j < B[0].length; j++){
        for (int k = 0; k < A.length; k++){
          res[i][j] += (A[i][k] * B[k][j]) % mod;
          res[i][j] %= mod;
        }
      }
    }

    return res;
  }

  public static long[][] matrix_mod_pow(long[][] A, long k){
    long[][] res = {{1, 0}, {0, 1}};

    while (k > 0){
      if (k % 2 == 1){
        res = matrix_mul(res, A);
        k--;
      }
      k /= 2;
      A = matrix_mul(A, A);
    }

    return res;
  }
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    long a = in.nextLong();
    long b = in.nextLong();

    long n = in.nextLong();

    in.close();
    
    long[][] A = {{1, 1}, {1, 0}};
    long[][] B = {{b}, {a}};

    long[][] res = matrix_mod_pow(A, 2*n);
    long[][] ans = matrix_mul(res, B);

    out.print(ans[1][0]);
    out.print(' ');
    out.print(ans[0][0]);

    
    out.println();
    out.flush();}}