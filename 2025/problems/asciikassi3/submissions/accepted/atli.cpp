#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w, d;
    cin >> h >> w >> d;
    vvi outp(h + d - 1, vi(w + d - 1, 0));
    for(ii off : { ii(0, d - 1), ii(d - 1, 0) }) {
        for(int i = 0; i < w; ++i) {
            outp[off.first][i + off.second] |= 1;
            outp[off.first + h - 1][i + off.second] |= 1;
        }
        for(int i = 0; i < h; ++i) {
            outp[i + off.first][off.second] |= 2;
            outp[i + off.first][off.second + w - 1] |= 2;
        }
    }
    for(int y_off : { 0, h - 1 }) {
        for(int x_off : { 0, w - 1 }) {
            ii st(d - 1 + y_off, x_off);
            ii nd(y_off, d - 1 + x_off);
            outp[st.first][st.second] |= 8;
            outp[nd.first][nd.second] |= 8;
            for(int k = 1; k < d; ++k) {
                outp[st.first - k][st.second + k] |= 4;
            }
        }
    }
    for(int i = 0; i < h + d - 1; ++i) {
        string res = "";
        for(int j = 0; j < w + d - 1; ++j) {
            if(outp[i][j] & 8) res.push_back('+');
            else if(__builtin_popcount(outp[i][j]) > 1) res.push_back('x');
            else if(outp[i][j] == 4) res.push_back('/');
            else if(outp[i][j] == 2) res.push_back('|');
            else if(outp[i][j] == 1) res.push_back('-');
            else res.push_back(' ');
        }
        while(res.size() > 0 && res.back() == ' ')
            res.pop_back();
        cout << res << '\n';
    }
}
