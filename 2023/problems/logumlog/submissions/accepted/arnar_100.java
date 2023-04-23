import java.util.*;
import java.math.*;
import java.io.*;

class Note {
    private static String NOTECHARS = "CDEFGAB";
    private static char SHARP = '#';
    private static char FLAT = 'b';
    private static int[] MAJOR = {2, 2, 1, 2, 2, 2, 1};
    private static int SEMITONES = 12;
    
    public String base, accidentals;
    public int octave, n;

    public Note(String note) {
        int octave_index = note.length()-1;
        base = note.substring(0, 1);
        accidentals = note.substring(1, octave_index);
        octave = Integer.parseInt(note.substring(octave_index));
        
        n = octave * SEMITONES;
        for (int i = 0; i < MAJOR.length; i++) {
            if (NOTECHARS.charAt(i) == base.charAt(0)) {
                break;
            }
            n += MAJOR[i];
        }
        if (accidentals.equals("#")) n += 1;
        else if (accidentals.equals("b")) n -= 1;
    }
}

public class arnar_100 {
    private static String REST = "-";
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, false);

        int n = in.nextInt();
        ArrayList<String> song1 = new ArrayList<String>();
        ArrayList<String> song2 = new ArrayList<String>();

        for (int i = 0; i < n; i++) {
            song1.add(in.next());
        }
        for (int i = 0; i < n; i++) {
            song2.add(in.next());
        }
        
        for (int i = 0; i < n; i++) {
            String a = song1.get(i);
            String b = song2.get(i);
            if (!a.equals(b) && (a.equals(REST) || b.equals(REST))) {
                out.println("Neibb");
                out.flush();
                return;
            }
        }

        ArrayList<Note> notes1 = new ArrayList<Note>();
        ArrayList<Note> notes2 = new ArrayList<Note>();
        for (String s : song1) {
            if (!s.equals(REST)) {
                notes1.add(new Note(s));
            }
        }
        for (String s : song2) {
            if (!s.equals(REST)) {
                notes2.add(new Note(s));
            }
        }

        for (int i = 1; i < notes1.size(); i++) {
            int a = notes1.get(i-1).n, b = notes1.get(i).n;
            int c = notes2.get(i-1).n, d = notes2.get(i).n;
            if (b-a != d-c) {
                out.println("Neibb");
                out.flush();
                return;
            }
        }
        out.println("Jebb");
        out.flush(); 
    }
}
