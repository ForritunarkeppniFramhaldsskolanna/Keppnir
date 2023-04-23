#include "validate.h"
#include <set>
#include <vector>
#include <math.h>
using namespace std;

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n;
    judge_in >> n;

    int pick_num, pick;
    if(!(author_out >> pick_num)) {
        wrong_answer("Wrong answer: Missing solution length.\n");
    }
    long long taxsm = 0, takesm = 0;
    set<int> tax, take;
    for(int i = 0; i < pick_num; ++i) {
        if(!(author_out >> pick)) {
            wrong_answer("Wrong answer: Missing picks.\n");
        }
        if(take.count(pick)) {
            wrong_answer("Wrong answer: Duplicate pick %d.\n", pick);
        }
        if(tax.count(pick)) {
            wrong_answer("Wrong answer: %d already taken by taxman.\n", pick);
        }
        bool taxable = false;
        for(int d = 1; d * d <= pick; ++d) {
            if(pick % d != 0) continue;
            vector<int> divs = { d };
            if(d * d != pick) divs.push_back(pick / d);
            for(int x : divs) {
                if(x == pick) continue;
                if(tax.count(x)) continue;
                if(take.count(x)) continue;
                taxable = true;
                tax.insert(x);
                taxsm += x;
                cerr << "Tax: " << x << endl;
            }
        }
        if(!taxable) {
            cerr << "Fail on: " << pick << endl;
            wrong_answer("Wrong answer: %d invalid, not taxable.\n", pick);
        }
        take.insert(pick);
        takesm += pick;
        cerr << "Take: " << pick << endl;
    }
    string s;
    author_out >> ws;
    if(author_out >> s) {
        wrong_answer("Wrong answer: Trailing output.\n");
    }

    int judge_num, judge_pick;
    judge_ans >> judge_num;
    long long judge_sum = 0;
    for(int i = 0; i < judge_num; ++i) {
        judge_ans >> judge_pick;
        judge_sum += judge_pick;
    }

    double half_sum = n; half_sum *= n + 1; 
    half_sum /= 4.0; half_sum = ceil(half_sum);
    double score = (half_sum - takesm) / (half_sum - judge_sum);
    score = max(score, 0.0);
    score = min(score, 1.0);
    accept_with_score(round(score * 100) / 100);
}
