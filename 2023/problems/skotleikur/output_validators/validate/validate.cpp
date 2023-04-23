
#include "validate.h"
#include <set>
#include <vector>
#include <math.h>
using namespace std;

int main(int argc, char **argv)
{
    init_io(argc, argv);

    int judge_n;
    judge_ans >> judge_n;

    int author_n;
    if (!(author_out >> author_n))
    {
        wrong_answer("Wrong answer: Missing solution length.\n");
    }

    if (author_n != judge_n)
    {
        wrong_answer("Wrong answer: Incorrect number of kills and assist pairs.\n");
    }

    set<pair<int, int>> judge_set;
    for (int i = 0; i < judge_n; i++) {
        int judge_kill, judge_assist;
        judge_ans >> judge_kill >> judge_assist;
        judge_set.insert(make_pair(judge_kill, judge_assist));
    }

    set<pair<int, int>> author_set;
    for (int i = 0; i < author_n; i++)
    {
        int author_kill, author_assist;
        author_out >> author_kill >> author_assist;
        pair<int, int> author_pair = make_pair(author_kill, author_assist);
        if (author_set.insert(author_pair).second)
        {
            // solution was not found in judge pairs
            if (judge_set.find(author_pair) == judge_set.end())
            {
                wrong_answer("Wrong answer: (%d, %d) invalid kill/assist combination.\n", author_kill, author_assist);
            }

        }
        // author found the same pair again
        else
        {
            wrong_answer("Wrong answer: duplicate kill/assist combination (%d, %d).\n", author_kill, author_assist);
        }
    }

    accept();
}
