#include "validate.h"
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n, m;
    judge_in >> n >> m;

    string correct;
    judge_ans >> correct;

    string guess;
    if (!(author_out >> guess)) {
        wrong_answer("Empty output\n");
    }

    transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
    transform(correct.begin(), correct.end(), correct.begin(), ::toupper);

    if (correct == "VILLA") {
        if (guess != "VILLA") {
            wrong_answer("There is an error, but they claim there is a solution\n");
        }
    } else {
        if (guess == "VILLA") {
            wrong_answer("There is a solution, but they claim there is an error\n");
        }

        if (guess.size() != correct.size()) {
            wrong_answer("Incorrect length of author solution\n");
        }

        for (int i = 0; i < n; i++) {
            switch (guess[i]) {
                case 'G':
                case 'T':
                case 'A':
                case 'C':
                    break;
                default:
                    wrong_answer("Incorrect character at position %d of author solution\n", i);
            }
        }

        for (int i = 0; i < m; i++) {
            int start;
            string s;
            judge_in >> start >> s;
            start--;

            bool either = false;
            for (int dir = 0; dir < 2; dir++) {
                bool ok = true;
                for (int j = 0; j < (int)s.size(); j++) {
                    char p = dir == 0 ? s[j] : s[(int)s.size() - 1 - j];
                    if (guess[start + j] != p) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    either = true;
                    break;
                }
            }
            if (!either) {
                wrong_answer("DNA part %d does not fit in author solution\n", i+1);
            }
        }
    }

    string trash;
    if (author_out >> trash) {
        wrong_answer("Trailing output\n");
    }

    accept();
}
