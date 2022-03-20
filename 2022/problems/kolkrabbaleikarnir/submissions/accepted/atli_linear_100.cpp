#include<bits/stdc++.h>
using namespace std;

struct kahan {
    double sm, c;
    kahan() : sm(0.0), c(0.0) { }
    void add_val(double d) {
        double y = d - c;
        double t = sm + y;
        c = (t - sm) - y;
        sm = t;
    }
    double get_sm() {
        return sm;
    }
};

vector<double> faclg;

void prepfac(int n) {
    faclg.resize(n + 5);
    faclg[0] = 0.0;
    kahan sm;
    for(int i = 1; i < n + 5; ++i) {
        sm.add_val(log((double) i));
        faclg[i] = sm.get_sm();
    }
}

double nckd2lg(int n, int k) {
    return faclg[n] - faclg[k] - faclg[n - k];
}


int main() {
    int n, m;
    cin >> n >> m;
    prepfac(n);
    kahan sm;
    for(int k = 0; k <= min(n, m); ++k) {
        sm.add_val(exp(nckd2lg(n, k) - n * log(2)) * (m - k));
    }
    cout << setprecision(15) << sm.get_sm() << '\n';
}
