using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

public class Taeta
{
    public static int heiltala(char c)
    {
        if ('0' <= c && c <= '9')
        {
            return c - '0';
        }

        return c - 'a' + 10;
    }

    public static char stafur(int c)
    {
        if (0 <= c && c <= 9)
        {
            return (char)(c + '0');
        }

        return (char)(c - 10 + 'a');
    }

    public static string leggjaSaman(string a, string b)
    {
        int carry = 0;
        string s = "";
        for (int at = 31; at >= 0; at--)
        {
            carry += heiltala(a[at]) + heiltala(b[at]);
            s = stafur(carry % 16) + s;
            carry = carry / 16;
        }

        return s;
    }

    public static string brengla(string s, int at, bool u)
    {
        string magic = "b058592efd277ae75f27bd99d1628fbd";
        if (at >= s.Length) {
            return magic;
        }

        string res = leggjaSaman(brengla(s, at+1, true), brengla(s, at+1, false));
        for (int i = 0; i < 6; i++)
        {
            res = leggjaSaman(res, res);
        }

        int cnt = s[at];
        for (int i = 0; i < cnt; i++)
        {
            res = leggjaSaman(res, magic);
        }

        return res;
    }

    public static string taetaLykilord(string s)
    {
        return brengla(s, 0, true);
    }

    public static void Main()
    {
        Console.WriteLine(taetaLykilord("forrit123"));
    }
}

