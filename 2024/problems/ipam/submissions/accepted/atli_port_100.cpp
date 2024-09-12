#include<bits/stdc++.h>
using namespace std;
typedef __uint128_t ml;


ml parse_ip(string s) {
    stringstream ss;
    ss << s;
    char jnk;
    if(s.find('.') == string::npos) {
        vector<ml> h[2] = { vector<ml>(), vector<ml>() };
        int cur = 0;
        if(ss.peek() == ':') ss >> jnk >> jnk, cur++;
        while(ss) {
            string chunk;
            getline(ss, chunk, ':');
            if(chunk == "") cur++;
            else {
                int x = stoi(chunk, nullptr, 16);
                h[cur].push_back(x);
            }
        }
        while(h[0].size() + h[1].size() != 8) h[0].push_back(0);
        ml res = 0;
        for(int i = 0; i < 2; ++i)
            for(ml x : h[i]) res *= 65536, res += x;
        return res;
    } else {
        ml res = 0;
        for(int i = 0; i < 4; ++i) {
            int x;
            ss >> x;
            res *= 256;
            res += x;
            if(i != 3) ss >> jnk;
        }
        res += 281470681743360LL;
        return res;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    map<string, map<pair<ml, ml>, string>> prop;
    map<string, string> def;
    int q; cin >> q;
    while(q--) {
        char op; cin >> ws >> op;
        if(op == '+') {
            string new_prop, new_def;
            cin >> new_prop >> new_def;
            if(!prop.count(new_prop)) prop[new_prop] = map<pair<ml, ml>, string>();
            def[new_prop] = new_def;
        } else if(op == '-') {
            string del_prop;
            cin >> del_prop;
            prop.erase(del_prop);
            def.erase(del_prop);
        } else if(op == '=') {
            string ipa, ipb, name, value;
            cin >> ipa >> ipb >> name >> value;
            ml a = parse_ip(ipa), b = parse_ip(ipb);
            auto it = prop[name].lower_bound(make_pair(a, 0));
            if(it != prop[name].begin()) {
                it--;
                if(it->first.first < a && it->first.second > b) {
                    string val = it->second;
                    auto key1 = make_pair(it->first.first, a - 1);
                    auto key2 = make_pair(b + 1, it->first.second);
                    prop[name].erase(it);
                    prop[name][key1] = val;
                    prop[name][key2] = val;
                } else if(it->first.first < a && it->first.second >= a) {
                    string val = it->second;
                    auto key = make_pair(it->first.first, a - 1);
                    prop[name].erase(it);
                    prop[name][key] = val;
                }
            }
            it = prop[name].lower_bound(make_pair(b + 1, 0));
            if(it != prop[name].begin()) {
                it--;
                if(it->first.first <= b && it->first.second > b) {
                    string val = it->second;
                    auto key = make_pair(b + 1, it->first.second);
                    prop[name].erase(it);
                    prop[name][key] = val;
                }
            }
            while(true) {
                it = prop[name].lower_bound(make_pair(a, 0));
                if(it != prop[name].end() && it->first.first >= a && it->first.second <= b)
                    prop[name].erase(it);
                else break;
            }
            prop[name][make_pair(a, b)] = value;
        } else {
            cout << prop.size() << '\n';
            string xip; cin >> xip;
            ml x = parse_ip(xip);
            for(auto p : prop) {
                cout << p.first << ' ';
                auto it = p.second.lower_bound(make_pair(x + 1, 0));
                if(it == p.second.begin() || (--it)->first.second < x)
                    cout << def[p.first];
                else cout << it->second;
                cout << '\n';
            }
        }
    }
}
