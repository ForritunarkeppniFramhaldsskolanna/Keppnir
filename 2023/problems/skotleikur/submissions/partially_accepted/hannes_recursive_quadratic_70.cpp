#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> sols;
set<tuple<int, int, int>> computed;
int K, a, b;

void solve(int total, int kills, int assists)
{
    if (computed.find(make_tuple(total, kills, assists)) != computed.end())
    {
        return;
    }

    if (total == 0)
    {
        sols.insert(make_pair(kills, assists));
        computed.insert(make_tuple(total, kills, assists));
        return;
    }

    if (total < 0)
    {
        computed.insert(make_tuple(total, kills, assists));
        return;
    }

    computed.insert(make_tuple(total, kills, assists));
    solve(total - a, kills + 1, assists);
    solve(total - b, kills, assists + 1);
}

int main()
{
    cin >> K >> a >> b;
    solve(K, 0, 0);

    if (K == 0)
    {
        sols.clear();
        sols.insert(make_pair(0, 0));
    }

    cout << sols.size() << endl;

    for (set<pair<int, int>>::iterator it = sols.begin(); it != sols.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}