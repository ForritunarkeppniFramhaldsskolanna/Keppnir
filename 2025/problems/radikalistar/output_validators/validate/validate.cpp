#include "validate.h"
#include <algorithm>
#include <vector>
using namespace std;

vector<int> line_to_ints(const string &s, bool err) {
    stringstream ss(s);
    vector<int> ret;
    string buf;
    while(ss >> buf) {
        int x;
        stringstream inner(buf);
        if(!(inner >> x) && err) {
            wrong_answer("Wrong answer: Failed to parse int in output.\n");
        }
        ret.push_back(x);
    }
    return ret;
}

int main(int argc, char **argv) {
    init_io(argc, argv);
    
    string judge_l, author_l;
    while(getline(judge_ans, judge_l)) {
        if(judge_l.empty()) break;
        if(!getline(author_out, author_l)) {
            wrong_answer("Wrong answer: Missing output.\n");
        }
        vector<int> author_ints = line_to_ints(author_l, true);
        vector<int> judge_ints = line_to_ints(judge_l, false);
        sort(author_ints.begin(), author_ints.end());
        sort(judge_ints.begin(), judge_ints.end());
        if(author_ints != judge_ints) {
            wrong_answer("Wrong answer: Incorrect output.\n");
        }
    }
    string trailing;
    author_out >> ws;
    if(author_out >> trailing) {
        wrong_answer("Wrong answer: Trailing output.\n");
    }
    accept();
}

