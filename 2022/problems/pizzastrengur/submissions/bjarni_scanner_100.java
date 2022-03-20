import java.util.*;

public class bjarni_scanner_100
{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int res = -1;
        ArrayList<Character> cs = new ArrayList<>(Arrays.asList('P', 'I', 'Z', 'A'));
        StringBuilder ans = new StringBuilder("");
        while (res != 2 && ans.length() != n) {
            Collections.shuffle(cs);
            for (int i = 0; i < cs.size(); i++) {
                ans.append(cs.get(i));
                if (i == cs.size() - 1) {
                    break;
                }
                System.out.println(ans);
                System.out.flush();
                res = in.nextInt();
                if (res != 0) {
                    break;
                }
                else {
                    ans.deleteCharAt(ans.length() - 1);
                }
            }
        }
        if (res != 2) {
            System.out.println(ans);
            System.out.flush();

        }
        in.close();
    }
}
