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

struct sol {
    set<string> walter;
    set<string> jesse;
    bool is_possible;
};

void get_sol(istream &in, sol &res, error_fun error) {

    string line;
    if (!getline(in, line)) {
        error("First line of output omitted");
    }

    stringstream ls(line);
    string fst, snd;

    if (ls >> fst && !(ls >> snd) && fst == "impossible") {
        res.is_possible = false;
        return;
    } else {
        res.is_possible = true;
    }

    stringstream ss(line);
    string s;
    while (ss >> s) {
        if (res.walter.find(s) != res.walter.end()) {
            error("Repeated item '%s'", s.c_str());
        }

        res.walter.insert(s);
    }

    if (!getline(in, line)) {
        // error("Second line of output omitted");
        line = "";
    }

    stringstream ss2(line);
    while (ss2 >> s) {
        if (res.jesse.find(s) != res.jesse.end()) {
            error("Repeated item '%s'", s.c_str());
        }

        res.jesse.insert(s);
    }
}

void validate_assignment(const vector<string> &names, const vector<pair<string, string> > &forbidden, sol &res, error_fun error) {

    set<string> both;
    set_intersection(res.walter.begin(), res.walter.end(),
            res.jesse.begin(), res.jesse.end(),
            std::inserter(both, both.begin()));

    if (both.size() != 0) {
        error("Repeated item '%s'", both.begin()->c_str());
    }

    set<string> either;
    set_union(res.walter.begin(), res.walter.end(),
            res.jesse.begin(), res.jesse.end(),
            std::inserter(either, either.begin()));


    for (size_t i = 0; i < names.size(); i++) {

        if (either.find(names[i]) == either.end()) {
            error("Item '%s' not used in output", names[i].c_str());
        }

        either.erase(names[i]);
    }

    if (either.size() != 0) {
        error("Unknown item '%s' specified in output", either.begin()->c_str());
    }

    for (size_t i = 0; i < forbidden.size(); i++) {

        bool walter_buys_a = res.walter.find(forbidden[i].first) != res.walter.end();
        bool walter_buys_b = res.walter.find(forbidden[i].second) != res.walter.end();

        if (walter_buys_a == walter_buys_b) {
            error("Suspicious pair of items '%s' and '%s' are bought by the same person", forbidden[i].first.c_str(), forbidden[i].second.c_str());
        }
    }
}

void check_case() {
    sol output;
    sol answer;

    get_sol(cin, output, wrong_answer);
    get_sol(judgeans, answer, judge_error);

    if (output.is_possible && !answer.is_possible) {
        wrong_answer("Output says 'possible', while answer is 'impossible'");
    }
    if (!output.is_possible && answer.is_possible) {
        wrong_answer("Output says 'impossible', while answer is 'possible'");
    }
    if (output.is_possible != answer.is_possible) {
        judge_error("Possibility comparision went wrong");
    }

    if (!answer.is_possible) {
        return;
    }

    int n;
    judgein >> n;
    vector<string> names(n);

    for (int i = 0; i < n; i++) {
        judgein >> names[i];
    }

    int m;
    judgein >> m;
    vector<pair<string, string> > forbidden(m);

    for (int i = 0; i < m; i++) {
        judgein >> forbidden[i].first >> forbidden[i].second;
    }

    validate_assignment(names, forbidden, answer, judge_error);
    validate_assignment(names, forbidden, output, wrong_answer);
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
