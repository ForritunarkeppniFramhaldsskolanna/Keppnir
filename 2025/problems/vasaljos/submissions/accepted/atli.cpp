#include<iostream>
#include<string>
using namespace std;

void guess(int a, int b) {
    cout << a << ' ' << b << '\n' << flush;
    string s; cin >> s;
    if(s == "Ljos!") exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    if(n == 4) {
        for(int i = 0; i < 4; ++i)
            for(int j = i + 1; j < 4; ++j)
                guess(i + 1, j + 1);
    }
    for(int o = 0; o <= 3; o += 3) {
        guess(1 + o, 2 + o);
        guess(1 + o, 3 + o);
        guess(2 + o, 3 + o);
    }
    for(int i = 7; i < n; i += 2)
        guess(i, i + 1);
}
