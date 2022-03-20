import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_90 {
    public static class Pair<K, V> {
        private final K element0;
        private final V element1;

        public static <K, V> Pair<K, V> createPair(K element0, V element1) {
            return new Pair<K, V>(element0, element1);
        }

        public Pair(K element0, V element1) {
            this.element0 = element0;
            this.element1 = element1;
        }

        public K getElement0() {
            return element0;
        }

        public V getElement1() {
            return element1;
        }

        @Override
        public boolean equals(Object o) {
            if(this == o) return true;
            if(o instanceof Pair) {
                Pair p = (Pair)o;
                return Objects.equals(this.element0, p.element0) && Objects.equals(this.element1, p.element1);
            }
            return false;
        }

        @Override
        public int hashCode()
        {
            return Objects.hash(element0, element1);
        }
    }

    private static HashMap<Pair<Integer, Integer>, Double> mem = new HashMap<>();

    public static Double E(Integer rows, Integer people) {
        if(people == 0) return 0.0;
        if(rows == 0) return 1.0*people;
        Pair<Integer, Integer> state = Pair.createPair(rows, people);
        Double result = mem.get(state);
        if (result == null) {
            result = (E(rows-1, people) + E(rows-1, people-1)) * 0.5;
            mem.put(state, result);
        }
        return result;
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);

        Integer n = in.nextInt();
        Integer m = in.nextInt();

        double[][] arr = new double[1001][1001];
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(j == 0) arr[i][j] = 0.0;
                else if(i == 0) arr[i][j] = 1.0*j;
                else arr[i][j] = (arr[i-1][j] + arr[i-1][j-1]) / 2.0;
            }
        }

        //out.println(E(n, m));
        out.println(arr[n][m]);
        //out.println(mem.size());
        out.flush();
    }
}
