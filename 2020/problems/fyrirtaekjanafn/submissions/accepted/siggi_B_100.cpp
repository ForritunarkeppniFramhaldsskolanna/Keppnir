#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    getline(cin,n);
    vector<char> outvec = vector<char>();
    for(char c : n){
        char lc = tolower(c);
        if(lc == 'a' || lc == 'e' || lc == 'o' || lc == 'i' || lc == 'u' || lc == 'y'){
            outvec.push_back(c);
        }
    }
    stringstream outstr;
    for(vector<char>::const_iterator itr = outvec.begin();  itr != outvec.end(); ++itr) {
        outstr << *itr;
    }
    cout << outstr.str() << endl;
    return 0;
}
