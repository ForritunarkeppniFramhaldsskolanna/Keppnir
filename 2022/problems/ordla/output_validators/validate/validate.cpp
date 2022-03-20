#include "validate.h"
#include <algorithm>
#include <climits>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n;
    judge_in >> n;
    vector<string> words;
    set<string> valid_words;
    for (int i = 0; i < n; i++) {
        string word;
        judge_in >> word;
        words.push_back(word);
        valid_words.insert(word);
    }

    vector<string> perm = words;
    random_shuffle(perm.begin(), perm.end());
    string correct_word = perm[0];

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << words[i] << endl;
    }

    int guesses = 0;
    while (true) {
        string guess;
        if (!(author_out >> guess)) {
            wrong_answer("Wrong answer: unexpected EOF.\n");
        }
        if (valid_words.find(guess) == valid_words.end()) {
            wrong_answer("Wrong answer: guess was not in the dictionary.\n");
        }
        guesses++;

        vector<char> color(5, 'X');
        map<char, int> count;
        for (int i = 0; i < 5; i++) {
            if (guess[i] == correct_word[i]) {
                color[i] = 'O';
            } else {
                count[correct_word[i]]++;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (guess[i] != correct_word[i] && count[guess[i]] > 0) {
                color[i] = '/';
                count[guess[i]]--;
            }
        }
        string c(color.begin(), color.end());
        cout << c << endl;
        if (c == "OOOOO") {
            break;
        }
    }

    /* double x = (guesses-1) * 1.0 / n * 2; */
    /* accept_with_score(max(0.0, 1 - x / (1 + exp(-x)))); */
    accept_with_score(max(0.0, 1 - 1.0 * (guesses-1) * (guesses-1) / n));
}
