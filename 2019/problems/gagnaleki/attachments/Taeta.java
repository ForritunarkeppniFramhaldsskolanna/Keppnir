import java.util.*;
import java.math.*;
import java.io.*;

public class Taeta {

    public static int heiltala(char c) {
        if ('0' <= c && c <= '9') {
            return c - '0';
        }

        return c - 'a' + 10;
    }

    public static char stafur(int c) {
        if (0 <= c && c <= 9) {
            return (char)(c + '0');
        }

        return (char)(c - 10 + 'a');
    }

    public static String leggjaSaman(String a, String b) {
        int carry = 0;
        String s = "";
        for (int at = 31; at >= 0; at--) {
            carry += heiltala(a.charAt(at)) + heiltala(b.charAt(at));
            s = stafur(carry % 16) + s;
            carry = carry / 16;
        }

        return s;
    }

    public static String brengla(String s, int at, boolean u) {
        String magic = "b058592efd277ae75f27bd99d1628fbd";
        if (at >= s.length()) {
            return magic;
        }

        String res = leggjaSaman(brengla(s, at+1, true), brengla(s, at+1, false));
        for (int i = 0; i < 6; i++) {
            res = leggjaSaman(res, res);
        }

        int cnt = s.charAt(at);
        for (int i = 0; i < cnt; i++) {
            res = leggjaSaman(res, magic);
        }

        return res;
    }

    public static String taetaLykilord(String s) {
        return brengla(s, 0, true);
    }

    public static void main(String[] args) throws Exception {
        System.out.println(taetaLykilord("forrit123"));
    }
}

