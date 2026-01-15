#include<iostream>
#include<cassert>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] & (1 << 7)) {
            assert(s[i] == '\xc3');
            assert(i + 1 < s.size());
            i++;
            if(s[i] == '\x81' || s[i] == '\xa1')
                cout << 'a';
            if(s[i] == '\x90' || s[i] == '\xb0')
                cout << 'd';
            if(s[i] == '\x89' || s[i] == '\xa9')
                cout << 'e';
            if(s[i] == '\x8d' || s[i] == '\xad')
                cout << 'i';
            if(s[i] == '\x93' || s[i] == '\xb3')
                cout << 'o';
            if(s[i] == '\x9a' || s[i] == '\xba')
                cout << 'u';
            if(s[i] == '\x9d' || s[i] == '\xbd')
                cout << 'y';
            if(s[i] == '\x9e' || s[i] == '\xbe')
                cout << 't' << 'h';
            if(s[i] == '\x86' || s[i] == '\xa6')
                cout << 'a' << 'e';
            if(s[i] == '\x96' || s[i] == '\xb6')
                cout << 'o';
        } else {
            if(!isalnum(s[i])) continue;
            cout << ((char) tolower(s[i]));
        }
    }
    cout << ".is\n";
}
