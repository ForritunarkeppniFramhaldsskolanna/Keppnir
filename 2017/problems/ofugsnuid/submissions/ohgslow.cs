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
            List<int> arr = new List<int>();
            for(int i = 0; i < n; i++){
                int a = Convert.ToInt32(Console.ReadLine());
                arr.Insert(0,a);
            }
            for(int i = 0; i < n; i++){
                Console.WriteLine(arr[i]);
            }
        }
    }
}
