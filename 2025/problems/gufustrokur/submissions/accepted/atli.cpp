#include<iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if(x > y) swap(x, y);
    int ans = y - x;
    ans = min(ans, 360 + x - y);
    cout << ans << '\n';
}
