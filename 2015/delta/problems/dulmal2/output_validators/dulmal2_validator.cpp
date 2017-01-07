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

void validate_sol(string original, int k, istream &in, error_fun error) {
    string code;
    in >> code;

    stringstream ans;
    for (size_t i = 0; i < code.size(); i += k) {
        ans << code[i];
    }

    if (ans.str() != original) {
        error("Got '%s' after decrypting solution, but expected '%s'", ans.str().c_str(), original.c_str());
    }
}

void check_case() {
    int k;
    judgein >> k;
    string s;
    judgein >> s;

    validate_sol(s, k, cin, wrong_answer);
    validate_sol(s, k, judgeans, judge_error);
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
