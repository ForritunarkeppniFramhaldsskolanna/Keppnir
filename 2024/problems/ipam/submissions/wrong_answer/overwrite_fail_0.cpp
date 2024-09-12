#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> i3;

int parse_ip(string s) {
    stringstream ss;
    ss << s;
    int res = 0;
    int x; char jnk;
    ss >> x >> jnk;
    for(int i = 0; i < 3; ++i) {
        res *= 256;
        ss >> x;
        res += x;
        if(i != 2) ss >> jnk;
    }
    return res;
}

const int TOT = 256 * 256 * 256;
const int BSZ = 1024;
const int BCNT = TOT / BSZ;

int main() {
    map<int,vector<int>> manual;
    vector<int> buckets[BCNT];
    for(int i = 0; i < BCNT; ++i) buckets[i] = vector<int>();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    map<string,int> s2int, o2int;
    vector<string> int2s, int2o;
    set<int> props;
    vector<int> defs;
    int q, cnt = 0, cnt2 = 0; 
    cin >> q;
    for(int i = 0; i < q; ++i) {
        char op; cin >> ws >> op;
        if(op == '+') {
            string k, v;
            cin >> k >> v;
            if(!s2int.count(k)) s2int[k] = cnt++, int2s.push_back(k), defs.push_back(0);
            if(!o2int.count(v)) o2int[v] = cnt2++, int2o.push_back(v);
            props.insert(s2int[k]);
            defs[s2int[k]] = o2int[v];
        } else if(op == '-') {
            string k; cin >> k;
            props.erase(s2int[k]);
        } else if(op == '=') {
            string aip, bip, k, v;
            cin >> aip >> bip >> k >> v;
            if(!o2int.count(v)) o2int[v] = cnt2++, int2o.push_back(v);
            int ind = s2int[k];
            int val = o2int[v];
            int a = parse_ip(aip), b = parse_ip(bip);
            while(a <= b && a % BSZ != 0) {
                if(!manual.count(a)) manual[a] = vector<int>();
                if(2 * ind + 1 >= manual[a].size()) manual[a].resize(2 * ind + 2, -1);
                manual[a][2 * ind] = val;
                manual[a][2 * ind + 1] = i;
                a++;
            }
            while(a <= b && b % BSZ != 0) {
                if(!manual.count(b)) manual[b] = vector<int>();
                if(2 * ind + 1 >= manual[b].size()) manual[b].resize(2 * ind + 2, -1);
                manual[b][2 * ind] = val;
                manual[b][2 * ind + 1] = i;
                b--;
            }
            a /= BSZ;
            b /= BSZ;
            if(a < b) {
                for(int j = a; j < b; ++j) {
                    if(2 * ind + 1 >= buckets[j].size())
                        buckets[j].resize(2 * ind + 2, -1);
                    buckets[j][2 * ind] = val;
                    buckets[j][2 * ind + 1] = i;
                }
            }
        } else {
            string xip; cin >> xip;
            int x = parse_ip(xip);
            vector<pair<string,string>> outp;
            for(int y : props) {
                int t1 = -1, v1 = -1;
                if(manual.count(x))
                    if(manual[x].size() >= 2 * y + 2)
                        v1 = manual[x][2 * y], t1 = manual[x][2 * y + 1];
                int t2 = -1, v2 = -1, b_ind = x / BSZ;
                if(buckets[b_ind].size() >= 2 * y + 2)
                    v2 = buckets[b_ind][2 * y], t2 = buckets[b_ind][2 * y + 1];
                if(t1 == -1 && t2 == -1) outp.push_back(make_pair(int2s[y], int2o[defs[y]]));
                else if(t2 > t1) outp.push_back(make_pair(int2s[y], int2o[v2]));
                else outp.push_back(make_pair(int2s[y], int2o[v1]));
            }
            sort(outp.begin(), outp.end());
            cout << outp.size() << '\n';
            for(auto p : outp) cout << p.first << ' ' << p.second << '\n';
        }
    }
}
