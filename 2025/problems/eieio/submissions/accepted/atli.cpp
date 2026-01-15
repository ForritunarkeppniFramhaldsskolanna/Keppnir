#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int res = b - 2 * a;
    if(res < 0 || res % 2 != 0 || (a - res / 2 < 0))
        cout << "Rong talning\n";
    else cout << res / 2 << '\n';
}
