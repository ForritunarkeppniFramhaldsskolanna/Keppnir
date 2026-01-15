#include "validate.h"
using namespace std;

int main(int argc, char **argv) {
    init_io(argc, argv);
    
    string secret, given;

    getline(judge_in, secret);

    assert(!judge_in.eof());

    getline(author_out, given);

    if(author_out.eof()) {
        wrong_answer("Wrong answer: No newline before EOF.\n");
    }

    if(given.size() > 10) {
        wrong_answer("Wrong answer: Answer too long.\n");
    }

    for(char c : given) {
        if(c == ' ') continue;
        if(c >= '0' && c <= '9') continue;
        if(c >= 'a' && c <= 'z') continue;
        if(c >= 'A' && c <= 'Z') continue;
        wrong_answer("Wrong answer: Invalid character in output.\n");
    }

    if(given == secret) {
        wrong_answer("Wrong answer: Answer equals input.\n");
    }

    string trailing;
    if(author_out >> trailing) {
        wrong_answer("Wrong answer: Trailing output.\n");
    }
    accept();
}
