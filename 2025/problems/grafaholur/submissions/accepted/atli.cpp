#include<iostream>
using namespace std;

int main() {
    double x, y, z, a, b;
    cin >> x >> y >> z >> a >> b;
    double ans = b * y * x / z / a;
    cout << ans << '\n';
}
