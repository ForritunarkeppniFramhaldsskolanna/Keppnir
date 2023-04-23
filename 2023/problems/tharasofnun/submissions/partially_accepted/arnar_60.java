import java.util.*;
import java.math.*;
import java.io.*;

public class arnar_60 {
  public static class Position {
    public long x, y;

    @Override
    public boolean equals(Object o) {

      // If the object is compared with itself then return true  
      if (o == this) {
        return true;
      }

      /* Check if o is an instance of Complex or not
        "null instanceof [type]" also returns false */
      if (!(o instanceof Position)) {
        return false;
      }
     
      // typecast o to Complex so that we can compare data members 
      Position p = (Position) o;
     
      // Compare the data members and return accordingly 
      return Long.compare(x, p.x) == 0
              && Long.compare(y, p.y) == 0;
    }

    @Override
    public int hashCode() {
      return Objects.hash(x, y);
    }
  }
  public static class Kelp {
    public long time_arrived;
    public Position position = new Position();

    @Override
    public boolean equals(Object o) {
      if (o == this) {
        return true;
      }
      if (!(o instanceof Kelp)) {
        return false;
      }
      Kelp k = (Kelp) o;
      return Long.compare(time_arrived, k.time_arrived) == 0
              && position.equals(k.position);
    }


    @Override
    public int hashCode() {
        return Objects.hash(time_arrived, position);
    }
  }

  public static class Robot {
    public long clock;
    public Position position = new Position();
  }

  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);
    Robot robot = new Robot();

    long c = in.nextLong(), r = in.nextLong(), q = in.nextLong();
    HashMap<Position, Queue<Kelp>> kelpMap = new HashMap<Position, Queue<Kelp>>();
    Queue<Kelp> kelps = new ArrayDeque<Kelp>();
    HashSet<Kelp> processed = new HashSet<Kelp>();

    for(int i = 0; i < q; i++) {
        Kelp kelp = new Kelp();
        kelp.time_arrived = in.nextLong();
        kelp.position.x = in.nextLong();
        kelp.position.y = in.nextLong();
        kelps.add(kelp);
        kelpMap.putIfAbsent(kelp.position, new ArrayDeque<Kelp>());
        kelpMap.get(kelp.position).add(kelp);
    }

    while (!kelps.isEmpty()) {
        Kelp kelp = kelps.poll();

        if (processed.contains(kelp)) {
            continue;
        }


        while(!robot.position.equals(kelp.position) || kelp.time_arrived > robot.clock) {
            if (kelp.time_arrived <= robot.clock) {
                long dx = Long.signum(kelp.position.x - robot.position.x);
                long dy = Long.signum(kelp.position.y - robot.position.y);
                robot.position.x += dx;
                robot.position.y += dy;
            }
            robot.clock += 1;
            Queue<Kelp> kelpsHere = kelpMap.getOrDefault(robot.position, new ArrayDeque<Kelp>());
            while (!kelpsHere.isEmpty()) {
                Kelp pickup = kelpsHere.peek();
                if(pickup.time_arrived <= robot.clock) {
                    out.printf("%d %d %d\n", robot.clock, robot.position.x, robot.position.y);
                    processed.add(pickup);
                    kelpsHere.poll();
                }
                else {
                    break;
                }
            }
            out.flush();
        }


    }

    out.flush(); } }
