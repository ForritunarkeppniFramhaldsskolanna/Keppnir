#include<iostream>
using namespace std;

string months[12] = { 
    "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
    "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

int main() {
    string s, ans = "2025-03-08";
    getline(cin, s);
    ans[2] = s[s.size() - 2];
    ans[3] = s[s.size() - 1];
    ans[8] = s[0];
    ans[9] = s[1];
    string t = s.substr(s.size() - 6, 3);
    for(int i = 0; i < 12; ++i) {
        if(months[i] != t) continue;
        if(i >= 9) ans[5] = '1';
        ans[6] = ((i + 1) % 10) + '0';
        break;
    }
    cout << ans << '\n';
}
