#include "validate.h"
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n;
    judge_in >> n;

    vector<set<int> > want(n);
    for(int i = 0; i < n; i++)
    {
        int k;
        judge_in >> k;
        for(int j = 0; j < k; j++)
        {
            int val;
            judge_in >> val;
            want[i].insert(val-1);
        }
    }

    string correct;
    judge_ans >> correct;

    string guess;
    if (!(author_out >> guess)) {
        wrong_answer("Empty output\n");
    }

    string no_answer_string = "Neibb";
    if (correct == no_answer_string) {
        if (guess != no_answer_string) {
            wrong_answer("There is no solution, but they claim there is a solution\n");
        }
    } else {
        if (guess == no_answer_string) {
            wrong_answer("There is a solution, but they claim there is no solution\n");
        }
        
        vector<int> ordering(n);
        vector<int> sitting(n, -1);
        try {
            ordering[0] = stoi(guess);
        }
        catch (const std::invalid_argument& ia) {
            wrong_answer("First element of author solution could not be parsed as number\n");
        }
        for(int i = 1; i < n; i++)
        {
            if (!(author_out >> ordering[i]))
            {
                wrong_answer("Incorrect length of author solution\n");
            }
        }


        for(int i = 0; i < n; i++)
        {
            int cur = ordering[i];
            if(cur < 1 || cur > n)
            {
                wrong_answer("Value at position %d of author solution is not between 1 and n\n", i);
            }
            if(sitting[cur-1] != -1)
            {
                wrong_answer("Value at position %d of author solution already appeared at position %d\n",
                             i,
                             sitting[cur-1]);
            }
            if (want[cur-1].find(i) == want[cur-1].end()) {
                wrong_answer("Value at position %d of author solution is not allowed at that position\n", i);
            }
            sitting[cur-1] = i;
        }
    }

    string trash;
    if (author_out >> trash) {
        wrong_answer("Trailing output\n");
    }

    accept();
}
