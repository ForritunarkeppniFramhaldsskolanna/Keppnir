
import java.util.*;
import java.math.*;
import java.io.*;

class Kattio extends PrintWriter {
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
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}

class Item {
    public String name;
    public long count;
    public Item(String s, long c) {
        name = s;
        count = c;
    }
}

public class arnar_100 {
    public static void main(String[] args) throws Exception {
        Kattio io = new Kattio(System.in, System.out);

        HashMap<String, ArrayList<Item>> recipes = new HashMap<String, ArrayList<Item>>();
        HashMap<String, Long> dishes = new HashMap<String, Long>();
        HashMap<String, Long> counts = new HashMap<String, Long>();
        
        int u = io.getInt(), k = io.getInt();
        for (int i = 0; i < u; i++) {
            String name = io.getWord();
            int h = io.getInt();
            ArrayList<Item> recipe = new ArrayList<Item>();
            for (int j = 0; j < h; j++) {
                String s = io.getWord();
                long c = io.getInt();
                recipe.add(new Item(s, c));
            }
            recipes.put(name, recipe);
        }
        
        for (int i = 0; i < k; i++) {
            int n = io.getInt();
            for (int j = 0; j < n; j++) {
                String name = io.getWord();
                long c = io.getInt();
                dishes.put(name, dishes.getOrDefault(name, 0L) + c);
            }
        }

        dishes.forEach((key, value) -> {
            for(Item it : recipes.get(key)) {
                counts.put(it.name, counts.getOrDefault(it.name, 0L) + it.count*value);
            }
        });

        ArrayList<String> keys = new ArrayList<String>(counts.keySet());
        Collections.sort(keys);
        for (String key : keys) {
            long value = counts.get(key);
            if (value > 0) {
                io.printf("%s %d\n", key, value);
            }
        }

        io.flush();
    }
}
