using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2 {
    class Program {
        static void Main(string[] args) {
            int n;
            n = Convert.ToInt32(Console.ReadLine());
            int[] a = new int[n];
            for(int i = 0; i < n; i++){
                a[i] = Convert.ToInt32(Console.ReadLine());
            }
            for(int i = n - 1; i >= 0; i--){
                Console.WriteLine(a[i]);
            }
        }
    }
}
