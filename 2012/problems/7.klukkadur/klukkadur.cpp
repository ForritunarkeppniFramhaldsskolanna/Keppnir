#include<iostream>
#include<vector>
#include<climits>

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

const int SIZE = 9;

bool is_final(const vector<int> & v)
{
    for(int i = 0; i != SIZE; i++)
    {
        if(v[i] != 0)
        {
            return false;
        }
    }
    return true;
}

void apply_pattern(const vector<bool> & pattern, int times, vector<int> & result)
{
    for(int i = 0; i != SIZE; i++)
    {
        if(pattern[i])
        {
            result[i] = (result[i] + times*3) % 12;
        }
    }
}

void apply(const vector<int> & counter, const vector< vector<bool> > & patterns, vector<int> & result)
{
    for(unsigned int i = 0; i != counter.size(); i++)
    {
        if(counter[i] != 0)
        {
            apply_pattern(patterns[i], counter[i], result);
        }
    }
}

bool increment(vector<int> & v)
{
    unsigned int ind = 0;
    while(ind < v.size())
    {
        v[ind] = (v[ind] + 1) % 4;
        if(v[ind] != 0)
        {
            return true;
        }
        ind++;
    }
    return false;
}

int sum(vector<int> & v)
{
    int s = 0;
    for(unsigned int i = 0; i != v.size(); i++)
    {
        s += v[i];
    }
    return s;
}

int main()
{
    read("in.txt");

    int test_cases, tests;
    int no_patterns;

    cin >> test_cases;

    while(test_cases--)
    {
        cin >> no_patterns;
        vector< vector<bool> > patterns(no_patterns);

        bool patt_tmp;
        for(int i = 0; i != no_patterns; i++)
        {
            for(int j = 0; j != SIZE; j++)
            {
                cin >> patt_tmp;
                patterns[i].push_back(patt_tmp);
            }
        }

        cin >> tests;
        while(tests--)
        {
            vector<int> setup(SIZE);
            for(int i = 0; i != SIZE; i++)
            {
                cin >> setup[i];
                setup[i] = setup[i] % 12;
            }

            vector<int> counter(no_patterns);
            vector<int> curr_setup(SIZE);
            int min_movements = INT_MAX;
            do
            {
                curr_setup.assign(setup.begin(), setup.end());
                apply(counter, patterns, curr_setup);
                if(is_final(curr_setup))
                {
                    int c_sum = sum(counter);
                    if(c_sum < min_movements)
                    {
                        min_movements = c_sum;
                    }
                }
            }
            while(increment(counter));

            if(min_movements == INT_MAX)
            {
                cout << "NOT POSSIBLE\n";
            }
            else
            {
                cout << min_movements << '\n';
            }
        }
    }
    return 0;
}
