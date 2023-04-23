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

public class arnar_100 {
  public static class Position implements Comparable<Position> {
    public long x, y;

    public Position() {
        x = 0;
        y = 0;
    }

    public Position(long _x, long _y) {
        x = _x;
        y = _y;
    }

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
      return this.compareTo(p) == 0;
    }
    
    @Override
    public int compareTo(Position p) {
        return x == p.x ? Long.compare(y, p.y) : Long.compare(x, p.x);
    }

    @Override
    public int hashCode() {
      return Objects.hash(x, y);
    }

    public String toString() {
        return String.format("%d %d", x, y);
    }

    public long distance(Position p) {
        return Math.max(Math.abs(p.x - x), Math.abs(p.y - y));
    }

    public Position add(Position p) {
        return new Position(x + p.x, y + p.y);
    }

    public Position sub(Position p) {
        return new Position(x - p.x, y - p.y);
    }

    public Position mul(Position p) {
        return new Position(x * p.x, y * p.y);
    }

    public long getRow() {
        return y;
    }
    public long getColumn() {
        return x;
    }
    public long getDiagonal() {
        return x - y;
    }
    public long getAntiDiagonal() {
        return x + y;
    }

    public long getIdentifier(Position dir) {
        if (dir.x == dir.y) {
            return getDiagonal();
        }
        if (dir.x == -dir.y) {
            return getAntiDiagonal();
        }
        if (dir.x == 0) {
            return getColumn();
        }
        return getRow();
    }
  }

  public static class Kelp implements Comparable<Kelp> {
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
    public int compareTo(Kelp k) {
        return position.compareTo(k.position);
    }

    @Override
    public int hashCode() {
        return Objects.hash(time_arrived, position);
    }

    public String toString() {
        return String.format("%d %s", time_arrived, position);
    }
  }

  public static class Robot {
    public long clock;
    public Position position = new Position();

    public void waitUntil(long time) {
        if (clock < time) {
            clock = time;
        }
    }

    public Position getDirection(Position p) {
        Position d = p.sub(position);
        return new Position(Long.signum(d.x), Long.signum(d.y));
    }

    public Position getDestination(Position p) {
        Position d = p.sub(position);
        long dx = Math.abs(d.x), dy = Math.abs(d.y);
        if(dx != 0 && dy != 0) {
           dx = Math.min(dx, dy);
           dy = dx;
        }
        else {
            return p;
        }
        return position.add(getDirection(p).mul(new Position(dx, dy)));
    }
    
    public void move(Position p) {
        clock += position.distance(p);
        position = new Position(p.x, p.y);
    }
  }

  public static HashMap<Long, TreeSet<Kelp>> rows, columns, diagonals, antiDiagonals;

  public static void addKelp(Kelp kelp) {
      rows.putIfAbsent(kelp.position.getRow(), new TreeSet<Kelp>());
      rows.get(kelp.position.getRow()).add(kelp);
      columns.putIfAbsent(kelp.position.getColumn(), new TreeSet<Kelp>());
      columns.get(kelp.position.getColumn()).add(kelp);
      diagonals.putIfAbsent(kelp.position.getDiagonal(), new TreeSet<Kelp>());
      diagonals.get(kelp.position.getDiagonal()).add(kelp);
      antiDiagonals.putIfAbsent(kelp.position.getAntiDiagonal(), new TreeSet<Kelp>());
      antiDiagonals.get(kelp.position.getAntiDiagonal()).add(kelp);
  }
  
  public static void removeKelp(Kelp kelp) {
      rows.getOrDefault(kelp.position.getRow(), new TreeSet<Kelp>()).remove(kelp);
      columns.getOrDefault(kelp.position.getColumn(), new TreeSet<Kelp>()).remove(kelp);
      diagonals.getOrDefault(kelp.position.getDiagonal(), new TreeSet<Kelp>()).remove(kelp);
      antiDiagonals.getOrDefault(kelp.position.getAntiDiagonal(), new TreeSet<Kelp>()).remove(kelp);
  }

  public static HashMap<Long, TreeSet<Kelp>> getHashMap(Position dir) {
      if (dir.x == dir.y) {
          return diagonals;
      }
      if (dir.x == -dir.y) {
          return antiDiagonals;
      }
      if (dir.x == 0) {
          return columns;
      }
      return rows;
  }

  public static TreeSet<Kelp> getSet(Position pos, Position dir) {
      return getHashMap(dir).getOrDefault(pos.getIdentifier(dir), new TreeSet<Kelp>());
  }

  public static Position min(Position a, Position b) {
      return a.compareTo(b) < 0 ? a : b;
  }

  public static Position max(Position a, Position b) {
      return a.compareTo(b) < 0 ? b : a;
  }

  public static void main(String[] args) throws Exception {
    Kattio io = new Kattio(System.in, System.out);
    Robot robot = new Robot();


    long c = io.getLong(), r = io.getLong(), q = io.getLong();
    ArrayList<Kelp> kelps = new ArrayList<Kelp>();
    HashSet<Kelp> processed = new HashSet<Kelp>();

    rows = new HashMap<Long, TreeSet<Kelp>>();
    columns = new HashMap<Long, TreeSet<Kelp>>();
    diagonals = new HashMap<Long, TreeSet<Kelp>>();
    antiDiagonals = new HashMap<Long, TreeSet<Kelp>>();

    for(int i = 0; i < q; i++) {
        Kelp kelp = new Kelp();
        kelp.time_arrived = io.getLong();
        kelp.position.x = io.getLong();
        kelp.position.y = io.getLong();
        kelps.add(kelp);
    }

    int toAddIndex = 0;
    for(int targetIndex = 0; targetIndex < q; targetIndex++) {
        Kelp target = kelps.get(targetIndex);
        robot.waitUntil(target.time_arrived);
        if (processed.contains(target)) {
            continue;
        }
        
        while(!robot.position.equals(target.position)) {
            Position nextDirection = robot.getDirection(target.position);
            Position nextDestination = robot.getDestination(target.position);

            long destinationReachedTime = robot.clock + robot.position.distance(nextDestination);
            while(toAddIndex < q && kelps.get(toAddIndex).time_arrived <= destinationReachedTime) {
                addKelp(kelps.get(toAddIndex));
                toAddIndex++;
            }
            
            Position fromPos = min(robot.position, nextDestination);
            Position toPos = max(robot.position, nextDestination);
            Kelp fromKelp = new Kelp();
            fromKelp.position = fromPos;
            Kelp toKelp = new Kelp();
            toKelp.position = toPos;
            
            TreeSet<Kelp> fullSet = getSet(robot.position, nextDirection);
            TreeSet<Kelp> subSet = (TreeSet<Kelp>)(fullSet.subSet(fromKelp, true, toKelp, true));
            Iterator it = subSet.iterator();
            
            ArrayList<Kelp> toProcess = new ArrayList<Kelp>();

            while(it.hasNext()) {
                Kelp k = (Kelp)it.next();
                long reachTime = robot.clock + robot.position.distance(k.position);
                if (reachTime >= k.time_arrived) {
                    toProcess.add(k);
                }
            }

            if (nextDirection.equals(new Position(0, -1)) || nextDirection.x == -1) {
                Collections.reverse(toProcess);
            }

            for (Kelp k : toProcess) {
                long reachTime = robot.clock + robot.position.distance(k.position);
                removeKelp(k);
                processed.add(k);
                io.printf("%d %d %d\n", reachTime, k.position.x, k.position.y);
            }

            robot.move(nextDestination);
        }
    }


    io.flush(); } }
