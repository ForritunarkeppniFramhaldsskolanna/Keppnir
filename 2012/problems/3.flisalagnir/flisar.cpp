#include<iostream>
#include<vector>

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

int test_cases;
int patt_r, patt_c;
int wall_r, wall_c;
char tmp;

int main()
{
    read("in.txt");

    cin >> test_cases;

    while(test_cases--)
    {
        cin >> patt_r >> patt_c;

        vector< vector<char> > pattern(patt_r);

        for(int i = 0; i != patt_r; i++)
        {
            for(int j = 0; j != patt_c; j++)
            {
                cin >> tmp;
                pattern[i].push_back(tmp);
            }
        }

        cin >> wall_r >> wall_c;

        int curr_r = 0, curr_c;

        while(curr_r < wall_r)
        {
            for(int i = 0; i != min(patt_r, wall_r - curr_r); i++)
            {
                curr_c = 0;
                while(curr_c < wall_c)
                {
                    for(int j = 0; j != min(patt_c, wall_c - curr_c); j++)
                    {
                        cout << pattern[i][j];
                    }
                    curr_c += patt_c;
                }
                cout << '\n';
            }

            curr_r += patt_r;
        }

        cout << '\n';

    }
    return 0;
}
