#include<bits/stdc++.h>
using namespace std;

vector<double> faclg;

void prepfac(int n) {
    faclg.resize(n + 5);
    faclg[0] = 0.0;
    for(int i = 1; i < n + 5; ++i) {
        faclg[i] = faclg[i - 1] + log((double) i);
    }
}

double nckd2lg(int n, int k) {
    return faclg[n] - faclg[k] - faclg[n - k];
}


int main() {
    int n, m;
    cin >> n >> m;
    prepfac(n);
    double sm = 0.0;
    for(int k = 0; k <= min(n, m); ++k) {
        sm += exp(nckd2lg(n, k) - n * log(2)) * (m - k);
    }
    cout << setprecision(15) << sm << '\n';
}
