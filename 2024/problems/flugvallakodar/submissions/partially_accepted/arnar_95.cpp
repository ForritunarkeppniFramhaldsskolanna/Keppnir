#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr char to_upper(char c) {
    return 'a' <= c && c <= 'z' ? (c & 0b11011111) : c;
}

constexpr size_t ind(char c) {
    return c - 'A';
}

constexpr size_t ind(char a, char b) {
    return 26*ind(a) + ind(b);
}

constexpr size_t ind(char a, char b, char c) {
    return 26*26*ind(a) + 26*ind(b) + ind(c);
}

bitset<26> used[26*26];

void process(const string_view s) {
    if (s.size() < 3) cout << ":(\n";
    vector<bitset<26>> masks(s.size()+1);
    for (size_t i = s.size(); i > 0ULL; i--) {
        masks[i-1] = masks[i];
        masks[i-1].set(ind(s[i-1]));
    }
    for (size_t i1 = 0; i1 + 2 < s.size(); i1++) {
        for (size_t i2 = i1+1; i2 + 1 < s.size(); i2++) {
            const auto ab{ ind(s[i1], s[i2]) };
            auto check{ masks[i2+1] };
            if ((~used[ab] & check).none()) continue;
            for (size_t i3 = i2+1; i3 < s.size(); i3++) {
                const auto c{ ind(s[i3]) };
                if (!used[ab][c]) {
                    cout << s[i1] << s[i2] << s[i3] << "\n";
                    used[ab][c] = true;
                    return;
                }
            }
        }
    }
    cout << ":(\n";
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), to_upper);
        process(s);
    }
}
