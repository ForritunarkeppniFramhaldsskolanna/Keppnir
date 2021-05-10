#include "validate.h"
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <unordered_set>
using namespace std;

int n, m;
unordered_set<string> valid;
bool transition(string a, string b) {
    int diff = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            diff++;
            if (a[i] + 1 == b[i]) continue;
            if (a[i] - 1 == b[i]) continue;
            if (a[i] == '0' && b[i] == '9') continue;
            if (a[i] == '9' && b[i] == '0') continue;
            return false;
        }
    }

    return diff == 1;
}

int main(int argc, char **argv) {
    init_io(argc, argv);

    judge_in >> n >> m;

    string start, end;
    judge_in >> start >> end;
    valid.insert(start);
    valid.insert(end);

    for (int i = 0; i < m; i++) {
        string cur;
        judge_in >> cur;
        valid.insert(cur);
    }

    string judge_first, author_first;
    judge_ans >> judge_first;
    if (!(author_out >> author_first)) {
        wrong_answer("Empty output\n");
    }

    if (judge_first != author_first) {
        wrong_answer("Mismatch on first line, expected '%s', got '%s'\n", judge_first.c_str(), author_first.c_str());
    }
    if (judge_first != "Neibb") {
        int cnt = atoi(judge_first.c_str());

        string cur;
        if (!(author_out >> cur)) {
            wrong_answer("Unexpected end of input\n");
        }
        if (cur != start) {
            wrong_answer("Unexpected start number, expected '%s', got '%s'\n", start.c_str(), cur.c_str());
        }
        for (int i = 0; i < cnt; i++) {
            string nxt;
            if (!(author_out >> nxt)) {
                wrong_answer("Unexpected end of input\n");
            }
            if (valid.find(nxt) == valid.end()) {
                wrong_answer("Got unlucky number '%s'\n", nxt.c_str());
            }
            if (!transition(cur, nxt)) {
                wrong_answer("Invalid transition from '%s' to '%s'\n", cur.c_str(), nxt.c_str());
            }
            cur = nxt;
        }
        if (cur != end) {
            wrong_answer("Unexpected end number, expected '%s', got '%s'\n", end.c_str(), cur.c_str());
        }
    }

    string trash;
    if (author_out >> trash) {
        wrong_answer("Trailing output\n");
    }

    accept();
}
