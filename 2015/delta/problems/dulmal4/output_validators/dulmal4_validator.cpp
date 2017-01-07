#include <algorithm>
#include <cassert>
#include <cstdarg>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

const int EXIT_AC = 42;
const int EXIT_WA = 43;

typedef vector<int> vi;
typedef void (*error_fun)(const char *, ...);

ifstream judgein, judgeans;
FILE *judgemessage = NULL;
int kase, verdict = EXIT_AC;

void wrong_answer(const char *err, ...) {
    va_list pvar;
    va_start(pvar, err);
    vfprintf(judgemessage, err, pvar);
    fprintf(judgemessage, "\n");
    exit(EXIT_WA);
}

void judge_error(const char *err, ...) {
    va_list pvar;
    va_start(pvar, err);
    // if judgemessage has not been set up yet, write error to stderr
    if (!judgemessage) judgemessage = stderr;
    vfprintf(judgemessage, err, pvar);
    fprintf(judgemessage, "\n");
    assert(!"Judge Error");
}

template <typename Stream>
void openfile(Stream &stream, const char *file, const char *whoami) {
    stream.open(file);
    if (stream.fail())
        judge_error("%s: failed to open %s\n", whoami, file);
}

FILE *openfeedback(const char *feedbackdir, const char *feedback, const char *whoami) {
    int len = strlen(feedbackdir) + strlen(feedback) + 1000;
    char path[len];
    sprintf(path, "%s%s", feedbackdir, feedback);
    FILE *res = fopen(path, "w");
    if (!res)
        judge_error("%s: failed to open %s for writing", whoami, path);
    return res;
}

void validate_sol(vector<string> S, string sol, string cur, error_fun error) {

    // for (int i = 0; i < (int)cur.size(); i++) {
    //     if (cur[i] < 'a' || cur[i] > 'z') {
    //         error("invalid character '%c' in answer\n", cur[i]);
    //     }
    // }

    int n = S.size();
    vector<bool> found(n, false);

    for (int k = 1; k <= (int)cur.size(); k++) {
        stringstream ss;
        int at = 0;
        while (at < (int)cur.size()) {
            ss << cur[at];
            at += k;
        }

        for (int i = 0; i < n; i++) {
            if (ss.str() == S[i]) {
                found[i] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!found[i]) {
            error("could not find '%s' in answer '%s'\n", S[i].c_str(), cur.c_str());
        }
    }

    if (cur.size() > sol.size()) {
        judge_error("team solution found shorter answer '%s'\n", cur.c_str());
    }

    if (cur.size() < sol.size()) {
        error("team returned suboptimal solution\n");
    }
}

void check_case() {
    int n;
    judgein >> n;

    vector<string> S;
    for (int i = 0; i < n; i++) {
        string x;
        judgein >> x;
        S.push_back(x);
    }

    string team_sol,
           judge_sol;

    cin >> team_sol;
    judgeans >> judge_sol;

    validate_sol(S, judge_sol, judge_sol, judge_error);
    validate_sol(S, judge_sol, team_sol, wrong_answer);
}

const char *USAGE = "Usage: %s judge_in judge_ans feedback_dir [options] < team_out";

int main(int argc, char **argv) {
    if(argc < 4)
        judge_error(USAGE, argv[0]);
    judgemessage = openfeedback(argv[3], "judgemessage.txt", argv[0]);
    openfile(judgein, argv[1], argv[0]);
    openfile(judgeans, argv[2], argv[0]);

    check_case();

    string buf;
    if (cin >> buf) {
        wrong_answer("Trailing output");
    }

    exit(verdict);
}
