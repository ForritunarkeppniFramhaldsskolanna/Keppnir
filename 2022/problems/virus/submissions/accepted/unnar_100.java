import java.util.*;
import java.lang.Math;
import java.io.*;

public class unnar_100{
    final static int N = 1000100;
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);
        String s = in.next();
        int n = s.length();
        int cnt = 0, cnt2 = 0, cnt_same = 0;
        char last = '0';
        int[] dec = new int[N];
        int[] inc = new int[N];
        int[] compr = new int[N];
        int[] rev = new int[N];
        for(int i = 0; i < n+3; i++){
            compr[i] = 0;
        }
        dec[0] = 1;
        int k = 0;
        for(int i = 0; i < n; i++) {
            if (s.charAt(i) > last) cnt = 0;
            if (s.charAt(i) < last) cnt2 = 0;
            if (i != 0 && s.charAt(i) != last) {
                k++;
                cnt_same = 0;
            }
            rev[i] = k;
            compr[k] = ++cnt_same;
            dec[i] = ++cnt;
            inc[i] = ++cnt2;
            last = s.charAt(i);
        }
        int ans = 0;  
        int mxDec = 0, mxInc = 0, mxOnes = 0, tmpInc = 0;
        for (int i = n-1; i >= 0; i--) { 
            int r = rev[i];
            if (s.charAt(i) == '1') {
                // flip this segment of ones to the segment of ones after it that is biggest (mx2)
                ans = Math.max(ans, compr[r]+compr[r+1]+mxOnes);
                mxOnes = Math.max(mxOnes, compr[r]);
                mxInc = Math.max(mxInc, tmpInc);
                tmpInc = inc[i];
                i -= compr[r] - 1;
                continue;
            }
            // flip only the very next segment of zeros and ones as then you also gain the next segment of ones after it
            ans = Math.max(ans, compr[r]+compr[r+1]+compr[r+2]+compr[r+3]);
            //cout << i << " " << r << " " << ans << endl;
            // flip the sequence behind this sequence of zeros to the best sequence of 1-0 after it
            ans = Math.max(ans, compr[r]+mxDec);
            // flip this sequence of zeros infront of the best sequence of 0-1 after it
            ans = Math.max(ans, compr[r]+mxInc);
            // sacrifice this 0 to take the highest number of 1's after it instead
            if (r > 1) ans = Math.max(ans, compr[r-1] + compr[r-2] + mxOnes);
            mxDec = Math.max(mxDec, dec[i]);
            //cout << i << " " << ans << endl;
            i -= compr[r] - 1;
        }
        out.println(ans);
        out.flush();
    }
}
