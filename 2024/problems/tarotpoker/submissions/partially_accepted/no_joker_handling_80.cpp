#include "bits/stdc++.h"

using namespace std;

vector<long long int> ranks[20];

int cnt = 0;
string cards[78];
vector<string> suits = {"S", "B", "V", "M"};

int get_value(int h) {
  if (h < 56) return h / 4;
  else return h;
}

int get_comp_value(int h) {
  if (h < 56) {
    if (h / 4 < 10) return h / 4 + 1;
    else return h / 4 + 20; // to not mix with high cards
  } else return h - 56;
}

int get_suit(int h) {
  if (h < 56) return h % 4;
  else return h;
}

tuple<vector<int>, vector<int>, vector<int>> get_values_and_suits(const vector<int>& h) {
  const auto N = h.size();
  // values
  vector<int> v(N);
  for (size_t i = 0; i < N; ++i) v[i] = get_value(h[i]);
  sort(v.begin(), v.end());

  // comparable values
  vector<pair<int, int>> c_(N);
  for (size_t i = 0; i < N; ++i) c_[i] = {get_value(h[i]), get_comp_value(h[i])};
  sort(c_.begin(), c_.end()); // sort according to value
  vector<int> c(N);
  for (size_t i = 0; i < N; ++i) c[i] = c_[i].second;

  // suits
  vector<int> s(N);
  for (size_t i = 0; i < N; ++i) s[i] = get_suit(h[i]);
  sort(s.begin(), s.end());

  return {v, c, s};
}

int solve2(const vector<int>& h) {
  auto [v, c, s] = get_values_and_suits(h);

  if (v[0] < 10 && v[1] >= 14 && c[0] == c[1]) return 15; // comp pair of low and high
  if (v[0] == v[1]) return 18; // 2 same value
  return 100;
}

int solve3(const vector<int>& h) {
  auto [v, c, s] = get_values_and_suits(h);

  if (v[0] == v[2]) return 16; // 3 same value
  return 100;
}

int solve4(const vector<int>& h) {
  auto [v, c, s] = get_values_and_suits(h);

  if (v[2] < 14 && v[3] >= 14 && c[0] + c[1] + c[2] == c[3]) return 7; // 3 low, 1 high comp to sum of low
  if (v[0] == v[3]) return 9; // 4 same value
  if (v[1] < 10 && v[2] >= 14 && c[0] == c[2] && c[1] == c[3]) return 13; // 2 low (numbers), 2 high, each high comp to corresponding low
  if (v[0] == v[1] && v[2] < 10 && v[3] >= 14 && c[2] == c[3]) return 14; // 2 same value, 1 low (number) comp to remaining high
  if (v[1] == v[2] && v[0] < 10 && v[3] >= 14 && c[0] == c[3]) return 14; //   does not matter which are same value, the combination set is the same
  if (v[2] == v[3] && v[0] < 10 && v[1] >= 14 && c[0] == c[1]) return 14;
  if (v[0] == v[1] && v[2] == v[3]) return 17; // 2 pairs of same values
  return 100;
}

