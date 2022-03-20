#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void quit() {
    cout << "Neibb\n";
    exit(0);
}

int main() {
    int n, k; cin >> n >> k;
    vi fr, gt, a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    for(int i = 0; i < n; ++i) {
        if(a[i] == 4) fr.push_back(b[i]);
        if(a[i] > 4) gt.push_back(b[i]);
    }
    sort(fr.begin(), fr.end());
    sort(gt.begin(), gt.end());
    for(int i = k; i > 0; --i) {
        if(gt.empty()) quit();
        if(gt.back() < i) quit();
        gt.pop_back();
        if(!fr.empty() && fr.back() >= i) fr.pop_back();
        else if(!gt.empty() && gt.back() >= i) gt.pop_back();
        else quit();
    }
    cout << "Jebb\n";
}
