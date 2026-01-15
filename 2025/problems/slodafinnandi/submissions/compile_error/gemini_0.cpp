#include <iostream>
#include <set>

using namespace std;

int main() {
  long long n;
  cin >> n;

  set<pair<long long, long long>> reachable_tiles;
  reachable_tiles.insert({0, 0});

  set<tuple<long long, long long, long long, bool>> q; // {x, y, remaining_movement, last_move_diagonal}
  q.insert({0, 0, n, false});

  while (!q.empty()) {
    auto current = *q.begin();
    q.erase(q.begin());

    long long x = get(current);
    long long y = get(current);
    long long remaining_movement = get(current);
    bool last_move_diagonal = get(current);

    // Move up
    if (remaining_movement >= 5) {
      if (reachable_tiles.find({x, y + 1}) == reachable_tiles.end()) {
        reachable_tiles.insert({x, y + 1});
        q.insert({x, y + 1, remaining_movement - 5, false});
      }
    }

    // Move down
    if (remaining_movement >= 5) {
      if (reachable_tiles.find({x, y - 1}) == reachable_tiles.end()) {
        reachable_tiles.insert({x, y - 1});
        q.insert({x, y - 1, remaining_movement - 5, false});
      }
    }

    // Move left
    if (remaining_movement >= 5) {
      if (reachable_tiles.find({x - 1, y}) == reachable_tiles.end()) {
        reachable_tiles.insert({x - 1, y});
        q.insert({x - 1, y, remaining_movement - 5, false});
      }
    }

    // Move right
    if (remaining_movement >= 5) {
      if (reachable_tiles.find({x + 1, y}) == reachable_tiles.end()) {
        reachable_tiles.insert({x + 1, y});
        q.insert({x + 1, y, remaining_movement - 5, false});
      }
    }

    // Move diagonally
    long long diagonal_cost = (last_move_diagonal ? 10 : 5);
    if (remaining_movement >= diagonal_cost) {
      // Up-right
      if (reachable_tiles.find({x + 1, y + 1}) == reachable_tiles.end()) {
        reachable_tiles.insert({x + 1, y + 1});
        q.insert({x + 1, y + 1, remaining_movement - diagonal_cost, !last_move_diagonal});
      }
      // Up-left
      if (reachable_tiles.find({x - 1, y + 1}) == reachable_tiles.end()) {
        reachable_tiles.insert({x - 1, y + 1});
        q.insert({x - 1, y + 1, remaining_movement - diagonal_cost, !last_move_diagonal});
      }
      // Down-right
      if (reachable_tiles.find({x + 1, y - 1}) == reachable_tiles.end()) {
        reachable_tiles.insert({x + 1, y - 1});
        q.insert({x + 1, y - 1, remaining_movement - diagonal_cost, !last_move_diagonal});
      }
      // Down-left
      if (reachable_tiles.find({x - 1, y - 1}) == reachable_tiles.end()) {
        reachable_tiles.insert({x - 1, y - 1});
        q.insert({x - 1, y - 1, remaining_movement - diagonal_cost, !last_move_diagonal});
      }
    }
  }

  cout << reachable_tiles.size() << endl;

  return 0;
}
