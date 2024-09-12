#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int st_left = 26;
    int nonz[26];
    for(int i = 0; i < 26; ++i) 
        nonz[i] = 26;
    int avail[26][26];
    for(int i = 0; i < 26; ++i)
        for(int j = 0; j < 26; ++j)
            avail[i][j] = (1 << 26) - 1;
    int n; cin >> n;
    while(n--) {
        if(st_left == 0) {
            cout << ":(\n";
            continue;
        }
        string s; cin >> s;
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return toupper(c) - 'A'; });
        vector<int> msk(s.size(), 0);        
        for(int i = s.size() - 1; i >= 0; --i) {
            msk[i] = 1 << s[i];
            if(i != s.size() - 1) msk[i] |= msk[i + 1];
        }
        int cdone[26];
        memset(cdone, 0, sizeof(cdone));
        bool done = false;
        for(int i = 0; i + 2 < s.size(); ++i) {
            if(done) break;
            if(cdone[s[i]]) continue;
            cdone[s[i]] = 1;
            if(nonz[s[i]] == 0) continue;
            for(int j = i + 1; j + 1 < s.size(); ++j) {
                if(done) break;
                if(!(avail[s[i]][s[j]] & msk[j + 1])) continue;
                for(int k = j + 1; k < s.size(); ++k) {
                    if(!(avail[s[i]][s[j]] & (1 << s[k]))) continue;
                    avail[s[i]][s[j]] ^= 1 << s[k];
                    if(avail[s[i]][s[j]] == 0) {
                        nonz[s[i]]--;
                        if(nonz[s[i]] == 0) st_left--;
                    }
                    cout << static_cast<char>(s[i] + 'A');
                    cout << static_cast<char>(s[j] + 'A');
                    cout << static_cast<char>(s[k] + 'A');
                    cout << '\n';
                    done = true;
                    break;
                }
            }
        }
        if(!done) cout << ":(\n";
    }
}
