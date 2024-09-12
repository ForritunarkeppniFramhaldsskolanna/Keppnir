#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int d = b * b - 4 * a * c;

    if (d > 0) cout << 2 << endl;
    else if (d == 0) cout << 1 << endl;
    else cout << 0 << endl;
}
