#include<iostream>
#include<cmath>
using namespace std;

int main() {
    long double y; cin >> y;
    y *= 100.0;
    y = sqrt(y);
    long double A = 2, B = 224, C = 795 - y;
    long double D = B * B - 4 * A * C;
    long double z = (-B + sqrt(D)) / (2 * A);
    long long ans = ceil(z);
    if(ans < 0) ans = 0;
    cout << ans << '\n';
}
