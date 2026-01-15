#include<iostream>
#include<vector>
using namespace std;
using thrw = pair<string,int>;
using vt = vector<thrw>;
using vvt = vector<vt>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    vt throws; vvt res;
    for(int i = 1; i <= 20; ++i)
        throws.emplace_back("Single " + to_string(i), i);
    for(int i = 1; i <= 20; ++i)
        throws.emplace_back("Double " + to_string(i), 2 * i);
    for(int i = 1; i <= 20; ++i)
        throws.emplace_back("Triple " + to_string(i), 3 * i);
    throws.emplace_back("Outer bullseye", 25);
    throws.emplace_back("Bullseye", 50);

    for(auto x : throws)
        if(x.second == n)
            res.push_back({ x });
    for(auto x : throws)
        for(auto y : throws)
            if(x.second + y.second == n)
                res.push_back({ x, y });
    for(auto x : throws)
        for(auto y : throws)
            for(auto z : throws)
                if(x.second + y.second + z.second == n)
                    res.push_back({ x, y, z });
    auto x = res.back();
    cout << res.size() << '\n';
    for(auto throws : res) {
        cout << throws.size() << '\n';
        for(auto entry : throws) {
            cout << entry.first << '\n';
        }
    }
}
