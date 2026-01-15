#include <cassert>
#include <cstdint>
#include <iostream>
#include <list>
#include <vector>

using int_t = std::int64_t;

struct soviet_union_find_t {
    mutable std::vector<int_t> parent;
    std::vector<std::list<int_t>> members;
    soviet_union_find_t(int_t n) : parent(n, -1), members(n) {
        for (int_t i = 0; i < n; i++) {
            members[i].insert(members[i].end(), i);
        }
    }

    int_t find(int_t x) const {
        return parent[x] < 0 ? x : parent[x] = find(parent[x]);
    }

    bool unite(const int_t x, const int_t y) {
        const int_t xp{ find(x) };
        const int_t yp{ find(y) };
        if (xp == yp) return false;
        parent[xp] += parent[yp];
        parent[yp] = xp;
        members[xp].splice(members[xp].end(), members[yp]);
        return true;
    }

    void balkanize(const int_t x) {
        const int_t xp{ find(x) };
        for (int_t i : members[xp]) {
            if (i != xp) {
                members[i].insert(members[i].end(), i);
                parent[i] = -1;
            }
        }
        members[xp].clear();
        members[xp].insert(members[xp].end(), xp);
        parent[xp] = -1;
    }
};

int main() {
    int_t n, q;
    std::cin >> n >> q;
    soviet_union_find_t suf(n);

    for (int_t i = 0; i < q; i++) {
        char op;
        std::cin >> std::ws >> op;
        switch (op) {
            case 'a': {
                int_t x, y;
                std::cin >> x >> y;
                x--, y--;
                suf.unite(x, y);
                break;
            }
            case 'b': {
                int_t x;
                std::cin >> x;
                x--;
                suf.balkanize(x);
                break;
            }
            case 'c': {
                int_t x;
                std::cin >> x;
                x--;
                std::cout << suf.find(x) + 1 << '\n';
                break;
            }
            default:
                assert(false);
        }
    }
}
