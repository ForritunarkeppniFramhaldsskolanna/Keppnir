import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

class Kattio extends PrintWriter
{
    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int getInt() {
        return Integer.parseInt(nextToken());
    }

    public double getDouble() {
        return Double.parseDouble(nextToken());
    }

    public long getLong() {
        return Long.parseLong(nextToken());
    }

    public String getWord() {
        return nextToken();
    }

    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null)
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null)
                        return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            }
            catch (IOException e) {
            }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}

public class atli_100 {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        int h = io.getInt(), w = io.getInt();
        String[] inp = new String[h];
        for(int i = 0; i < h; ++i)
            inp[i] = io.getWord();
        int s_x = -1, s_y = -1;
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(inp[i].charAt(j) == 'S') {
                    s_x = i;
                    s_y = j;
                }
            }
        }
        int[][] dst = new int[h][w];
        for(int[] arr : dst)
            Arrays.fill(arr, 1_000_000_000);
        dst[s_x][s_y] = 0;
        Queue<Integer> q = new ArrayDeque<Integer>();
        q.add(s_x * w + s_y);
        while(q.size() > 0) {
            int x = q.peek() / w;
            int y = q.poll() % w;
            int[] dx = new int[]{ 0, 0, 1, -1 };
            int[] dy = new int[]{ 1, -1, 0, 0 };
            for(int di = 0; di < 4; ++di) {
                int nx = x + dx[di];
                int ny = y + dy[di];
                if(nx < 0 || ny < 0) continue;
                if(nx >= h || ny >= w) continue;
                if(dst[nx][ny] <= dst[x][y] + 1) continue;
                if(inp[nx].charAt(ny) == '#') continue;
                dst[nx][ny] = dst[x][y] + 1;
                q.add(w * nx + ny);
            }
        }
        int bst = 1_000_000_000;
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(inp[i].charAt(j) == 'G') {
                    bst = Math.min(bst, dst[i][j]);
                }
            }
        }
        if(bst != 1_000_000_000) io.println(bst);
        else io.println("thralatlega nettengdur");
        io.close();
    }
}
