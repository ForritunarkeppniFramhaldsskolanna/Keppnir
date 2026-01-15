#include<iostream>
using namespace std;

int main() {
    string cur = "", inp;
    cin >> inp;
    for(char c : inp) {
        if(c == '.')
            cur = "";
        cur.push_back(c);
    }
    cout << cur << '\n';
}
