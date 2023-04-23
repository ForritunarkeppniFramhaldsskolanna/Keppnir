import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_40 {
  public static class Kelp {
    public long time_arrived, x, y;
  }

  public static class Robot {
    public long clock, x, y;
  }

  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);
    Robot robot = new Robot();

    long c = in.nextLong(), r = in.nextLong(), q = in.nextLong();
    

    for(int i = 0; i < q; i++) {
        Kelp kelp = new Kelp();
        kelp.time_arrived = in.nextLong();
        kelp.x = in.nextLong();
        kelp.y = in.nextLong();
        
        robot.clock = Math.max(robot.clock, kelp.time_arrived);
        robot.clock += Math.max(Math.abs(kelp.x - robot.x), Math.abs(kelp.y - robot.y));
        robot.x = kelp.x;
        robot.y = kelp.y;

        out.print(robot.clock);
        out.print(" ");
        out.print(robot.x);
        out.print(" ");
        out.print(robot.y);
        out.println();
    }

    out.flush(); } }
