#include "validate.h"
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int n, m;
const int MAX_SOLUTION_SIZE = 10000;

bool is_legal_move(vector<vector<int> >& state, char move, int& r, int& c)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (state[i][j] == n*m) r = i, c = j;
    if (move == 'U') return r < n-1;
    else if (move == 'D') return r > 0;
    else if (move == 'L') return c < m-1;
    else if (move == 'R') return c > 0;
    return false;
}

bool execute_move(vector<vector<int> >& state, char move)
{
    int r, c;
    if (!is_legal_move(state, move, r, c)) return false;
    
    if (move == 'U') swap(state[r][c], state[r+1][c]);
    else if (move == 'D') swap(state[r][c], state[r-1][c]);
    else if (move == 'L') swap(state[r][c], state[r][c+1]);
    else if (move == 'R') swap(state[r][c], state[r][c-1]);

    return true;
}

bool is_solved(vector<vector<int> >& state)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (state[i][j] != i*m + j + 1)
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char **argv) {
    init_io(argc, argv);

    judge_in >> n >> m;

    vector<vector<int> > state(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int val;
            judge_in >> val;
            state[i].push_back(val);
        }
    }

    string correct;
    judge_ans >> correct;

    string guess;
    author_out >> guess;

    string no_answer_string = "impossible";
    if (correct == no_answer_string) {
        if (guess != no_answer_string) {
            wrong_answer("There is no solution, but they claim there is a solution\n");
        }
    } else {
        if (guess == no_answer_string) {
            wrong_answer("There is a solution, but they claim there is no solution\n");
        }

        if (guess.size() > MAX_SOLUTION_SIZE)
        {
            wrong_answer("Solution of length %d is too long, max length is %d\n", guess.size(), MAX_SOLUTION_SIZE);
        }

        for(size_t i = 0; i < guess.size(); i++)
        {
            if(!execute_move(state, guess[i]))
            {
                wrong_answer("Illegal move at position %d\n", i);
            }
        }

        if (!is_solved(state))
        {
            wrong_answer("Moves did not result in solved state %d\n");
        }
    }

    string trash;
    if (author_out >> trash) {
        wrong_answer("Trailing output\n");
    }

    accept();
}
