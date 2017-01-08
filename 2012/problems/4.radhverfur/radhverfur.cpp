#include<iostream>
#include<string>
#include<algorithm>

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

void clear_line()
{
    while(cin.get() != '\n');
}

void remove_spaces(string & s)
{
    unsigned int pos = s.find(' ');
    if(pos == string::npos)
    {
        return;
    }

    int endpos = s.size();
    for(unsigned int i = pos; i != s.size(); i++)
    {
        if(s[i] != ' ')
        {
            endpos = i;
            break;
        }
    }

    s.erase(pos, endpos - pos);
}

int main()
{
    read("in2.txt");

    int test_cases, test_words;
    string curr, orig;

    cin >> test_cases;

    while(test_cases--)
    {
        cin >> test_words;
        clear_line();

        getline(cin, orig);
        sort(orig.begin(), orig.end());
        remove_spaces(orig);

        while(test_words--)
        {
            getline(cin, curr);
            sort(curr.begin(), curr.end());
            remove_spaces(curr);
            if(curr == orig)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
    return 0;
}
