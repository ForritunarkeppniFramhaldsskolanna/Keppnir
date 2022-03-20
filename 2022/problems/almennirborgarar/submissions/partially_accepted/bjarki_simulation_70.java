import java.util.*;
import java.io.*;

public class bjarki_simulation_70 {
    static class Event implements Comparable<Event> {
        public long time;
        public int grill;
        public Event(long time, int grill) {
            this.time = time;
            this.grill = grill;
        }

        public int compareTo(Event other) {
            if (time != other.time) {
                return time < other.time ? -1 : 1;
            }
            return grill - other.grill;
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, true);
        int n = in.nextInt(),
            m = in.nextInt() + n + 1;
        int[] grill_time = new int[n];
        PriorityQueue<Event> events = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            grill_time[i] = in.nextInt();
            events.add(new Event(0, i));
        }
        while (m > 0) {
            Event event = events.poll();
            m--;
            if (m == 0) {
                out.printf("%d\n", event.time);
                return;
            }
            events.add(new Event(event.time + grill_time[event.grill], event.grill));
        }
    }
}
