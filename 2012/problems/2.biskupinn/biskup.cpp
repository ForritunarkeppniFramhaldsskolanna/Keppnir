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

int total_test_cases, test_cases, board_size;
int bishop_r, bishop_c;
int target_r, target_c;

int abs(int a)
{
    return a < 0 ? -a : a;
}

int main()
{
    read("in.txt");

    cin >> total_test_cases;

    while(total_test_cases--)
    {
        cin >> test_cases;
        cin >> board_size;
        while(test_cases--)
        {
            cin >> bishop_r >> bishop_c >> target_r >> target_c;
            if( (bishop_r + bishop_c) % 2 != (target_r + target_c) % 2 )
            {
                cout << "impossible\n";
            }
            else if(bishop_r == target_r && bishop_c == target_c)
            {
                cout << 0 << '\n';
            }
            else if( abs(bishop_r - target_r) == abs(bishop_c - target_c) )
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 2 << '\n';
            }
        }
    }
    return 0;
}
