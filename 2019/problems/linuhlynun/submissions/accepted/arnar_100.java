import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_100 {
  public static class Student {
    public long x, c;
  }

  public static class Sorter implements Comparator<Student> {
    public int compare(Student a, Student b)
    {
        if(a.x < b.x) return -1;
        else if(a.x > b.x) return 1;
        else return 0;
    }
  }
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    int n = in.nextInt();
    
    ArrayList<Student> studs = new ArrayList<Student>();
    long left = 0, right = 0, cur = 0;
    for(int i = 0; i < n; i++) {
        int x = in.nextInt(), c = in.nextInt();
        Student s = new Student();
        s.x = x;
        s.c = c;
        right = right+c;
        cur = cur + x*c;
        studs.add(s);
    }
    Collections.sort(studs, new Sorter());

    long best = cur, prev = 0;
    int besti = 0;
    for(int i = 0; i < studs.size(); i++) {
        Student s = studs.get(i);
        cur -= right*(s.x - prev);
        cur += left*(s.x - prev);

        if(cur < best) {
          best = cur;
          besti = (int)s.x;
        }

        right -= s.c;
        left += s.c;

        prev = s.x;
    }
    out.println(besti);
    out.flush(); } }
