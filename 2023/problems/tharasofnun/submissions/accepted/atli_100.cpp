#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

template<typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

unordered_map<ll,set<ll>> rows, cols, diag, anti;

void add_point(ll x, ll y) {
    if(!rows.count(y)) rows[y] = set<ll>();
    if(!cols.count(x)) cols[x] = set<ll>();
    if(!diag.count(x - y)) diag[x - y] = set<ll>();
    if(!anti.count(x + y)) anti[x + y] = set<ll>();
    rows[y].insert(x);
    cols[x].insert(y);
    diag[x - y].insert(x + y);
    anti[x + y].insert(x - y);
}

void rem_point(ll x, ll y) {
    rows[y].erase(x);
    cols[x].erase(y);
    diag[x - y].erase(x + y);
    anti[x + y].erase(x - y);
    if(rows[y].empty()) rows.erase(y);
    if(cols[x].empty()) cols.erase(x);
    if(diag[x - y].empty()) diag.erase(x - y);
    if(anti[x + y].empty()) anti.erase(x + y);
}

pair<ll,ll> target(ll posx, ll posy, ll goalx, ll goaly) {
    if(posx == goalx || posy == goaly) return make_pair(goalx, goaly);
    ll mov = min(abs(posx - goalx), abs(posy - goaly));
    return make_pair(posx + sgn(goalx - posx) * mov, posy + sgn(goaly - posy) * mov);
}

ll dist(ll posx, ll posy, ll goalx, ll goaly) {
    return max(abs(posx - goalx), abs(posy - goaly));
}

bool sweeps(ll px, ll py, ll qx, ll qy, ll tx, ll ty, ll dt) {
    ll sgnx = sgn(tx - px), sgny = sgn(ty - py);
    ll mov = max(abs(px - tx), abs(py - ty));
    ll mov2 = max(abs(px - qx), abs(py - qy));
    if(mov2 > mov) return false;
    if(mov2 < dt) return false;
    if(qx != px + sgnx * mov2) return false;
    if(qy != py + sgny * mov2) return false;
    return true;
}

int main() {
    rows.max_load_factor(0.5);
    cols.max_load_factor(0.5);
    diag.max_load_factor(0.5);
    anti.max_load_factor(0.5);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r, c, q, t, x, y;
    cin >> c >> r >> q;
    vvl inp(q, vl(3));
    for(int i = 0; i < q; ++i)
        cin >> inp[i][0] >> inp[i][1] >> inp[i][2];
    reverse(inp.begin(), inp.end());
    queue<vl> todo;
    ll time = 0, posx = 0, posy = 0;
    while(inp.size() > 0 || todo.size() > 0) {
        vvl outp;
        while(!todo.empty() && !cols[todo.front()[1]].count(todo.front()[2])) todo.pop();
        if(todo.empty() && inp.empty()) continue;
        if(todo.empty() && time < inp.back()[0]) {
            time = inp.back()[0];
        }
        while(inp.size() > 0 && time >= inp.back()[0]) {
            todo.push(inp.back());
            add_point(inp.back()[1], inp.back()[2]);
            inp.pop_back();
        }
        auto targ = target(posx, posy, todo.front()[1], todo.front()[2]);
        if(targ == make_pair(posx, posy)) {
            outp.push_back(todo.front());
            todo.pop();
        } else {
            ll sgnx = sgn(targ.first - posx), sgny = sgn(targ.second - posy), key, lo, hi;
            unordered_map<ll,set<ll>>* search_in = nullptr;
            if(sgnx == 0) search_in = &cols, key = posx;
            else if(sgny == 0) search_in = &rows, key = posy;
            else if(sgnx == sgny) search_in = &diag, key = posx - posy;
            else search_in = &anti, key = posx + posy;
            if(sgnx == 0 && sgny > 0) lo = posy, hi = targ.second;
            else if(sgnx == 0 && sgny < 0) lo = targ.second, hi = posy;
            else if(sgny == 0 && sgnx > 0) lo = posx, hi = targ.first;
            else if(sgny == 0 && sgnx < 0) lo = targ.first, hi = posx;
            else if(sgnx == sgny && sgnx > 0) lo = posx + posy, hi = targ.first + targ.second;
            else if(sgnx == sgny && sgnx < 0) lo = targ.first + targ.second, hi = posx + posy;
            else if(sgnx != sgny && sgnx > 0) lo = posx - posy, hi = targ.first - targ.second;
            else if(sgnx != sgny && sgnx < 0) lo = targ.first - targ.second, hi = posx - posy;
            assert(lo <= hi);
            if(search_in->count(key)) {
                auto it = search_in->at(key).lower_bound(lo);
                while(it != search_in->at(key).end() && *it <= hi) {
                    ll curx = key, cury = *it;
                    if(sgny == 0) swap(curx, cury);
                    if(sgnx != 0 && sgny != 0 && sgnx != sgny) { curx += cury; curx /= 2; cury = curx - cury; }
                    if(sgnx != 0 && sgny != 0 && sgnx == sgny) { curx += cury; curx /= 2; cury = cury - curx; }
                    ll dt = dist(posx, posy, curx, cury);
                    outp.push_back(vl({time + dt, curx, cury}));
                    it++;
                }
            }
            ll timestep = max(abs(posx - targ.first), abs(posy - targ.second));
            while(inp.size() > 0 && time + timestep >= inp.back()[0]) {
                if(sweeps(posx, posy, inp.back()[1], inp.back()[2], targ.first, targ.second, inp.back()[0] - time)) {
                    inp.back()[0] = time + dist(posx, posy, inp.back()[1], inp.back()[2]);
                    outp.push_back(inp.back());
                    inp.pop_back();
                } else {
                    todo.push(inp.back());
                    add_point(inp.back()[1], inp.back()[2]);
                    inp.pop_back();
                }
            }
            posx = targ.first; posy = targ.second; time += timestep;
        }
        sort(outp.begin(), outp.end());
        for(vl v : outp) {
            rem_point(v[1], v[2]);
            cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
        }
    }
}
