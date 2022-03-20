#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, d, x, a = 0;
    cin >> n >> k >> d;
    while(n--) {
        cin >> x;
        if(x + 14 <= d + k) a++;
    }
    cout << a << '\n';
}
