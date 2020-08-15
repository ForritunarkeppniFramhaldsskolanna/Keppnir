#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;

void counting_sort(vi& v){
    vi _v(v.size());
    vi cnt(100001);
    for(int i=0; i<v.size(); i++){
        cnt[v[i]]++;
    }

    for(int i=1; i<cnt.size(); i++){
        cnt[i] += cnt[i-1];
    }

    for(int i=0; i<v.size(); i++){
        _v[cnt[v[i]]-1] = v[i];
        cnt[v[i]]--;
    }

    for(int i=0; i<v.size(); i++){
        v[i] = _v[i];
    }
}

int main() {
    int n;
    cin >> n;

    vi t(n);
    for(int i=0;i<n;i++){
        cin >> t[i];
    }

    counting_sort(t);

    ll top_sum = 0;
    ll bottom_sum = 0;
    for(int i=1;i<=n;i++){
        top_sum += (ll)(2 * i - n - 1) * t[i-1];
        bottom_sum += (ll)n * t[i-1];
    }

    cout << fixed << setprecision(17) << (double)top_sum / (double)bottom_sum << endl;

    return 0;
}

