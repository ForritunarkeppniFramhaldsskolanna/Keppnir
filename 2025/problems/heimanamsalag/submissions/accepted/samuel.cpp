#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

bool check(ll x, vector<pair<ll, ii>> &v) {
    priority_queue<ii, vector<ii>, greater<ii>> q;

    ll i = 0;
    ll at = -1;
    ll left = 0;
    while (i < v.size() || !q.empty()) {
        // Add all that start before our current date
        if (i < v.size() && v[i].first <= at) {
            q.push({v[i].second.first, v[i].second.second});
            i++;
            continue;
        }
        // if q is empty, add the top one
        if (i < v.size() && q.empty()) {
            q.push({v[i].second.first, v[i].second.second});
            if (v[i].first > at) {
                left = x;
                at = v[i].first;
            }
            i++;
            continue;
        }
        // cout << "i: " << i << endl;
        ii top = q.top();
        q.pop();

        // cout << "at: " << at << ' ' << top.second << ' ' << left << endl;

        // If our date is further than last date return false
        if (at > top.first)
            return false;
        
        // Select the date we want to finish counting on
        ll end = top.first;
        if (i < v.size()) {
            end = min(end, v[i].first - 1);
        }

        // cout << "end: " << end << endl;

        // If remainder covers what is left
        if (top.second < left) {
            left -= top.second;
        }
        // If we can finish this task before the desired time then we do so
        else if (top.second <= (end - at) * x + left) {
            top.second -= left;
            at += top.second / x + 1;
            top.second -= top.second / x * x;
            left = x - top.second;
            if (left == 0) {
                at++;
                left = x;
            }
        // Finish as much as we can and add the remainder
        } else {
            // cout << "Left: " << left << endl;
            top.second -= left;
            // cout << "end - at " << end - at << endl;
            top.second -= (end - at) * x;
            at += (end - at) + 1;
            left = x;
            // cout << "Leaving: " << top.second << endl;
            q.push({top.first, top.second});
        }
    }

    return true;
}

int main() {
    ll n;
    cin >> n;

    vector<pair<ll, ii>> v(n);

    ll r = 0;

    for (ll i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;
        r += v[i].second.second;
    }

    sort(v.begin(), v.end());

    // cout << check(999911160, v) << endl;
    // return 0;

    ll l = 1;
    ll ans = 0;
    while (l <= r) {
        ll m = (l + r) / 2;
        // cout << "Trying: " << m << endl;
        if (check(m, v)) {
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }

    cout << ans << endl;
}
