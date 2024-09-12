#include "validate.h"
#include <algorithm>
#include <cmath>
#include <random>
#include <vector>
using namespace std;

constexpr double EPS{ 1e-6 };

double progress(double x, double a, double b) {
   return (x-a)/(b-a);
}

double mylerp(double p, double a, double b) {
    return (1 - p)*a + p*b;
}

struct scoring {
    double guesses;
    double score;
};

double get_score(int guesses, int n){
    double nd = n;
    vector<scoring> scoring_for_level = {
        { 0, 100.0 },
        { 1, 100.0 },
        { max(1.0, ceil(log2(nd))), 80.0 },
        { max(1.0, 2*sqrt(nd)), 60.0 },
        { max(1.0, nd/2 + 1), 40.0 },
        { nd, 20.0 },
        { 2*nd, 0.0 },
    };

    if (guesses > scoring_for_level.rbegin()->guesses) return 0;

    for (size_t i = 1; i < scoring_for_level.size(); i++) {
        if (guesses <= scoring_for_level[i].guesses) {
            double p = progress(guesses, scoring_for_level[i-1].guesses, scoring_for_level[i].guesses);
            return mylerp(p, scoring_for_level[i-1].score, scoring_for_level[i].score);
        }
    }
    assert(false);
}

int find_unused(const vector<bool>& used, int old) {
    constexpr int default_seed{ 1337 };
    vector<int> available, out;
    for (int i = 0; i < static_cast<int>(used.size()); i++) {
        if (!used[i]) available.push_back(i);
    }
    if (available.empty()) {
        return old;
    }
    std::sample(available.begin(), available.end(), std::back_inserter(out), 1,
                std::mt19937 { default_seed });
    return out.back() + 1;
}

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n, fake_index;
    judge_in >> n >> fake_index;
    cout << n << endl;

    bool adaptive = fake_index == 0;
    vector<bool> used(n, false);
    if (adaptive) {
        fake_index = find_unused(used, fake_index);
    }

    string op;
    int queries{ 0 };
    while (author_out >> op) {
        if (op == "!") {
            int guessed_index;
            if (!(author_out >> guessed_index)) {
                wrong_answer("Wrong answer: Failed to read integer into final guess.\n");
            }

            if (guessed_index <= 0 || n < guessed_index) {
                wrong_answer("Wrong answer: The final guess is out of range.\n");
            }
            
            used[guessed_index - 1] = true;
            
            if (adaptive) {
                fake_index = find_unused(used, fake_index);
            }
            
            if (guessed_index != fake_index) {
                wrong_answer("Wrong answer: The final guess %d is incorrect.\n", guessed_index);
            }

            string trailing;
            author_out >> ws;
            if (author_out >> trailing) {
                wrong_answer("Wrong answer: Trailing output.\n");
            }

            double score = get_score(queries, n) * 100.0;
            score = static_cast<double>(static_cast<int>(score + EPS) / 100);
            if (score > 0) {
                accept_with_score(score);
            }
            wrong_answer("Wrong answer: Too many guesses.\n");
        }
        else if (op == "?") {
            queries++;
            vector<int> counts(n);
            int output{ 0 };
            for (int i = 0; i < n; i++) {
                if (!(author_out >> counts[i])) {
                    wrong_answer("Wrong answer: Failed to read integer into index %d for guess %d.\n", i, queries);
                }
                if (counts[i] < 0 || n < counts[i]) {
                    wrong_answer("Wrong answer: Integer at index %d for guess %d is out of range.\n", i, queries);
                }

                if (counts[i] > 0) {
                    used[i] = true;
                }
            }

            if (adaptive) {
                fake_index = find_unused(used, fake_index);
            }

            for (int i = 0; i < n; i++) {
                output += counts[i] * (i + 1 == fake_index ? n + 1 : n);
            }
            cout << output << endl;
        }
        else {
            wrong_answer("Wrong answer: Invalid token, expected '!' or '?'.\n");
        }
    }
    wrong_answer("Wrong answer: Unexpected end of output.\n");
}
