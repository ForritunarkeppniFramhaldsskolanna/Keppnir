#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    vii rle; int cnt = 0;
    for(int i = 0; i < s.size(); ++i) {
        cnt++;
        if(i != s.size() - 1 && s[i] == s[i + 1]) continue;
        int ch = s[i] == '0' ? 0 : 1;
        rle.push_back(ii(ch, cnt));
        cnt = 0;
    }
    int bst = 0, n = rle.size();
    for(int i = 0; i < n; ++i) {
        bst = max(bst, rle[i].second);
    }
    for(int i = 0; i < n - 1; ++i) {
        if(rle[i].first == 0) bst = max(bst, rle[i].second + rle[i + 1].second);
    }
    for(int i = 0; i < n - 1; ++i) {
        if(rle[i].first == 1) bst = max(bst, rle[i].second + rle[i + 1].second);
    }
    for(int i = 0; i < n - 3; ++i) {
        if(rle[i].first == 0) bst = max(bst, rle[i].second + rle[i + 1].second + rle[i + 2].second + rle[i + 3].second);
    }
    vi lmx(n, 0), rmx(n, 0);
    for(int i = 0; i < n; ++i) {
        if(i > 0) lmx[i] = max(lmx[i], lmx[i - 1]);
        if(i + 1 < n && i > 0 && rle[i - 1].first == 1) {
            lmx[i + 1] = max(lmx[i + 1], rle[i - 1].second + rle[i].second);
        }
        if(i + 1 < n && rle[i].first == 0) {
            lmx[i + 1] = max(lmx[i + 1], rle[i].second);
        }
    }
    for(int i = n - 1; i >= 0; --i) {
        if(i != n - 1) rmx[i] = max(rmx[i], rmx[i + 1]);
        if(i > 0 && i < n - 1 && rle[i + 1].first == 0) {
            rmx[i - 1] = max(rmx[i - 1], rle[i + 1].second + rle[i].second);
        }
        if(i > 0 && rle[i].first == 1) {
            rmx[i - 1] = max(rmx[i - 1], rle[i].second);
        }
    }
    for(int i = 0; i < n; ++i) {
        if(rle[i].first == 0) bst = max(bst, rle[i].second + rmx[i]);
        else bst = max(bst, rle[i].second + lmx[i]);
    }
    lmx = vi(n, 0); rmx = vi(n, 0);
    for(int i = 0; i < n; ++i) {
        if(i > 0) lmx[i] = max(lmx[i], lmx[i - 1]);
        if(rle[i].first == 0) lmx[i] = max(lmx[i], rle[i].second);
    }
    for(int i = n - 1; i >= 0; --i) {
        if(i < n - 1) rmx[i] = max(rmx[i], rmx[i + 1]);
        if(rle[i].first == 1) rmx[i] = max(rmx[i], rle[i].second);
    }
    for(int i = 1; i < n - 1; ++i) {
        if(rle[i].first == 0) bst = max(bst, lmx[i - 1] + rle[i].second + rle[i + 1].second);
        else bst = max(bst, rmx[i + 1] + rle[i].second + rle[i - 1].second);
    }
    cout << bst << '\n';
}
