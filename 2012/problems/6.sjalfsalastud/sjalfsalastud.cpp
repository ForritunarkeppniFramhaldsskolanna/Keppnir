#include<iostream>

using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG 0
#endif
//-------------------
#ifdef ONLINE_JUDGE
#define DEBUG 0
#endif
#if DEBUG > 1
#define dout cout
#else
#define dout 0 && cout
#endif
#if DEBUG > 0
#include<cstdio>
#define read(file) freopen(file,"r",stdin)
#define write(file) freopen(file,"w",stdout)
#else
#define read(file)
#define write(file)
#endif

int main()
{
    read("in.txt");

    int test_cases;
    int cokes, hundred, fifty, ten, count;
    cin >> test_cases;

    while(test_cases--)
    {
        cin >> cokes >> ten >> fifty >> hundred;
        count = 0;
        while(cokes > 0)
        {
            if(hundred > 0)
            {
                if(hundred + fifty >= cokes || ten < 3)
                {
                    hundred--;
                    ten += 2;
                    count++;
                }
                else
                {
                    hundred--;
                    ten -= 3;
                    fifty++;
                    count += 4;
                }
            }
            else if(fifty > 0)
            {
                if(fifty <= cokes)
                {
                    fifty--;
                    ten -= 3;
                    count += 4;
                }
                else
                {
                    fifty -= 2;
                    ten += 2;
                    count += 2;
                }
            }
            else
            {
                ten -= 8;
                count += 8;
            }
            cokes--;
        }
        cout << count << '\n';
    }
    return 0;
}
