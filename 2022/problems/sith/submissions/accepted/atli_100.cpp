#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int a, b, c;
    getline(cin, s);
    cin >> a >> b >> c;
    if(a >= b) cout << "VEIT EKKI\n";
    else if(c == a - b) cout << "JEDI\n";
    else cout << "SITH\n";
}
