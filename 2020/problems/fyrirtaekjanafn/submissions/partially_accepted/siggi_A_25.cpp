#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    string n;
    getline(cin,n);
    string outstr = "";

    for(char c : n){
        char lc = tolower(c);
        if(lc == 'a' || lc == 'e' || lc == 'o' || lc == 'i' || lc == 'u' || lc == 'y'){
            outstr = outstr + c;
        }
    }

    cout << outstr << endl;
    return 0;
}
