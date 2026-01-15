#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
using vi = vector<int>;

vector<vi> moves(vi v, bool cannibal=true) {
    vector<vi> res;
    for(int i = 9; i < 11; ++i) {
        if(v[i] == 0) continue;
        for(int j = 0; j < 9; ++j) {
            if(abs(v[j]) >= i - 8) continue;
            vi cp = v;
            cp[j] = i - 8;
            cp[i]--;
            res.push_back(cp);
        }
    }
    for(int i = 0; i < 9; ++i) {
        if(v[i] != 2) continue;
        for(int j = 0; j < 9; ++j) {
            if(v[j] == 0) continue;
            if(abs(v[j]) >= abs(v[i])) continue;
            if(v[j] == 1 && !cannibal) continue;
            vi cp = v;
            cp[j] = cp[i];
            cp[i] = 0;
            res.push_back(cp);
        }
    }
    return res;
}

vi to_board(string &s) {
    vi res;
    for(char c : s) {
        if(c == '.') res.push_back(0);
        if(c == 'x') res.push_back(1);
        if(c == 'X') res.push_back(2);
        if(c == 'o') res.push_back(-1);
        if(c == 'O') res.push_back(-2);
    }
    return res;
}

void print_stat(vi &s) {
    string outp = "Oo.xX";
    for(int i = 0; i < 9; ++i) {
        cout << outp[s[i] + 2];
        if(i % 3 == 2) cout << '\n';
    }
    cout << flush;
}

int main() {
    srand(1234);
    vector<int> state = {
        0, 0, 0,
        0, 0, 0,
        0, 0 ,0,
        4, 2, 4, 2
    };
    bool first_move = true;
    while(true) {
        vector<vi> poss = moves(state, false);
        if(poss.empty()) poss = moves(state, true);
        int ind = rand() % poss.size();
        vi res = poss[ind];
        print_stat(res);
        state = res;
        string inp = "", line;
        for(int i = 0; i < 3; ++i) {
            cin >> line;
            if(line == "Sigur!") return 0;
            if(line == "Tap!") return 0;
            inp += line;
        }
        vi board = to_board(inp);
        vi prv_cnt(5, 0), cur_cnt(5, 0);
        for(int i = 0; i < 9; ++i) {
            prv_cnt[state[i] + 2]++;
            cur_cnt[board[i] + 2]++;
            state[i] = board[i];
        }
    }
}
