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
  cerr << "Current state:\n"; out(current, cerr);
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
}

inline bool try_win_in_one_move() {
  auto move = get_a_winning_move(current, true, cnt_x, cnt_X); // already have xx in a row
  if (!move.empty()) { go(move); return true; }
  return false;
}

int main() {
  go("....x....");
  if (cnt(current, 'O')) { // response is O
    if (cnt(current, 'x')) { // x was not replaced - so replace it
      auto s = current; s[4] = 'X'; go(s);
    } else { // O replaced x - put X to the corner
      go("X...O....");
    }
  } else { // response is o
    if (current[0] == 'o') go("oX..x...."); else
    if (current[2] == 'o') go(".Xo.x...."); else
    if (current[6] == 'o') go("....x.oX."); else
    if (current[8] == 'o') go("....x..Xo"); else
    if (current[1] == 'o') go(".o.Xx...."); else
    if (current[3] == 'o') go(".X.ox...."); else
    if (current[5] == 'o') go(".X..xo..."); else
    if (current[7] == 'o') go("...Xx..o.");
    if (cnt(current, 'O')) { // response is O
      if (current[4] == 'O') { // O replaced x - then replace o with X
        auto s = current; s[s.find('o')] = 'X'; go(s);
      } else {
        if (try_win_in_one_move()) return 0; else { // O blocked our Xx. - put second X adjacent in the corner
          auto s = current;
          if (s[1] == 'X' || s[3] == 'X') s[0] = 'X'; else
          if (s[7] == 'X') s[8] = 'X';
          go(s);
          assert(try_win_in_one_move());
          return 0;
        }
      }
    } else { // response is o
      assert(try_win_in_one_move());
      return 0;
    }
  }

  // we had one X and one O, and got a reply
  while (cnt(current, 'o')) { // reply was o -- move our X to replace it
    auto s = current; if (current == "Sigur!") return 0;
    s[s.find('X')] = '.';
    s[s.find('o')] = 'X';
    go(s);
  }

  if (current == "Sigur!") return 0;

  // we have one X and two O - reply with another X (block if Os are on a line)
  for (auto move : get_moves(current, true, 0, 1)) if (get_a_winning_move(move, false, 1, 0).empty()) {
    go(move);
    break;
  }

  while (current != "Sigur!") { // we got two X, two O, and one o - replace it with one of X
    for (auto move : get_moves(current, true, 0, 0)) if (get_a_winning_move(move, false, 1, 0).empty()) {
      go(move);
      break;
    }
  }

  return 0;
}
