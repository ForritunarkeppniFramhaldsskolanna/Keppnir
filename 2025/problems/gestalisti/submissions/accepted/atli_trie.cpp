#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct TrieNode {
    bool is_entry;
    int nxt[26];
    TrieNode() : is_entry(false) {
        memset(nxt, -1, sizeof(nxt));
    }
};

struct Trie {
    vector<TrieNode> nodes;
    Trie() : nodes(vector<TrieNode>(1)) { 
        nodes.reserve(1600000 + 5);
    }
    void insert(string &s) {
        int pos = 0;
        for(char c : s) {
            if(nodes[pos].nxt[c - 'a'] == -1) {
                int ind = nodes.size();
                nodes.emplace_back();
                nodes[pos].nxt[c - 'a'] = ind;
            }
            pos = nodes[pos].nxt[c - 'a'];
        }
        nodes[pos].is_entry = true;
    }
    void remove(string &s) {
        int pos = 0;
        for(char c : s) {
            pos = nodes[pos].nxt[c - 'a'];
        }
        nodes[pos].is_entry = false;
    }
    bool contains(string &s) {
        int pos = 0;
        for(char c : s) {
            pos = nodes[pos].nxt[c - 'a'];
            if(pos == -1) return false;
        }
        return nodes[pos].is_entry;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    Trie tr;
    while(n--) {
        char op; string nam;
        cin >> ws >> op >> nam;
        if(op == '+') {
            tr.insert(nam);
        }
        if(op == '-') {
            tr.remove(nam);
        }
        if(op == '?') {
            cout << (tr.contains(nam) ? "Jebb\n" : "Neibb\n");
        }
    }
}
