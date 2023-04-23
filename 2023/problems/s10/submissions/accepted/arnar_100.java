import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int n, k;
    String car;
    n = in.nextInt();
    k = in.nextInt();
    HashMap<String, Integer> carToCompany = new HashMap<String, Integer>();
    ArrayList<Integer> companyLimit = new ArrayList<Integer>();
    ArrayList<HashSet<String>> companyParked = new ArrayList<HashSet<String>>();
    HashSet<String> parked = new HashSet<String>();
    HashSet<String> unpins = new HashSet<String>();
    TreeSet<String> illegal = new TreeSet<String>();

    for(int i = 0; i < k; ++i) {
        companyParked.add(new HashSet<String>());
        int limit = in.nextInt();
        companyLimit.add(limit);
        int x = in.nextInt();
        for(int j = 0; j < x; ++j) {
            car = in.next();
            carToCompany.put(car, i);
        }
    }

    
    int m = in.nextInt();
    for(int i = 0; i < m; ++i) {
        car = in.next();
        if(unpins.contains(car)) {
            unpins.remove(car);
            continue;
        }
        if(parked.contains(car)) {
            parked.remove(car);
            if(carToCompany.containsKey(car)) {
                companyParked.get(carToCompany.get(car)).remove(car);
            }
            continue;
        }
        if(parked.size() == n) {
            illegal.add(car);
            unpins.add(car);
            continue;
        }
        parked.add(car);
        if(!carToCompany.containsKey(car)) {
            illegal.add(car);
            continue;
        }
        int ind = carToCompany.get(car);
        companyParked.get(ind).add(car);
        if(companyParked.get(ind).size() > companyLimit.get(ind)) {
            illegal.add(car);
        }
    }
    out.println(illegal.size());
    for (String s : illegal) {
        out.println(s);
    }

    out.flush(); 
  }
}
