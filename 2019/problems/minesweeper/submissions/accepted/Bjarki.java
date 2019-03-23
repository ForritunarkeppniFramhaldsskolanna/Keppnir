import java.util.*;
import java.math.*;
import java.io.*;

public class Bjarki {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);

        int n = in.nextInt(),
            m = in.nextInt(),
            k = in.nextInt();

        char[][] arr = new char[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = '.';
            }
        }

        for (int i = 0; i < k; i++) {
            int x = in.nextInt(),
                y = in.nextInt();
            x--;
            y--;
            arr[x][y] = '*';
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                out.print(arr[i][j]);
            }
            out.println();
        }

        out.flush();
    }
}

