#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> a(n), b(n), t(n);
    ll lo = 1, hi = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> t[i], hi += t[i];
    if(hi == 0) {
        cout << 0 << '\n';
        return 0;
    }
    vector<ii> st(n);
    for(int i = 0; i < n; ++i)
        st[i] = ii(a[i], i);
    sort(st.begin(), st.end());
    while(hi > lo) {
        ll md = lo + (hi - lo) / 2;
        priority_queue<ii, vector<ii>, greater<ii>> nd;
        int st_ind = 0;
        ll cur_day = 0, hours_left = md, top_left = -1;
        bool possible = true;
        while(st_ind < n || nd.size() > 0) {
            if(st_ind < n && st[st_ind].first <= cur_day) {
                int i = st[st_ind].second;
                st_ind++;
                nd.push(ii(b[i], t[i]));
                continue;
            }
            if(st_ind < n && nd.empty()) {
                int i = st[st_ind].second;
                st_ind++;
                if(a[i] > cur_day) {
                    cur_day = a[i];
                    hours_left = md;
                }
                nd.push(ii(b[i], t[i]));
                continue;
            }
            if(cur_day > nd.top().first) {
                possible = false;
                break;
            }
            int until = nd.top().first;
            if(st_ind < n)
                until = min(until, st[st_ind].first - 1);
            ll take_1 = min(hours_left, (ll) nd.top().second);
            ii nw(nd.top().first, nd.top().second - (int) take_1);
            nd.pop(); nd.push(nw);
            hours_left -= take_1;
            if(nd.top().second == 0) {
                nd.pop();
                continue;
            }
            if(until == cur_day) {
                cur_day++;
                hours_left = md;
                continue;
            }
            ll take_2 = min(md * (until - cur_day), (ll) nd.top().second);
            cur_day += (take_2 + md - 1) / md;
            hours_left = md - (take_2 % md);
            if(take_2 % md == 0) hours_left = 0;
            ii nw2(nd.top().first, nd.top().second - (int) take_2);
            nd.pop(); nd.push(nw2);
            if(cur_day > nd.top().first) {
                possible = false;
                break;
            }
            if(nd.top().second == 0)
                nd.pop();
        }
        if(!possible) lo = md + 1;
        else hi = md;
    }
    cout << lo << '\n';
}
