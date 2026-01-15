#include<iostream>
using namespace std;

int main() {
    int i, x, y, z = 3;
    cin >> i;
    if(i == 1) cin >> x, y = x;
    if(i == 2) cin >> x >> y;
    if(i == 3) cin >> x >> y >> z;
    cout << x * y * z - (x - 2) * (y - 2) * (z - 1) << '\n';
}
