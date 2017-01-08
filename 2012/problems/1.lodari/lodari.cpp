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
    int curr;
    cin >> test_cases;

    while(test_cases--)
    {
        cin >> curr;
        cout << 2 * curr + 1 << '\n';
    }
    return 0;
}
