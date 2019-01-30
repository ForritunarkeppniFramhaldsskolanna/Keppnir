#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n;
    vector<long long> peepz;
    for(int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        peepz.push_back(x*x+y*y);
    }
    sort(peepz.begin(), peepz.end());
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        long long d;
        cin >> d;
        d = d*d;
        cout << distance(peepz.begin(), upper_bound(peepz.begin(), peepz.end(), d)) << endl;
    }
    return 0;
}
