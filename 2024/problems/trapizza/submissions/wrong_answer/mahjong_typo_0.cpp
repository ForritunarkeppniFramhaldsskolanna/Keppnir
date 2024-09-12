#include<bits/stdc++.h>
using namespace std;

int main() {
    double d, a, b, h;
    cin >> d >> a >> b >> h;
    double area_1 = M_PI * (d / 2) * (d / 2);
    double area_2 = h * (a + b) / 2;
    if(area_1 == area_2) cout << "Jafn storar!\n";
    else if(area_1 > area_2) cout << "Majong!\n";
    else cout << "Trapizza!\n";
}