// result and best combination, sorted in descending order
pair<int, vector<int>> solve5(const vector<int>& h) {
  auto [v, c, s] = get_values_and_suits(h);

  // solve subsets of 2 (for case 18)
  pair<int, vector<int>> result2 = {100, {}};
  for (int i = 0; i < 4; ++i) {
    for (int j = i + 1; j < 5; ++j) {
      vector<int> subh = {h[i], h[j]};
      auto result = solve2(subh);
      if (result < result2.first) { // subh are in decreasing order, so only strictly better result
        result2 = {result, subh};
      }
    }
  }
  // solve subsets of 3 (for case 16)
  pair<int, vector<int>> result3 = {100, {}};
  for (int i = 3; i >= 0; i--) {
    for (int j = 4; j > i; j--) {
      vector<int> subh = h; subh.erase(subh.begin() + j); subh.erase(subh.begin() + i); // erase order!
      auto result = solve3(subh);
      if (result != 100) { // subh are in decreasing order, only 1 possible result
        result3 = {result, subh}; break;
      }
    }
    if (result3.first != 100) break;
  }
  // solve subsets of 4 (for cases 7, 9, 13, 14, 17)
  pair<int, vector<int>> result4 = {100, {}};
  for (int i = 4; i >= 0; i--) {
    vector<int> subh = h; subh.erase(subh.begin() + i);
    auto result = solve4(subh);
    if (result < result4.first) { // subh are in decreasing order, so only strictly better result
      result4 = {result, subh};
    }
  }

  if (v[0] == v[4]) return {1, h}; // 5 same value
  if (v[0] >= 14) return {2, h}; // 5 high cards
  if (v[4] < 14 && s[0] == s[4] && v[0] + 1 == v[1] && v[1] + 1 == v[2] && v[2] + 1 == v[3] && v[3] + 1 == v[4]) return {3, h}; // 5 (low) same suit, sequential
  if (v[3] < 14 && v[4] >= 14 && s[0] != s[1] && s[1] != s[2] && s[2] != s[3] && s[3] != s[4]) return {4, h}; // 4 low, 1 high, all(!) different suits
  if (v[3] < 14 && v[4] >= 14 && c[0] + c[1] + c[2] + c[3] == c[4]) return {5, h}; // 4 low, 1 high, sum of low compares to high
  if (v[3] < 14 && v[4] >= 14 && c[0] == c[4] && c[0] == c[3]) return {6, h}; // 4 low, 1 high, each low compares to high
  if (result4.first == 7) return result4;
  if (v[0] >= 10 && v[4] < 14) return {8, h}; // 5 low, no numbers
  if (result4.first == 9) return result4;
  if ((v[0] == v[2] && v[3] == v[4]) || (v[0] == v[1] && v[2] == v[4])) return {10, h}; // 3+2 or 2+3 same value
  if (v[4] < 14 && s[0] == s[4]) return {11, h}; // 5 (low), same suit
  if (v[0] + 1 == v[1] && v[1] + 1 == v[2] && v[2] + 1 == v[3] && v[3] + 1 == v[4]) return {12, h}; // 5 sequential
  if (result4.first == 13) return result4;
  if (result4.first == 14) return result4;
  if (result2.first == 15) return result2;
  if (result3.first == 16) return result3;
  if (result4.first == 17) return result4;
  if (result2.first == 18) return result2; // 2 same value
  if (v[4] < 14) return {19, h}; // 5 low cards
  return {20, {h[0]}}; // highest card
}

pair<int, vector<int>> solve(vector<int> h) {
  auto result = solve5(h);
  // remove winning combination from the hand
  for (int i = 0; i < result.second.size(); ++i) {
    for (int j = 0; j < h.size(); ++j) {
      if (h[j] == result.second[i]) {
        h.erase(h.begin() + j); break;
      }
    }
  }
  // augment winning combination with the remaining cards for tiebreak
  for (auto x : h) result.second.push_back(x);
  return result;
}

vector<int> get_hand(vector<string> s) {
  vector<int> h(5);
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < cnt; ++j) if (cards[j] == s[i]) h[i] = j;
  sort(h.begin(), h.end(), std::greater<int>());
  return h;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 1; i <= 10; ++i)
    for (auto suit : suits) cards[cnt++] = suit + to_string(i);
  for (auto court : {"G", "R", "D", "K"})
    for (auto suit : suits) cards[cnt++] = suit + court;
  cards[cnt++] = "O";
  cards[cnt++] = "I";
  cards[cnt++] = "II";
  cards[cnt++] = "III";
  cards[cnt++] = "IV";
  cards[cnt++] = "V";
  cards[cnt++] = "VI";
  cards[cnt++] = "VII";
  cards[cnt++] = "VIII";
  cards[cnt++] = "IX";
  cards[cnt++] = "X";
  cards[cnt++] = "XI";
  cards[cnt++] = "XII";
  cards[cnt++] = "XIII";
  cards[cnt++] = "XIV";
  cards[cnt++] = "XV";
  cards[cnt++] = "XVI";
  cards[cnt++] = "XVII";
  cards[cnt++] = "XVIII";
  cards[cnt++] = "XIX";
  cards[cnt++] = "XX";
  cards[cnt++] = "XXI";

  vector<string> konrads(5);
  for (int i = 0; i < 5; ++i) cin >> konrads[i];
  auto konradh = get_hand(konrads);
  vector<string> atlis(5);
  for (int i = 0; i < 5; ++i) cin >> atlis[i];
  auto atlih = get_hand(atlis);

  auto konrad = solve(konradh);
  auto atli = solve(atlih);
  cout << konrad.first << ' ' << atli.first << endl;
  // order scores same as winning combinations
  konrad.first = -konrad.first;
  atli.first = -atli.first;
  if (konrad > atli)
    cout << "Konrad" << endl;
  if (konrad < atli)
    cout << "Atli" << endl;
  if (konrad == atli)
    cout << "Jafntefli" << endl;
  return 0;
}
