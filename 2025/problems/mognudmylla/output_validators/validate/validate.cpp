#include "validate.h"
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <random>
using namespace std;
using vi = vector<int>;

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

struct Player {
    constexpr static int lines[8][3] = {
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

    unordered_map<vi,int,VectorHasher> memo;
    mt19937 rng;

    Player(unsigned int seed) {
        rng = mt19937(seed);
        memo.max_load_factor(0.2);
    }

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

    vector<vi> reachable(vi v, bool cannibal=true) {
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
                if(!cannibal && v[j] == 1) continue;
                vi cp = v;
                cp[j] = cp[i];
                cp[i] = 0;
                res.push_back(cp);
            }
        }
        return res;
    }

    vi worst_move(vi state) {
        for(vi v : reachable(state)) {
            flip(v);
            if(dp(v) == 1) {
                flip(v);
                return v;
            }
        }
        return random_move(state);
    }
    vi random_move(vi state) {
        vector<vi> opts = reachable(state);
        uniform_int_distribution<mt19937::result_type> ch(0, opts.size() - 1);
        int ind = ch(rng);
        return opts[ind];
    }
    vi better_random_move(vi state) {
        vector<vi> opts = reachable(state, false);
        if(opts.empty()) opts = reachable(state, true);
        for(vi v : opts) {
            if(result(v) == 1) {
                return v;
            }
        }
        uniform_int_distribution<mt19937::result_type> ch(0, opts.size() - 1);
        int ind = ch(rng);
        return opts[ind];
    }
    vi half_random_half_smart(vi state) {
        uniform_int_distribution<mt19937::result_type> ff(0, 1);
        int res = ff(rng);
        if(res == 0) return best_move(state);
        return better_random_move(state);
    }
    vi best_move(vi state) {
        for(vi v : reachable(state)) {
            flip(v);
            if(dp(v) == -1) {
                flip(v);
                return v;
            }
        }
        return better_random_move(state);
    }
    void do_move(vi &state, string agent) {
        if(agent == "worst") state = worst_move(state);
        else if(agent == "random") state = random_move(state);
        else if(agent == "rand2") state = better_random_move(state);
        else if(agent == "half") state = half_random_half_smart(state);
        else if(agent == "best") state = best_move(state);
        else assert(false);
    }
};

void transition(vi &state, vi board) {
    int d_ind_1 = -1, d_ind_2 = -1;
    for(int i = 0; i < 9; ++i) {
        if(state[i] != board[i]) {
            if(d_ind_1 == -1)
                d_ind_1 = i;
            else if(d_ind_2 == -1)
                d_ind_2 = i;
            else {
                wrong_answer("Wrong answer: Illegal move, too many changes.\n");
            }
        }
    }
    if(d_ind_1 == -1) {
        wrong_answer("Wrong answer: Illegal move, too few changes.\n");
    }
    if(d_ind_2 == -1) { // placed new
        int placed = board[d_ind_1];
        if(placed != 2 && placed != 1) {
            wrong_answer("Wrong answer: Illegal move, can only place X or x.\n");
        }
        if(state[8 + placed] == 0) {
            wrong_answer("Wrong answer: Illegal move, out of letters.\n");
        }
        state[8 + placed]--;
        if(abs(state[d_ind_1]) >= placed) {
            wrong_answer("Wrong answer: Illegal move, placed over upper case letter.\n");
        }
        state[d_ind_1] = placed;
    } else { // replaced old
        if(abs(state[d_ind_2]) > abs(state[d_ind_1]))
            swap(d_ind_1, d_ind_2);
        if(state[d_ind_1] != 2) {
            wrong_answer("Wrong answer: Illegal move, moved non upper case letter.\n");
        }
        if(abs(state[d_ind_2]) != 1) {
            wrong_answer("Wrong answer: Illegal move, placed over non lower case letter.\n");
        }
        if(board[d_ind_1] != 0) {
            wrong_answer("Wrong answer: Illegal move, did not leave empty space after moving.\n");
        }
        if(board[d_ind_2] != 2) {
            wrong_answer("Wrong answer: Illegal move, did not overwrite letter correctly.\n");
        }
        state[d_ind_2] = state[d_ind_1];
        state[d_ind_1] = 0;
    }
}

vi read_board() {
    string lines[3];
    for(int i = 0; i < 3; ++i) {
        if(!(author_out >> lines[i])) {
            wrong_answer("Wrong answer: Failed to read line of board.\n");
        }
        if(lines[i].size() != 3) {
            wrong_answer("Wrong answer: Line does not have 3 non-whitespace characters.\n");
        }
    }
    vi result(9, 0);
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(lines[i][j] == '.') {
                result[3 * i + j] = 0;
            } else if(lines[i][j] == 'o') {
                result[3 * i + j] = -1;
            } else if(lines[i][j] == 'O') {
                result[3 * i + j] = -2;
            } else if(lines[i][j] == 'x') {
                result[3 * i + j] = 1;
            } else if(lines[i][j] == 'X') {
                result[3 * i + j] = 2;
            } else {
                wrong_answer("Wrong answer: Invalid character in board.\n");
            }
        }
    }
    return result;
}

void print_board(vi &state) {
    string outp = "Oo.xX";
    for(int i = 0; i < 9; ++i) {
        cout << outp[state[i] + 2];
        if(i % 3 == 2) cout << '\n';
    }
    cout << flush;
}

void debug_print_state(vi &state, string prf) {
    for(int x : state) prf += " " + to_string(x);
    prf += "\n";
    judge_message(prf);
}

bool check_end(Player &p, vi &state, bool &win, bool opp) {
    int verdict = p.result(state);
    if(verdict == 0) return false;
    if((verdict == -1) ^ opp) {
        cout << "Tap!\n" << flush;
        return true;
    }
    if((verdict == 1) ^ opp) {
        cout << "Sigur!\n" << flush;
        win = true;
        return true;
    }
    assert(false);
}

int main(int argc, char **argv) {
    init_io(argc, argv);

    string enemy; unsigned int seed;
    judge_in >> enemy >> seed;
    vi state({
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        4, 2, 4, 2
    });
    Player player(seed);
    bool win = false;
    while(true) {
        vi author_move = read_board();
        transition(state, author_move);
        if(check_end(player, state, win, false)) break;
        player.flip(state);
        player.do_move(state, enemy);
        if(check_end(player, state, win, true)) break;
        player.flip(state);
        print_board(state);
    }
    string trailing;
    if(author_out >> trailing) {
        wrong_answer("Wrong answer: Trailing output.\n");
    }
    accept_with_score(win ? 2 : 0);
}

