#include "validate.h"
#include <vector>
using namespace std;

void split(const string &txt, vector<string> &strs)
{
    stringstream stream(txt);

    string word;
    while (stream >> word) {
        strs.push_back(word);
    }

    return;
}

int main(int argc, char **argv) {
    init_io(argc, argv);

    string secret, given, inp;


    int n, l, t;
    judge_in >> n >> l >> t;

    vector<string> judge_lines, author_lines, words, correct_words(n);

    for (int i = 0; i < n; i++) {
        judge_in >> correct_words[i];
    }

    while (getline(judge_ans, inp)) {
        judge_lines.push_back(inp);
    }

    if (judge_lines[0] == "/ff") {
        author_out >> inp;
        if (inp != "/ff") {
            wrong_answer("Wrong answer: Judge said /ff, but author not.\n");
        }

        string trailing;
        if (author_out >> trailing) {
            wrong_answer("Wrong answer: Trailing output.\n");
        }

        accept();
    }

    // We don't want to get the last newline
    for (int i = 0; i < judge_lines.size(); i++) {
        if(!getline(author_out, inp)){
            wrong_answer("Wrong answer: Answer is too short");
        }
        author_lines.push_back(inp);
    }

    string trailing;
    if (author_out >> trailing) {
        wrong_answer("Wrong answer: Answer is too long.\n");
    }

    for (string line : author_lines) {
        if (l * t < line.size() + 1) {
            wrong_answer("Wrong answer: Line is too long.\n");
        }
        split(line, words);
    }

    if (words.size() != n) {
        wrong_answer("Wrong answer: Words count does not match n.\n");
    }

    if (!equal(correct_words.begin(), correct_words.end(), words.begin())) {
        wrong_answer("Wrong answer: Author solution does not match judge input.\n");
    }

    accept();
}