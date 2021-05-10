#include "validate.h"
#include <vector>
using namespace std;
typedef pair<string, string> ss;

string read_solution(istream &sol, feedback_function feedback) {
	string s;
    if(!(sol >> s)) feedback("premature EOF or EOL");
    return s;
}

int is_subseq(string s, string t)
{ // Is |t| substring of |s|?
	int i, j = 0;
	for (i = 0; i < s.size(); i++) if (j < t.size() && s[i] == t[j]) j++;
	return j == t.size();
}

void check_case() {
	ss s;
    judge_in >> s.first;
    judge_in >> s.second;

    string ans = read_solution(judge_ans, judge_error);
    string out = read_solution(author_out, wrong_answer);

	if (!is_subseq(out, s.first)) wrong_answer("First string is not subsequence.");
	if (!is_subseq(out, s.second)) wrong_answer("Second string is not subsequence.");
	if (out.size() < ans.size()) judge_error("Answer string is shorter than judges.");
	if (out.size() > ans.size()) wrong_answer("Answer string is longer than judges.");
}


int main(int argc, char **argv) {
    init_io(argc, argv);

    check_case();

    string trash;
    if(author_out >> trash) {
        wrong_answer("Trailing output");
    }

    accept();
}
