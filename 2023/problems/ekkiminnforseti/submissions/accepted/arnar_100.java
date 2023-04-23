import java.util.*;
import java.io.*;

class VotePair implements Comparable<VotePair> {
    int votes, id;
    public VotePair(int votes, int id) {
        this.votes = votes;
        this.id = id;
    }
    @Override
    public int compareTo(VotePair other) {
        int res = -Integer.compare(votes, other.votes);
        if(res == 0) {
            return Integer.compare(id, other.id);
        }
        return res;
    }

    @Override
    public String toString() {
        return String.format("(%d, %d)", votes, id);
    }
}

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
    static Kattio io;

    static ArrayList<Integer> getResults(ArrayList<ArrayList<ArrayList<Integer>>> voteMap)
    {
        ArrayList<VotePair> result = new ArrayList<VotePair>();
        for(int i = 0; i < voteMap.size(); i++)
        {
            result.add(new VotePair(voteMap.get(i).size(), i));
        }
        Collections.sort(result);
        ArrayList<Integer> order = new ArrayList<Integer>();
        for(int i = 0; i < voteMap.size(); i++)
        {
            order.add(result.get(i).id);
        }
        return order;
    }

    static boolean hasWinner(ArrayList<Integer> order, ArrayList<ArrayList<ArrayList<Integer>>> voteMap, int requiredToWin)
    {
        if (order.isEmpty())
        {
            return false;
        }

        int winnerId = order.get(0);
        return voteMap.get(winnerId).size() >= requiredToWin;
    }

    static int getNextLoser(ArrayList<Integer> order, ArrayList<ArrayList<ArrayList<Integer>>> voteMap)
    {
        for (int i = voteMap.size() - 1; i >= 0; i--)
        {
            if (!voteMap.get(order.get(i)).isEmpty())
            {
                return order.get(i);
            }
        }
        assert(false);
        return -1;
    }

    static void transferVotesFromLoser(ArrayList<Integer> order, ArrayList<ArrayList<ArrayList<Integer>>> voteMap)
    {
        int loserId = getNextLoser(order, voteMap);
        ArrayList<ArrayList<Integer>> loserVotes = voteMap.get(loserId);
        for(ArrayList<Integer> vote : loserVotes)
        {
            vote.remove(vote.size() - 1);
            int successor = vote.get(vote.size() - 1);
            while (voteMap.get(successor).isEmpty())
            {
                vote.remove(vote.size() - 1);
                successor = vote.get(vote.size() - 1);
            }
            voteMap.get(successor).add(vote);
        }
        loserVotes.clear();
    }

    public static void main(String[] args) throws Exception {
        io = new Kattio(System.in, System.out);

        int n = io.getInt();
        int m = io.getInt();
        ArrayList<String> candidates = new ArrayList<String>();
        for (int i = 0; i < m; i++) {
            candidates.add(io.getWord());
        }

        int requiredToWin = n/2 + 1;
        
        ArrayList<ArrayList<Integer>> votes = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> cur = new ArrayList<Integer>();
            for (int j = 0; j < m; j++)
            {
                cur.add(io.getInt() - 1);
            }
            Collections.reverse(cur);
            votes.add(cur);
        }

        ArrayList<ArrayList<ArrayList<Integer>>> voteMap = new ArrayList<ArrayList<ArrayList<Integer>>>();
        for(int i = 0; i < m; i++) {
            voteMap.add(new ArrayList<ArrayList<Integer>>());
        }

        ArrayList<Integer> order = new ArrayList<Integer>();

        
        while(!hasWinner(order, voteMap, requiredToWin)) {
            if (order.isEmpty()) {
                for(ArrayList<Integer> vote : votes) {
                    voteMap.get(vote.get(vote.size() - 1)).add(vote);
                }
            }
            else {
                transferVotesFromLoser(order, voteMap);
            }
            order = getResults(voteMap);
        }
        io.println(candidates.get(order.get(0)));
        io.close();

        return;
    }
}
