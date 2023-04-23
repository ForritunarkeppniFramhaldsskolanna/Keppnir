#include<bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL));
    int n; cin >> n;
    vector<int> values(n), outp, taken(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        values[i] = i + 1;
    }
    random_shuffle(values.begin(), values.end());
    for(int i : values) {
        if(taken[i]) continue;
        bool taxable = false;
        for(int d = 1; d * d <= i; ++d) {
            if(i % d != 0) continue;
            if(d != i && !taken[d]) {
                taken[d] = 1;
                taxable = true;
            }
            if(d != 1 && !taken[i / d]) {
                taken[i / d] = 1;
                taxable = true;
            }
        }
        if(taxable) {
            taken[i] = 1;
            outp.push_back(i);
        }
    }
    cout << outp.size() << '\n';
    for(int x : outp) cout << x << ' ';
    cout << '\n';
}
