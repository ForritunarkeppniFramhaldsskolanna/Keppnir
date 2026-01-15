#include "validate.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> read_throw(istream &in, feedback_function f, int j) {
    int k; 
    if(!(in >> k)) {
        f("Failed to read number of darts.\n");
    }
    vector<string> darts(k);
    for(int i = 0; i < k; ++i) {
        in >> ws;
        if(!(getline(in, darts[i]))) {
            f("Failed to read dart " + to_string(i) + " in throw " + to_string(j) + ".\n");
        }
    }
    return darts;
}

int main(int argc, char **argv) {
    init_io(argc, argv);

    int judge_n; 
    judge_ans >> judge_n;
    int out_n;
    if(!(author_out >> out_n)) {
        wrong_answer("Failed to read number of ways at start of answer.\n");
    }
    if(out_n != judge_n) {
        wrong_answer("Wrong number of ways.\n");
    }
    vector<vector<string>> judge_ways, out_ways;

    for(int i = 0; i < out_n; ++i) {
        judge_ways.push_back(read_throw(judge_ans, judge_error, i));
        out_ways.push_back(read_throw(author_out, wrong_answer, i));
    }
    sort(judge_ways.begin(), judge_ways.end());
    sort(out_ways.begin(), out_ways.end());
    for(int i = 0; i < out_n; ++i) {
        if(judge_ways[i] != out_ways[i]) {
            wrong_answer("Throws are not correct.\n");
        }
    }
    author_out >> ws;
    string trailing;
    if(author_out >> trailing) {
        wrong_answer("Wrong answer: Answer is too long.\n");
    }
    accept();
}
