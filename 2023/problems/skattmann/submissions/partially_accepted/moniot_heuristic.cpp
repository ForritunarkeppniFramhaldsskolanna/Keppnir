#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int mxn = 1e4;
int eratos[mxn + 1];
int sigma[mxn + 1];
int score[mxn + 1];

void calc() {
    memset(eratos, -1, sizeof(eratos));
    for(int i = 2; i <= mxn; ++i) {
        if(eratos[i] == -1) eratos[i] = i;
        else continue;
        for(int j = i * i; j <= mxn; j += i) {
            eratos[j] = i;
        }
    }
    sigma[1] = 1;
    for(int i = 2; i <= mxn; ++i) {
        int x = i, p = eratos[i];
        while(x % p == 0) x /= p;
        sigma[i] = sigma[x] * (((i / x) * p - 1) / (p - 1));
    }
    for(int i = 1; i <= mxn; ++i) {
        score[i] = 2 * i - sigma[i];
    }
}

vi divisors(int x) {
    if(x == 1) return vi({1});
    int p = eratos[x], e = 0;
    while(x % p == 0) x /= p, e++;
    vi res;
    for(int d : divisors(x)) {
        int pe = 1;
        for(int i = 0; i <= e; ++i) {
            res.push_back(d * pe);
            pe *= p;
        }
    }
    return res;
}

void erase_score(set<ii> &scores, int x, int n) {
    ii rem(score[x], x);
    scores.erase(rem);
    for(int m = 2 * x; m <= n; m += x) {
        ii old(score[m], m);
        if(!scores.count(old)) continue;
        score[m] += x;
        scores.erase(old);
        scores.insert(ii(score[m], m));
    }
}

int main() {
    calc();
    int n; cin >> n;
    set<ii> scorepq;
    for(int i = 1; i <= n; ++i) {
        scorepq.insert(ii(score[i], i));
    }
    vi outp;
    while(scorepq.size() > 0 && (--scorepq.end())->first >= INT_MIN / 2) {
        int pick = (--scorepq.end())->second;
        bool taxable = false;
        for(int d : divisors(pick)) {
            if(d == pick) continue;
            ii srch(score[d], d);
            if(scorepq.count(srch)) {
                taxable = true;
                erase_score(scorepq, d, n);
            }
        }
        if(!taxable) {
            scorepq.erase(ii(score[pick], pick));
            score[pick] = INT_MIN;
            scorepq.insert(ii(score[pick], pick));
            continue;
        }
        erase_score(scorepq, pick, n);
        outp.push_back(pick);
    }
    cout << outp.size() << '\n';
    for(int x : outp) cout << x << ' ';
    cout << '\n';
}
