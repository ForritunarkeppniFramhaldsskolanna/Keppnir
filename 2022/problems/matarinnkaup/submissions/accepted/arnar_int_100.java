import java.util.*;
import java.math.*;
import java.io.*;

class Item {
    public String name;
    public int count;
    public Item(String s, int c) {
        name = s;
        count = c;
    }
}

public class arnar_int_100 {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);

        HashMap<String, ArrayList<Item>> recipes = new HashMap<String, ArrayList<Item>>();
        HashMap<String, Integer> dishes = new HashMap<String, Integer>();
        HashMap<String, Integer> counts = new HashMap<String, Integer>();
        
        int u = in.nextInt(), k = in.nextInt();
        for (int i = 0; i < u; i++) {
            String name = in.next();
            int h = in.nextInt();
            ArrayList<Item> recipe = new ArrayList<Item>();
            for (int j = 0; j < h; j++) {
                String s = in.next();
                int c = in.nextInt();
                recipe.add(new Item(s, c));
            }
            recipes.put(name, recipe);
        }
        
        for (int i = 0; i < k; i++) {
            int n = in.nextInt();
            for (int j = 0; j < n; j++) {
                String name = in.next();
                int c = in.nextInt();
                dishes.put(name, dishes.getOrDefault(name, 0) + c);
            }
        }

        dishes.forEach((key, value) -> {
            for(Item it : recipes.get(key)) {
                counts.put(it.name, counts.getOrDefault(it.name, 0) + it.count*value);
            }
        });

        ArrayList<String> keys = new ArrayList<String>(counts.keySet());
        Collections.sort(keys);
        for (String key : keys) {
            int value = counts.get(key);
            if (value > 0) {
                System.out.printf("%s %d\n", key, value);
            }
        }

        System.out.flush();
    }
}
