#include "bits/stdc++.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s1, s2;
  cin >> s1 >> s2;

  if (s2 == "0.0") {
    cout << "Veit ekki" << endl;
    return 0;
  }

  assert(s1 != "0.0"); // 0 cannot be rounded or truncated to non-0

  // check for no leading zeroes
  assert(s1[0] != '0' || s1[1] == '.');
  assert(s2[0] != '0' || s2[1] == '.');

  int exp1 = s1.find('.');
  int exp2 = s2.find('.');
  int last = s2.size() - 1;
  for (; s2[last] == '.' || s2[last] == '0'; last--);

  if (last < exp2) {
    last = exp2 - 1 - last; // non-negative powers
  } else {
    last = exp2 - last; // negative powers
  }

  // s1 is either truncated or rounded to 10^last
  bool can_trunc = false;
  bool can_round = false;

  // try truncate
  string t = s1;
  if (last < 0) {
    t.resize(exp1 + 1 - last);
  } else {
    if (exp1 > last) {
      t.resize(exp1 - last);
      // add zeroes
      for (int i = 0; i < last; ++i) t.push_back('0');
      t += ".0";
    } else // we trucate more than we have, producing 0 (which is already ruled out)
      t = "0.0";
  }
  if (t == s2) can_trunc = true;

  // try round
  string r = s1;
  if (last < 0) {
    if (exp1 - last != s1.size()) {
      if (s1[exp1 + 1 - last] < '5') {
        // same as truncate
        r = t;
      } else {
        r.resize(exp1 + 1 - last);
        int cur = exp1 - last;
        while (cur >= 0) {
          if (r[cur] == '.') { cur--; continue; }
          if (r[cur] == '9') {
            r[cur] = '0';
            cur--;
          } else {
            r[cur]++;
            break;
          }
        }
        if (cur < 0) {
          r = "1" + r;
        }
      }
    } else { /* already at the last digit, nothing to round */ }
  } else {
    int cur = exp1 - last - 1;
    assert(cur >= -1); // rounding cannot add more than one digit
    if (cur <= 0) {
      r = "0" + r;
      exp1++;
      cur++;
    }
    char next = r[cur + 1] == '.' ? r[cur + 2] : r[cur + 1];
    if (next >= '5') {
      while (cur >= 0) {
        if (r[cur] == '9') {
          r[cur] = '0';
          cur--;
        } else {
          r[cur]++;
          break;
        }
      }
    }
    r.resize(exp1 - last);
    assert(cur >= 0); // wtf
    if (r[0] == '0') r = r.substr(1);

    // add zeroes
    for (int i = 0; i < last; ++i) r.push_back('0');
    r += ".0";
  }

  if (r == s2) can_round = true;

  assert(can_round || can_trunc);

  if (can_round)
    if (can_trunc)
      cout << "Veit ekki" << endl;
    else
      cout << "Runnun" << endl;
  else
    cout << "Styfun" << endl;

  return 0;
}
