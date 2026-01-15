#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
using vi = vector<int>;

int lines[8][3] = {
    { 0, 1, 2 },
    { 3, 4, 5 },
    { 6, 7, 8 },
    { 0, 3, 6 },
    { 1, 4, 7 },
    { 2, 5, 8 },
    { 0, 4, 8 },
    { 2, 4, 6 }
};

int result(vi &v) {
    for(int i = 0; i < 8; ++i) {
        bool iswin = true;
        bool isloss = true;
        for(int j = 0; j < 3; ++j) {
            iswin &= v[lines[i][j]] > 0;
            isloss &= v[lines[i][j]] < 0;
        }
        if(iswin) return 1;
        if(isloss) return -1;
    }
    if(v[11] > 0) return 0;
    if(v[12] > 0) return 0;
    bool has_small = false, has_big_o = false;
    for(int i = 0; i < 9; ++i) {
        has_small |= abs(v[i]) == 1;
        has_big_o |= v[i] == -2;
    }
    return has_small & has_big_o ? 0 : 1;
}

void flip(vi &v) {
    for(int i = 0; i < 9; ++i)
        v[i] = -v[i];
    for(int i = 9; i < 11; ++i)
        swap(v[i], v[i + 2]);
}

void reflect(vi &v) {
    for(int i = 0; i < 3; ++i)
        swap(v[i], v[i + 6]);
}

void rotate(vi &v) {
    int x = v[2];
    v[2] = v[0];
    v[0] = v[6];
    v[6] = v[8];
    v[8] = x;
    x = v[1];
    v[1] = v[3];
    v[3] = v[7];
    v[7] = v[5];
    v[5] = x;
}

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};


unordered_map<vi,int,VectorHasher> memo;

int dp(vi v) {
    int res = result(v);
    if(res != 0) return res;
    vi tmp = v;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 4; ++j) {
            rotate(tmp);
            v = min(v, tmp);
        }
        reflect(tmp);
    }
    if(memo.count(v)) {
        return memo[v];
    }
    int ans = -1;
    for(int i = 9; i < 11; ++i) {
        if(v[i] == 0) continue;
        for(int j = 0; j < 9; ++j) {
            if(abs(v[j]) >= i - 8) continue;
            vi cp = v;
            cp[j] = i - 8;
            cp[i]--;
            flip(cp);
            int sub = dp(cp);
            ans = max(ans, -sub);
        }
    }
    for(int i = 0; i < 9; ++i) {
        if(v[i] <= 0) continue;
        for(int j = 0; j < 9; ++j) {
            if(v[j] == 0) continue;
            if(abs(v[j]) >= abs(v[i])) continue;
            vi cp = v;
            cp[j] = cp[i];
            cp[i] = 0;
            flip(cp);
            int sub = dp(cp);
            ans = max(ans, -sub);
        }
    }
    memo[v] = ans;
    return ans;
}

vector<vi> moves(vi v) {
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
        if(v[i] <= 0) continue;
        for(int j = 0; j < 9; ++j) {
            if(v[j] == 0) continue;
            if(abs(v[j]) >= abs(v[i])) continue;
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
    memo.max_load_factor(0.2);
    vector<int> state = {
        0, 0, 0,
        0, 0, 0,
        0, 0 ,0,
        4, 2, 4, 2
    };
    while(true) {
        for(vi nstat : moves(state)) {
            flip(nstat);
            if(dp(nstat) != -1) continue;
            flip(nstat);
            state = nstat;
            print_stat(state);
            break;
        }
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
        if(prv_cnt[0] < cur_cnt[0])
            state[12]--;
        if(prv_cnt[1] < cur_cnt[1])
            state[11]--;
    }
}
