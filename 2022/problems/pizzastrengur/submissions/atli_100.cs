using System;
using System.Linq;

public class Program {
    public static void Main() {
        Random rnd = new Random();
        string line = Console.ReadLine();
        int n = Int32.Parse(line), m = 0;
        char[] guesses = { 'P', 'I', 'Z', 'A' };
        char[] known = new char[n];
        while(m < n) {
            char[] curguesses = guesses.OrderBy(c => rnd.Next()).ToArray();
            bool found = false;
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < m; ++j) {
                    Console.Write(known[j]);
                }
                Console.WriteLine(curguesses[i]);
                Console.Out.Flush();
                line = Console.ReadLine();
                int corr = Int32.Parse(line);
                if(corr > 0) {
                    if(corr == 2) {
                        Environment.Exit(0);
                    }
                    known[m] = curguesses[i];
                    m++;
                    found = true;
                    break;
                }
            }
            if(!found) {
                known[m] = curguesses[3];
                m++;
            }
        }
        for(int i = 0; i < n; ++i) {
            Console.Write(known[i]);
        }
        Console.Out.Flush();
    }
}

