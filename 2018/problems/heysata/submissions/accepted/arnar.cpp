#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == c)
        {
            cout << "Unnar fann hana!" << endl;
            return 0;
        }
    }
    cout << "Unnar fann hana ekki!" << endl;
    return 0;
}
