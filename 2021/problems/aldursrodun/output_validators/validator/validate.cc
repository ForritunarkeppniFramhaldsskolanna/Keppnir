#include "validate.h"
#include <algorithm>
using namespace std;
typedef pair<string, string> ss;

int gcd(int a, int b)
{
	int r;
	while (b > 0) { r = a%b; a = b; b = r; }
	return a;
}

void read_solution(istream &sol, feedback_function feedback, int n, int* b) {
	int i;
	for (i = 0; i < n; i++) if(!(sol >> b[i])) feedback("premature EOF or EOL.\n");
}

void check_case() {
	int i, n, m;
    judge_in >> n;
	int a[n], b[n];
	for (i = 0; i < n; i++) if(!(judge_in >> a[i])) judge_error("Not enough input.\n");
	if (tolower(judge_ans.peek()) == 'n' && tolower(author_out.peek()) == 'n') accept();
	if (tolower(judge_ans.peek()) == 'n' && tolower(author_out.peek()) != 'n') wrong_answer("Author gave answer when it should be 'Neibb'.\n");

    read_solution(author_out, wrong_answer, n, b);

	for (i = 0; i < n - 1; i++) if (gcd(b[i], b[i + 1]) == 1) wrong_answer("gcd(%d, %d) = 1.\n", b[i], b[i + 1]);
	sort(a, a + n);
	sort(b, b + n);
	for (i = 0; i < n; i++) if (a[i] != b[i]) wrong_answer("Element %d in authour answer is not in the input.\n");
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
