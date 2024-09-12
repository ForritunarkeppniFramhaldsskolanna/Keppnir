#include "validate.h"
#include <map>
#include <vector>
#include <set>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n, c;
    judge_in >> n >> c;
    map<string, pair<int,int>> data;

    for(int i = 0; i < n; ++i) {
        string s;
        int a, b;
        judge_in >> s >> a >> b;
        if(a != 0 && b != 0) {
            int g = gcd(a, b);
            a /= g; b /= g;
        }
        data[s] = make_pair(a, b);
    }
    
    set<string> seen_names;
    vector<pair<int,int>> nonz_ans, nonz_ref;

    for(int i = 0; i < n; ++i) {
        string ans, ref;
        if(!(author_out >> ans)) {
            wrong_answer("Failed to read %d-th name in output.\n", i + 1);
        }
        if(!data.count(ans)) {
            wrong_answer("%d-th name given is not in input.\n", i + 1);
        }
        if(seen_names.count(ans)) {
            wrong_answer("Duplicate lines in output.\n");
        }
        seen_names.insert(ans);
        judge_ans >> ref;
        if(data[ans] != make_pair(0, 0)) nonz_ans.push_back(data[ans]);
        if(data[ref] != make_pair(0, 0)) nonz_ref.push_back(data[ref]);
    }
    for(int i = 0; i < nonz_ans.size(); ++i) {
        if(nonz_ans[i] == nonz_ref[i]) continue;
        if(nonz_ans[i].first == 0 && nonz_ref[i].first == 0) continue;
        if(nonz_ans[i].second == 0 && nonz_ref[i].second == 0) continue;
        wrong_answer("Output not in valid order.\n");
    }
    string s;
    author_out >> ws;
    if(author_out >> s) {
        wrong_answer("Trailing output.\n");
    }
    accept();
}
