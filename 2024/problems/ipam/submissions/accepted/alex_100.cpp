#include "bits/stdc++.h"

using namespace std;

using i128 = unsigned __int128;

string to_string_hex(int n) {
  std::stringstream stream;
  stream << std::hex << n;
  auto result = stream.str();
  return result;
}

int from_string_hex(string s) {
  int n;
  std::stringstream stream;
  stream << s;
  stream >> std::hex >> n;
  return n;
}

string inttostr(i128 n) {
  string r;
  for (int i = 0; i < 39; ++i) {
    r.push_back('0' + n % 10);
    n /= 10;
  }
  reverse(r.begin(), r.end());
  return r;
}

i128 iptoint(string s) {
  if (s.find('.') != string::npos) {
    int p1 = s.find('.');
    int p2 = s.find('.', p1 + 1);
    int p3 = s.find('.', p2 + 1);
    int a = stoi(s.substr(0, p1)) << 8 | stoi(s.substr(p1 + 1, p2));
    int b = stoi(s.substr(p2 + 1, p3)) << 8 | stoi(s.substr(p3 + 1));
    return iptoint("::ffff:" + to_string_hex(a) + ":" + to_string_hex(b));
  }

  if (s.find("::") != string::npos) {
    int blocks = 0;
    for (int i = 0; i < s.size(); ++i) if (s[i] != ':') {
      if (i == s.size() - 1 || s[i + 1] == ':') blocks++;
    }
    int p = s.find("::");
    string zeroes = ":";
    for (int i = 0; i < 8 - blocks; ++i) zeroes += "0:";
    s = s.substr(0, p) + zeroes + s.substr(p + 2);
    if (s.back() == ':') s.pop_back();
    if (s[0] == ':') s.erase(0, 1);
    return iptoint(s);
  }

  i128 result = (i128)0;
  for (int i = 0; i < 8; ++i) {
    int n = from_string_hex(s.substr(0, s.find(':')));
    result <<= 16;
    result |= n;
    s = s.substr(s.find(':') + 1);
  }
  return result;
}

struct Node {
  map<string, pair<string, int>> vals;
};

Node tr[1000000];
int tid = 0;

void add(int n, int L, int R, int l, int r, const string& k, const string& v) {
  if (L == l && R == r) {
    tr[n].vals[k] = make_pair(v, tid);
  } else {
    if (l <= (L + R) >> 1) {
      add(n << 1, L, (L + R) >> 1, l, min(r, (L + R) >> 1), k, v);
    }
    if (r > (L + R) >> 1) {
      add(n << 1 | 1, ((L + R) >> 1) + 1, R, max(((L + R) >> 1) + 1, l), r, k, v);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  map<string, pair<string, int>> defaults;

  vector<vector<string>> inp;

  set<string> ips;

  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    char c; cin >> c;
    vector<string> entry(1);
    entry[0].push_back(c);
    if (c == '+') {
      string k; string v;
      cin >> k >> v;
      entry.push_back(k);
      entry.push_back(v);
    } else if (c == '-') {
      string k; cin >> k;
      entry.push_back(k);
    } else if (c == '=') {
      string ip1, ip2, k, v;
      cin >> ip1 >> ip2 >> k >> v;
      ip1 = inttostr(iptoint(ip1));
      ip2 = inttostr(iptoint(ip2));
      ips.insert(ip1);
      ips.insert(ip2);
      entry.push_back(ip1);
      entry.push_back(ip2);
      entry.push_back(k);
      entry.push_back(v);
    } else {
      string ip; cin >> ip;
      ip = inttostr(iptoint(ip));
      ips.insert(ip);
      entry.push_back(ip);
    }
    inp.push_back(entry);
  }

  unordered_map<string, int> ip_to_id;
  vector<string> id_to_ip(ips.size());
  int cnt = 0;
  for (auto x : ips) {
    id_to_ip[cnt] = x;
    ip_to_id[x] = cnt;
    cnt++;
  }

  int maxn = 1;
  while (maxn < cnt) maxn <<= 1;

  int anscnt = 0;

  for (int i = 0; i < n; ++i) {
    auto& entry = inp[i];
    char c = entry[0][0];
    tid++;
    if (c == '+') {
      string k = entry[1];
      string v = entry[2];
      if (defaults.find(k) == defaults.end())
        defaults[k] = {v, tid};
      else
        defaults[k].first = v;
    } else if (c == '-') {
      string k = entry[1];
      defaults.erase(k);
    } else if (c == '=') {
      string ip1 = entry[1];
      string ip2 = entry[2];
      string k = entry[3];
      string v = entry[4];
      add(1, 0, maxn - 1, ip_to_id[ip1], ip_to_id[ip2], k, v);
    } else {
      string ip = entry[1];
      int id = ip_to_id[ip];
      map<string, pair<string, int>> result = defaults;
      int cur = 1;
      int l = 0;
      int r = maxn - 1;
      while (true) {
        for (auto& [k, v] : tr[cur].vals) {
          if (defaults.find(k) != defaults.end()) {
            if (v.second > result[k].second) result[k] = v;
          }
        }
        if (l == r) break;
        if (id > (l + r) >> 1) {
          cur = cur << 1 | 1;
          l = ((l + r) >> 1) + 1;
        } else {
          cur = cur << 1;
          r = (l + r) >> 1;
        }
      }
      cout << result.size() << endl;
      anscnt++;
      for (auto& [k, v] : result) {
        cout << k << ' ' << v.first << endl;
        anscnt++;
      }
    }
  }

  return 0;
}
