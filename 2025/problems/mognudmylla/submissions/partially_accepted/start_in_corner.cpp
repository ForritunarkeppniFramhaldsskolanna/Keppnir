#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

using lli = long long int;

vector<string> get_moves(const string &s, bool x_to_move, int lower_cnt, int upper_cnt) {
  char lower = x_to_move ? 'x' : 'o';
  char upper = lower - 'a' + 'A';
  vector<string> moves;
  for (int i = 0; i < 9; ++i) if (s[i] == '.') {
    if (lower_cnt) { auto move = s; move[i] = lower; moves.push_back(move); }
    if (upper_cnt) { auto move = s; move[i] = upper; moves.push_back(move); }
  } else if (s[i] > 'a') {
    if (upper_cnt) { auto move = s; move[i] = upper; moves.push_back(move); }
    for (int j = 0; j < 9; ++j) if (s[j] == upper)
      { auto move = s; move[i] = upper; move[j] = '.'; moves.push_back(move); }
  }
  return moves;
}

bool has_player_won(const string &s, bool player_is_x) {
  char lower = player_is_x ? 'x' : 'o';
  char upper = lower - 'a' + 'A';
  vector<vector<int>> lines = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
  for (auto& line : lines) {
    if (all_of(line.begin(), line.end(), [&](int pos) { return (s[pos] == lower) || (s[pos] == upper); })) return true;
  }
  return false;
}

string get_a_winning_move(const string &s, bool player_is_x, int lower_cnt, int upper_cnt) {
  auto moves = get_moves(s, player_is_x, lower_cnt, upper_cnt);
  for (auto& result : moves) if (has_player_won(result, player_is_x)) return result;
  return "";
}

inline int cnt(const string& s, char c) { return count(s.begin(), s.end(), c); }

int cnt_x = 4;
int cnt_X = 2;
int cnt_o = 4;
int cnt_O = 2;
string current = ".........";

inline void out(string& s, ostream& stream) {
  stream << s.substr(0, 3) << endl << s.substr(3, 3) << endl << s.substr(6, 3) << endl; stream.flush();
}

inline void go(string s) {
  cerr << "My move:\n"; out(s, cerr);
  out(s, cout);
  if (cnt(s, 'x') > cnt(current, 'x')) cnt_x--;
  if (cnt(s, 'X') > cnt(current, 'X')) cnt_X--;
  string s1, s2, s3; cin >> s1; if (s1 == "Sigur!") { current = "Sigur!"; return; }
  assert(s1 != "Tap!");
  cin >> s2 >> s3;
  current = s1 + s2 + s3;
  if (cnt(current, 'o') > cnt(s, 'o')) cnt_o--;
  if (cnt(current, 'O') > cnt(s, 'O')) cnt_O--;
  cerr << "Got reply:\n"; out(current, cerr);
}

inline bool try_win_in_one_move() {
  auto move = get_a_winning_move(current, true, cnt_x, cnt_X); // already have xx in a row
  if (!move.empty()) { go(move); return true; }
  return false;
}

int main() {
  go("x........");
  if (cnt(current, 'O')) { // response is O
    if (cnt(current, 'x')) { // x was not replaced - so replace it
      auto s = current; s[0] = 'X'; go(s);
    } else { // O replaced x - put X in the corner
      go("O...X....");
    }
  } else { // response is o - respond with x
    auto s = current;
    if (current[3] == '.' && current[6] == '.') s[3] = 'x'; else s[1] = 'x';
    go(s);
    if (cnt(current, 'O')) { // response is O
      if (cnt(current, 'x') != 2) { // O replaced x - add X somewhere so that O doesn't win immediately
        bool found_move = false;
        for (int i = 0; i < 9; ++i) if (current[i] == '.') {
          s = current; s[i] = 'X';
          if (get_a_winning_move(s, false, 1, 1).empty()) {
            go(s); found_move = true; break;
          }
        }
        assert(found_move);
      } else { // O was added - replace o with X
        if (try_win_in_one_move()) return 0; else { // O blocked our xx. - replace o with X
          auto s = current;
          for (int i = 0; i < 9; ++i) if (s[i] == 'o') s[i] = 'X';
          go(s);
        }
      }
    } else { // response is o
      assert(try_win_in_one_move());
      return 0;
    }
  }

  if (current == "Sigur!") return 0;

  if (try_win_in_one_move()) {
    return 0;
  }

  // we have one X and at least one O
  while (cnt(current, 'O') < 2) { // keep parity of small letters until we get a second O
    assert((cnt(current, 'x') + cnt(current, 'o')) & 1);
    bool found_move = false;
    for (auto move : get_moves(current, true, 0, 0)) if (get_a_winning_move(move, false, 1, 1).empty()) {
      go(move);
      found_move = true;
      break;
    }
    assert(found_move);
  }

  // we have one X and two O, and possibly some small letter
  while ((current != "Sigur!") && !try_win_in_one_move()) {
    auto s = current;
    if ((cnt(current, 'x') + cnt(current, 'o')) & 1) { // keep parity by replacing a small letter with X, without blundering
      for (int i = 0; i < 9; ++i) if (s[i] == 'o') {
        s[i] = 'X';
        if (get_a_winning_move(s, false, 1, 0).empty()) break;
        s[i] = 'o'; // restore, try again
      }
      if (s == current) // could not replace o, try replacing x
        for (int i = 0; i < 9; ++i) if (s[i] == 'x') {
          s[i] = 'X';
          if (get_a_winning_move(s, false, 1, 0).empty()) break;
          s[i] = 'x'; // restore, try again
        }
      assert(s != current);
      go(s);
    } else { // add X without blundering
      for (int i = 0; i < 9; ++i) if (s[i] == '.') {
        s[i] = 'X';
        if (get_a_winning_move(s, false, 1, 0).empty()) break;
        s[i] = '.'; // restore, try again
      }
      assert(s != current);
      go(s);
    }
  }

  return 0;
}
