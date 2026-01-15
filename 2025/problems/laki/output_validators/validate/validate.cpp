#include "validate.h"
#include <iostream>
using namespace std;

string read_until_eof(istream &in) {
    string res = "", buf = "";
    while(getline(in, buf))
        res += buf;
    return res;
}

bool fuzzy_match(string &s, string &t) {
    int i = 0, j = 0;
    while(i < s.size() || j < t.size()) {
        if(i < s.size() && isspace(s[i])) {
            i++;
            continue;
        }
        if(j < t.size() && isspace(t[j])) {
            j++;
            continue;
        }
        if(i >= s.size() || j >= t.size())
            return false;
        if(s[i] != t[j]) return false;
        i++; j++;
    }
    return true;
}

int main(int argc, char **argv) {
    init_io(argc, argv);
    
    string judge_txt = read_until_eof(judge_ans);
    string author_txt = read_until_eof(author_out);
    string inp = read_until_eof(judge_in);

    if(fuzzy_match(judge_txt, author_txt)) {
        accept();
    }

    char group = ' ';

    // Uses old group names, not same as in actual data
    if(inp[0] == '"') group = 'D';
    else if(inp[0] == '0' && inp[1] == 'x') group = 'B';
    else if(inp[0] & (1 << 7)) group = 'F';
    else if(inp[0] == 'l') group = 'G';
    else if(inp[0] == '{') group = 'E';
    else if('a' <= inp[0] && inp[0] <= 'z') group = 'J';
    else if('A' <= inp[0] && inp[0] <= 'Z') group = 'I';
    else if(inp.find("mod") != string::npos) group = 'H';
    else if(inp.find("i") != string::npos) group = 'C';
    else group = 'A';

    if(group == 'A') {
        author_message("Það er svo gott að gera öðrum illt!\n");
        author_message("Being mean is so fun!\n");
    } else if(group == 'B') {
        author_message("Ég veit meir um tölvutölur en þú!\n");
        author_message("I know more about computer numbers than you!\n");
    } else if(group == 'C') {
        author_message("Ég tók örugglega meiri stærðfræði í framhaldsskóla en þú!\n");
        author_message("I definitely took more math in high school than you!\n");
    } else if(group == 'D') {
        author_message("Kemur sér vel að kunna meira um Javascript en þú!\n");
        author_message("Luckily I know more Javascript than you!\n");
    } else if(group == 'E') {
        author_message("Venn og Cantor geta lítið hjálpað lengur!\n");
        author_message("Venn and Cantor can't help you anymore!\n");
    } else if(group == 'F') {
        author_message("Ég vissi að aðrar grunntölur myndu rugla í þér! Ef tölva þín getur þá einu sinni sýnt þér rétta unicode stafi!\n");
        author_message("I knew that using other bases would get you! That's if your computer can even show you the right unicode letters in the first place!\n");
    } else if(group == 'G') {
        author_message("Versti óvinur allra framhaldsskólanema, lograr!\n");
        author_message("The worst enemy of all high schoolers, logarithms!\n");
    } else if(group == 'H') {
        author_message("Ef þú þekkir ekki leyndardóma Kínverjanna er það hingað og ekki lengra!\n");
        author_message("If you don't know the secrets of the Chinese you'll be stuck here!\n");
    } else if(group == 'I') {
        author_message("Fyrst forritun stoppar þig ekki, skulum sjá með efnafræði!\n");
        author_message("Alright, you're good at programming, but chemistry will stop you!\n");
    } else if(group == 'J') {
        author_message("Hingað og ekki lengra!\n");
        author_message("You will go no further!\n");
    } else {
        judge_error("Malformed input.\n");
    }

    wrong_answer("Incorrect answer.");
}

