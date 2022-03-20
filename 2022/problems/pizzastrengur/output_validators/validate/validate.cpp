#include "validate.h"
#include <algorithm>
#include <climits>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct Trie {

    struct Node {
        map<char, Node *> children;
        Node *parent = nullptr;
        unsigned int cnt = 0;
        Node() {}
        Node(Node *parent) : parent(parent) {}
        ~Node() {
            for (auto &p : children) {
                delete p.second;
            }
        }
    };

    Node *root;
    Node *fixed;
    vector<char> cs;
    Trie() : root(new Node()), fixed(root), cs({'P', 'I', 'Z', 'A'}) {}
    ~Trie() {
        delete root;
    }

    bool insert(string s) {
        Node *cur = root;
        for (unsigned int i = 0; i < s.length(); i++) {
            if (!cur->children[s[i]]) {
                cur->children[s[i]] = new Node(cur);
                cur->cnt++;
            }
            cur = cur->children[s[i]];
        }
        return fixed->cnt == cs.size();
    }

    string find_new(string fixed_ans) {
        Node *cur = fixed;
        char to_append;
        for (char c : cs) {
            if (!cur->children[c]) {
                to_append = c;
                break;
            }
        }
        return fixed_ans += to_append;
    }

    void fix(char c) {
        Node *next_fixed = fixed->children[c];
        if (next_fixed != nullptr)
            fixed = next_fixed;
    }
};

bool need_new(string cur_ans, string in) {
    for (unsigned int i = 0; i < cur_ans.size(); i++) {
        if (i >= in.size())
            return true;
        if (cur_ans[i] != in[i])
            return false;
    }
    return true;
}

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n, m;
    string op, tmp_ans, ans;
    judge_in >> op >> n >> m >> ans;
    bool adaptive = (op == "adaptive");
    if (adaptive) {
        ans = "";
        tmp_ans = "P";
    }

    Trie trie = Trie();

    cout << n << endl;

    for (int q = 0; q < m; q++) {
        string guess;
        if (!(author_out >> guess))
            wrong_answer("Wrong answer: unexpected EOF.\n");

        if (guess.size() > n)
            wrong_answer("Wrong answer: guess is longer than answer.\n");

        int res = 0;
        if (adaptive) {
            if (trie.insert(guess) && tmp_ans.size() <= n) {
                ans = tmp_ans;
                trie.fix(ans[ans.size() - 1]);
            }
            if (need_new(tmp_ans, guess)) {
                tmp_ans = trie.find_new(ans);
                if (need_new(tmp_ans, guess)) {
                    res = 1;
                }
            }
        }
        else {
            auto mismatchres = mismatch(guess.begin(), guess.end(), ans.begin());
            if (mismatchres.first == guess.end())
                res = 1;
        }

        if (ans.size() == n && guess == ans) {
            cout << 2 << endl;

            string trash;
            if (author_out >> trash)
                wrong_answer("Wrong answer: trailing output.\n");

            judge_message("Queries used: %d.\n", q + 1);
            accept();
        }

        cout << res << endl;
    }

    wrong_answer("Wrong answer: used all %d queries without finding correct answer.\n", m);
}
