import java.util.*;
import java.math.*;
import java.io.*;
public class arnar_unqualified_0 {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, false);

    String ip = in.next();
    
    if(ip.contains(":")) {
        // IPv6
        if(ip.contains("::")) {
            String[] leftright = ip.split("::"), lparts, rparts;
            String left, right;
            if (ip.startsWith("::")) {
                left = "";
                lparts=new String[0];
            }
            else {
                left = leftright[0];
                lparts = left.split(":");
            }
            if (ip.endsWith("::")) {
                right = "";
                rparts=new String[0];
            }
            else {
                right = leftright[1];
                rparts = right.split(":");
            }
            String created = "";
            for(int i = 0; i < 8; i++) {
                if (i > 0) created += ":";
                if (i < lparts.length) {
                    created += lparts[i];
                }
                else if (7-i < rparts.length) {
                    created += rparts[rparts.length - (7-i) - 1];
                }
                else {
                    created += "0";
                }
            }
            ip = created;
        }
        String[] parts = ip.split(":");
        for(int i = 0; i < 8; i++)
        {
            while(parts[i].length() < 4) parts[i] = "0"+parts[i];
        }
        String joined = String.join("", parts);
        String dotjoin = String.join(".", new StringBuilder(joined).reverse().toString().split("(?!^)"));
        out.printf("%s.IP6.ARPA\n", dotjoin); 
    }
    else {
        // IPv4
        String[] parts = ip.split("\\.");
        out.printf("%s.%s.%s.%s.IN-ADDR.ARPA\n", parts[3], parts[2], parts[1], parts[0]);
    }

    out.flush(); } }
