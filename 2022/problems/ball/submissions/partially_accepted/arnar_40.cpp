#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > pairs_original;
    for (int i = 0; i < n/2+1; i++)
    {
        int a, b;
        cin >> a >> b;
        pairs_original.push_back(make_pair(a, b));
    }
    for (int i = 0; i < pairs_original.size(); i++)
    {
        vector<pair<int, int> > pairs(pairs_original);
        pairs.erase(pairs.begin()+i);
        bool conflict = false;
        for (int j = 0; j < pairs.size(); j++)
        {
            for (int k = j+1; k < pairs.size(); k++)
            {
                if (pairs[j].first == pairs[k].first  ||
                    pairs[j].second == pairs[k].first ||
                    pairs[j].first == pairs[k].second ||
                    pairs[j].second == pairs[k].second)
                {
                    conflict = true;
                }
            }
        }
        if (!conflict)
        {
            int a = pairs_original[i].first, b = pairs_original[i].second;
            cout << min(a, b) << " " << max(a, b) << endl;
        }
    }
}
