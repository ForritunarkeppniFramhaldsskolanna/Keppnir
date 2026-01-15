#include "validate.h"
#include <algorithm>
#include <array>
#include <random>
#include <vector>
#include <bitset>
using namespace std;
constexpr double EPS{ 1e-6 };
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<bitset<64>> vb;
struct Maxclique {
	double limit=0.025, pk=0;
	struct Vertex { int i, d=0; };
	typedef vector<Vertex> vv;
	vb e;
	vv V;
	vector<vi> C;
	vi qmax, q, S, old;
	void init(vv& r) {
		for (auto& v : r) v.d = 0;
		for (auto& v : r) for (auto j : r) v.d += e[v.i][j.i];
		sort(all(r), [](auto a, auto b) { return a.d > b.d; });
		int mxD = r[0].d;
		rep(i,0,sz(r)) r[i].d = min(i, mxD) + 1;
	}
	void expand(vv& R, int lev = 1) {
		S[lev] += S[lev - 1] - old[lev];
		old[lev] = S[lev - 1];
		while (sz(R)) {
			if (sz(q) + R.back().d <= sz(qmax)) return;
			q.push_back(R.back().i);
			vv T;
			for(auto v:R) if (e[R.back().i][v.i]) T.push_back({v.i});
			if (sz(T)) {
				if (S[lev]++ / ++pk < limit) init(T);
				int j = 0, mxk = 1, mnk = max(sz(qmax) - sz(q) + 1, 1);
				C[1].clear(), C[2].clear();
				for (auto v : T) {
					int k = 1;
					auto f = [&](int i) { return e[v.i][i]; };
					while (any_of(all(C[k]), f)) k++;
					if (k > mxk) mxk = k, C[mxk + 1].clear();
					if (k < mnk) T[j++].i = v.i;
					C[k].push_back(v.i);
				}
				if (j > 0) T[j - 1].d = 0;
				rep(k,mnk,mxk + 1) for (int i : C[k])
					T[j].i = i, T[j++].d = k;
				expand(T, lev + 1);
			} else if (sz(q) > sz(qmax)) qmax = q;
			q.pop_back(), R.pop_back();
		}
	}
	vi maxClique() { init(V), expand(V); return qmax; }
	Maxclique(vb conn) : e(conn), C(sz(e)+1), S(sz(C)), old(S) {
		rep(i,0,sz(e)) V.push_back({i});
	}
};

double progress(double x, double a, double b) {
   return (x-a)/(b-a);
}

double mylerp(double p, double a, double b) {
    return (1 - p)*a + p*b;
}

struct scoring {
    int guesses;
    double score;
};

double get_score(int guesses, int n) {
    int best = n / 2 + 3;
    if(n == 4) best = 6;
    array<scoring, 9> scoring_for_level = { {
        { 0, 100.0 },
        { best, 100.0 },
        { n / 2 + 4, 90.0 },
        { 3 * n / 4 + 4, 80.0 },
        { n, 60.0 },
        { 2 * n, 40.0 },
        { n * (n - 1) / 2, 20.0 },
        { n * n, 10.0 },
        { 4 * n * n, 0.0 },
    } };

    for(int i = 1; i < 9; ++i) {
        scoring_for_level[i].guesses = max(scoring_for_level[i].guesses, scoring_for_level[i - 1].guesses);
    }

    if(guesses > scoring_for_level.rbegin()->guesses) return 0.0;

    for(size_t i = 1; i < scoring_for_level.size(); i++) {
        if(guesses <= scoring_for_level[i].guesses) {
            double p = progress(guesses, scoring_for_level[i-1].guesses, scoring_for_level[i].guesses);
            return mylerp(p, scoring_for_level[i-1].score, scoring_for_level[i].score);
        }
    }
    assert(false);
}

pair<int,int> read_guess(int n, int &guess_ind) {
    if(guess_ind == 4 * n * n) {
        wrong_answer("Wrong answer: Too many guesses.\n");
    }
    guess_ind++;
    int battery_1, battery_2;
    if (!(author_out >> battery_1)) {
        wrong_answer("Wrong answer: Failed to read first integer of guess.\n");
    }
    if (!(author_out >> battery_2)) {
        wrong_answer("Wrong answer: Failed to read second integer of guess.\n");
    }
    if(battery_1 <= 0 || n < battery_1) {
        wrong_answer("Wrong answer: The first integer of guess is out of range.\n");
    }
    if(battery_2 <= 0 || n < battery_2) {
        wrong_answer("Wrong answer: The second integer of guess is out of range.\n");
    }
    if(battery_1 == battery_2) {
        wrong_answer("Wrong answer: Same battery appears twice in one guess.\n");
    }
    return make_pair(battery_1 - 1, battery_2 - 1);
}


int main(int argc, char **argv) {
    init_io(argc, argv);

    int n, guess_ind = 0;
    bool adaptive;
    judge_in >> n >> adaptive;
    cout << n << endl;

    if(!adaptive) {
        constexpr int default_seed { 164 };
        mt19937 rng(default_seed);
        vector<int> is_good(n, 0), to_shuf(n, 0);
        iota(to_shuf.begin(), to_shuf.end(), 0);
        shuffle(to_shuf.begin(), to_shuf.end(), rng);
        for(int i = 0; i < n / 2; ++i) {
            is_good[to_shuf[i]] = 1;
        }
        while(true) {
            pair<int,int> guess = read_guess(n, guess_ind);
            if(is_good[guess.first] && is_good[guess.second]) {
                cout << "Ljos!" << endl;
                break;
            } else {
                cout << "Myrkur!" << endl;
            }
        }
    } else {
        vb adj(n);
        for(int i = 0; i < n; ++i) {
            adj[i].set();
            adj[i].reset(i);
        }
        while(true) {
            pair<int,int> guess = read_guess(n, guess_ind);
            adj[guess.first].reset(guess.second);
            adj[guess.second].reset(guess.first);
            Maxclique mxc(adj);
            if(mxc.maxClique().size() < n / 2) {
                cout << "Ljos!" << endl;
                break;
            } else {
                cout << "Myrkur!" << endl;
            }
        }
    }
    string trailing;
    author_out >> ws;
    if(author_out >> trailing) {
        wrong_answer("Wrong answer: Trailing output.\n");
    }
    double score = get_score(guess_ind, n) * 100.0;
    score = static_cast<double>(static_cast<int>(score + EPS) / 100);
    accept_with_score(score);
}
