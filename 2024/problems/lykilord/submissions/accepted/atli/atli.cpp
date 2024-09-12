#include<bits/stdc++.h>
using namespace std;

const char MN_CHAR = 33;
const char MX_CHAR = 126;
const size_t CHAR_NUM = MX_CHAR - MN_CHAR + 1;
const int MAX_LEN = 32;

const string ALL_CHAR = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

char same(char c) { return c; }
char incr(char c) { return c + 1; }
char decr(char c) { return c - 1; }

unsigned long long sat_add(unsigned long long x, unsigned long long y) {
    return (x > 0xFFFFFFFFFFFFFFFF - y) ? 0xFFFFFFFFFFFFFFFF : x + y;
}

struct node {
    int next[CHAR_NUM];
    bool accepting;
    node() : accepting(false) {
        memset(next, -1, sizeof(next));
    }
};

struct dfa {
    vector<node> nodes;
    int initial;

    dfa(int n, int i) : nodes(vector<node>(n)), initial(i) { }

    void negate() {
        for(int i = 0; i < nodes.size(); ++i)
            nodes[i].accepting = !nodes[i].accepting;
    }
    
    void print(ostream &out) {
        out << nodes.size() << ' ' << initial << '\n';
        for(int i = 0; i < nodes.size(); ++i) {
            for(int j = 0; j < CHAR_NUM; ++j) {
                out << nodes[i].next[j] << ' ';
            }
            out << nodes[i].accepting << '\n';
        }
    }
};

dfa acceptor() {
    dfa d(1, 0);
    d.nodes[0].accepting = true;
    memset(d.nodes[0].next, 0, sizeof(d.nodes[0].next));
    return d;
}

dfa rejector() {
    dfa d(1, 0);
    memset(d.nodes[0].next, 0, sizeof(d.nodes[0].next));
    return d;
}

dfa deserialize(istream &in) {
    int n, initial; 
    in >> n >> initial;
    dfa res(n, initial);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < CHAR_NUM; ++j) {
            in >> res.nodes[i].next[j];
        }
        in >> res.nodes[i].accepting;
    }
    return res;
}

void add_string_to_dfa(string const &s, dfa &d) {
    int v = d.initial;
    for(char ch : s) {
        int c = ch - MN_CHAR;
        if(d.nodes[v].next[c] == -1) {
            d.nodes[v].next[c] = d.nodes.size();
            d.nodes.emplace_back();
        }
        v = d.nodes[v].next[c];
    }
    d.nodes[v].accepting = true;
}

struct aho_node {
    int next[CHAR_NUM], go[CHAR_NUM];
    bool output = false;
    int p = -1, link = - 1, pch = -1;

    aho_node(int p = -1, int ch = -1) : p(p), pch(ch) {
        memset(next, -1, sizeof(next));
        memset(go, -1, sizeof(go));
    }
};

struct aho_dfa {
    vector<aho_node> nodes;
    
    aho_dfa() : nodes(1, aho_node()) { }
    
    void add_string(string const &s) {
        int v = 0;
        for(char ch : s) {
            int c = ch - MN_CHAR;
            if(nodes[v].next[c] == -1) {
                nodes[v].next[c] = nodes.size();
                nodes.emplace_back(v, c);
            }
            v = nodes[v].next[c];
        }
        nodes[v].output = true;
    }

    int go(int v, char ch);

    int get_link(int v) {
        if(nodes[v].link == -1) {
            if(v == 0 || nodes[v].p == 0) nodes[v].link = 0;
            else nodes[v].link = go(get_link(nodes[v].p), nodes[v].pch);
        }
        return nodes[v].link;
    }

    int go(int v, int c) {
        if(nodes[v].go[c] == -1) {
            if(nodes[v].next[c] != -1) nodes[v].go[c] = nodes[v].next[c];
            else nodes[v].go[c] = v == 0 ? 0 : go(get_link(v), c);
        }
        return nodes[v].go[c];
    }

    dfa to_dfa() {
        dfa d(nodes.size(), 0);
        for(int i = 0; i < nodes.size(); ++i) {
            d.nodes[i].accepting = nodes[i].output;
            for(int j = 0; j < CHAR_NUM; ++j) {
                d.nodes[i].next[j] = go(i, j);
            }
        }
        return d;
    }
};

struct partition_refinement {
    int *locs, *ord_elem, *set_ind;
    vector<pair<int,int>> ranges;

    partition_refinement(int n) : ranges(1, make_pair(0, n - 1)) {
        locs = new int[n];
        ord_elem = new int[n];
        set_ind = new int[n];
        memset(set_ind, 0, n * sizeof(int));
        for(int i = 0; i < n; ++i) ord_elem[i] = locs[i] = i;
    }
    
    ~partition_refinement() {
        delete[] locs;
        delete[] ord_elem;
        delete[] set_ind;
    }

    vector<pair<int,int>> refine(vector<int>::iterator xb, vector<int>::iterator xe) {
        vector<pair<int,int>> hit, ret;
        for(auto it = xb; it != xe; ++it) {
            hit.push_back(make_pair(set_ind[*it], *it));
        }
        sort(hit.begin(), hit.end());
        for(int i = 0, j = 0; i < hit.size(); i = j + 1) {
            while(j + 1 < hit.size() && hit[j + 1].first == hit[i].first) j++;
            int ind = hit[i].first;
            int sz = ranges[ind].second - ranges[ind].first + 1;
            int to_move = j - i + 1;
            if(sz == to_move) continue;
            ret.push_back(ranges[ind]);
            for(int k = i; k <= j; ++k) {
                locs[ord_elem[ranges[ind].second]] = locs[hit[k].second];
                swap(ord_elem[locs[hit[k].second]], ord_elem[ranges[ind].second]);
                locs[hit[k].second] = ranges[ind].second;
                ranges[ind].second--;
            }
            for(int k = ranges[ind].second + 1; k <= ranges[ind].second + to_move; ++k) {
                set_ind[ord_elem[k]] = ranges.size();
            }
            ranges.push_back(make_pair(ranges[ind].second + 1, ranges[ind].second + to_move));
            ret.push_back(ranges[ind]);
            ret.push_back(ranges.back());
        }
        return ret;
    }
};

void remove_unreachable(dfa &d) {
    vector<bool> reachable(d.nodes.size(), false);
    vector<int> q;
    reachable[d.initial] = true;
    q.push_back(d.initial);
    while(q.size() > 0) {
        vector<int> new_q;
        for(int j = 0; j < CHAR_NUM; ++j) {
            for(int i : q) {
                int x = d.nodes[i].next[j];
                if(!reachable[x]) {
                    reachable[x] = true;
                    new_q.push_back(x);
                }
            }
        }
        q = new_q;
    }
    int counter = 0;
    vector<int> new_ind;
    for(int i = 0; i < d.nodes.size(); ++i) {
        if(!reachable[i]) new_ind.push_back(-1);
        else new_ind.push_back(counter++);
    }
    if(counter == d.nodes.size()) return;
    dfa smaller(counter, new_ind[d.initial]);
    for(int i = 0; i < d.nodes.size(); ++i) {
        if(reachable[i]) {
            smaller.nodes[new_ind[i]].accepting |= d.nodes[i].accepting;
            for(int j = 0; j < CHAR_NUM; ++j) {
                int x = d.nodes[i].next[j];
                smaller.nodes[new_ind[i]].next[j] = new_ind[d.nodes[i].next[j]];
            }
        }
    }
    d = smaller;
}

void remove_duplicates(dfa &d) {
    partition_refinement p(d.nodes.size());
    vector<int> acc;
    vector<vector<int>> rev(d.nodes.size() * CHAR_NUM, vector<int>());
    for(int i = 0; i < d.nodes.size(); ++i) {
        if(d.nodes[i].accepting) acc.push_back(i);
        for(int j = 0; j < CHAR_NUM; ++j) {
            rev[d.nodes[i].next[j] * CHAR_NUM + j].push_back(i);
        }
    }
    p.refine(acc.begin(), acc.end());
    set<pair<int,int>> todo;
    todo.insert(p.ranges[0]);
    while(todo.size() > 0) {
        pair<int,int> a = *todo.begin();
        todo.erase(todo.begin());
        for(int j = 0; j < CHAR_NUM; ++j) {
            vector<int> x;
            for(int i = a.first; i <= a.second; ++i) {
                for(int k : rev[p.ord_elem[i] * CHAR_NUM + j]) {
                    x.push_back(k);
                }
            }
            auto res = p.refine(x.begin(), x.end());
            for(int i = 0; i < res.size(); i += 3) {
                if(todo.count(res[i])) {
                    todo.erase(res[i]);
                    todo.insert(res[i + 1]);
                    todo.insert(res[i + 2]);
                } else {
                    int sz1 = res[i + 1].second - res[i + 1].first;
                    int sz2 = res[i + 2].second - res[i + 2].first;
                    todo.insert(sz1 < sz2 ? res[i + 1] : res[i + 2]);
                }
            }
        }
    }
    int *new_ind = new int[d.nodes.size()];
    memset(new_ind, -1, d.nodes.size() * sizeof(int));
    int initial = -1;
    for(int i = 0; i < p.ranges.size(); ++i) {
        for(int j = p.ranges[i].first; j <= p.ranges[i].second; ++j) {
            if(p.ord_elem[j] == d.initial)
                initial = i;
            new_ind[p.ord_elem[j]] = i;
        }
    }
    dfa reduced(p.ranges.size(), initial);
    for(int i = 0; i < p.ranges.size(); ++i) {
        for(int j = 0; j < CHAR_NUM; ++j) {
            for(int k = p.ranges[i].first; k <= p.ranges[i].second; ++k) {
                reduced.nodes[i].next[j] = new_ind[d.nodes[p.ord_elem[k]].next[j]];
                reduced.nodes[i].accepting |= d.nodes[p.ord_elem[k]].accepting;
            }
        }
    }
    delete[] new_ind;
    d = reduced;
}

dfa powerset_construction(dfa &d, vector<int> init, vector<int> loops) {
    sort(init.begin(), init.end());
    vector<int> is_loop(d.nodes.size(), 0);
    for(int x : loops) is_loop[x] = 1;
    dfa pd(1, 0);
    for(int x : init) pd.nodes.back().accepting |= d.nodes[x].accepting;
    map<vector<int>,int> ind;
    ind[init] = 0;
    vector<pair<vector<int>,int>> q;
    q.push_back(make_pair(init, 0));
    while(q.size() > 0) {
        auto [cur, cur_ind] = q.back();
        q.pop_back();
        for(int j = 0; j < CHAR_NUM; ++j) {
            vector<int> poss_next;
            for(int i : cur) {
                if(is_loop[i]) poss_next.push_back(i);
                int x = d.nodes[i].next[j];
                poss_next.push_back(x);
            }
            sort(poss_next.begin(), poss_next.end());
            poss_next.erase(unique(poss_next.begin(), poss_next.end()), poss_next.end());
            if(!ind.count(poss_next)) {
                ind[poss_next] = pd.nodes.size();
                q.push_back(make_pair(poss_next, pd.nodes.size()));
                pd.nodes.emplace_back();
                for(int x : poss_next) pd.nodes.back().accepting |= d.nodes[x].accepting;
            }
            pd.nodes[cur_ind].next[j] = ind[poss_next];
        }
    }
    // no need to remove unreachable, comes with construction, so this minimizes
    remove_duplicates(pd);
    return pd;
}

template<typename K, typename V>
struct HashCell {
    int8_t dist;
    K key;
    V val;

    HashCell() : dist(-1) { }

    void set_values(int8_t d, K k, V v) {
        dist = d;
        key = k;
        val = v;
    }

    bool inline has_value() const {
        return dist >= 0;
    }
};


// Have to have K as an int-like type to allow for bit operations
// No such limitations on V
template<typename K, typename V>
struct HashTable {
    size_t entries, size, mask, log;
    std::vector<HashCell<K,V> > dat;

    HashTable() : entries(0), size(4), mask(3), log(2), dat(7, HashCell<K,V>()) { }

    void grow() {
        size *= 2;
        mask = size - 1;
        log++;
        rehash(size + log + 1);
    }

    void rehash(size_t buckets) {
        std::vector<HashCell<K, V> > old_dat;
        std::swap(dat, old_dat);
        dat = std::vector<HashCell<K, V> >(buckets, HashCell<K, V>());
        entries = 0;
        for(auto cell : old_dat) {
            if(cell.has_value()) {
                insert(cell.key, cell.val);
            }
        }
    }

    void clear() {
        size = 4;
        mask = 3;
        log = 2;
        entries = 0;
        std::vector<HashCell<K,V> > new_dat(7, HashCell<K,V>());
        std::swap(new_dat, dat);
    }

    // Using a hash incurs a minor overhead but it allows for a far better load factor
    // In tests the resulting hash table is about 4 times smaller
    // Tests show this function to be sufficient to achieve this effect
    // while still being very fast for minimal overhead
    // Will likely have to be changed if table is used for non-32bit inputs
    K inline hash(K x) const {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        return x & mask;
    }

    void insert(K k, V v) {
        if(entries > size / 2) grow();
        K ind = hash(k);
        for(int8_t d = 0; d < log; ++d, ++ind) {
            if(!dat[ind].has_value()) {
                dat[ind].set_values(d, k, v);
                entries++;
                return;
            } else if(dat[ind].key == k) {
                dat[ind].val = v;
                return;
            } else if(dat[ind].dist < d) {
                std::swap(v, dat[ind].val);
                std::swap(k, dat[ind].key);
                std::swap(d, dat[ind].dist);
            }
        }
        grow();
        insert(k, v);
    }

    V get(K k, V fallback) {
        K ind = hash(k);
        for(int8_t d = 0; dat[ind].dist >= d; ++d, ++ind) {
            if(dat[ind].key == k) {
                return dat[ind].val;
            }
        }
        return fallback;
    }
    
    bool has_key(K k) {
        K ind = hash(k);
        for(int8_t d = 0; dat[ind].dist >= d; ++d, ++ind) {
            if(dat[ind].key == k) {
                return true;
            }
        }
        return false;
    }

    V& operator[](K k) {
        K ind = hash(k);
        for(int8_t d = 0; dat[ind].dist >= d; ++d, ++ind) {
            if(dat[ind].key == k) {
                return dat[ind].val;
            }
        }
    }
};

dfa union_of(dfa &d1, dfa &d2) {
    vector<HashTable<int,int>> new_ind(d1.nodes.size(), HashTable<int,int>());
    dfa res(1, 0);
    pair<int,int> initial(d1.initial, d2.initial);
    int x = 0;
    new_ind[initial.first].insert(initial.second, x++);
    vector<pair<int,int>> todo;
    todo.push_back(initial);
    res.nodes[0].accepting |= d1.nodes[d1.initial].accepting;
    res.nodes[0].accepting |= d2.nodes[d2.initial].accepting;
    while(todo.size() > 0) {
        auto cur = todo.back();
        int ind = new_ind[cur.first][cur.second];
        todo.pop_back();
        for(int j = 0; j < CHAR_NUM; ++j) {
            int fst = d1.nodes[cur.first].next[j];
            int snd = d2.nodes[cur.second].next[j];
            auto key = make_pair(fst, snd);
            if(!new_ind[fst].has_key(snd)) {
                new_ind[fst].insert(snd, x++);
                res.nodes.emplace_back();
                res.nodes.back().accepting |= d1.nodes[fst].accepting;
                res.nodes.back().accepting |= d2.nodes[snd].accepting;
                todo.push_back(key);
            }
            res.nodes[ind].next[j] = new_ind[fst][snd];
        }
    }
    remove_duplicates(res);
    return res;
}

dfa intersection_of(dfa &d1, dfa &d2) {
    d1.negate(); d2.negate();
    dfa res = union_of(d1, d2);
    res.negate();
    return res;
}

dfa at_least_from(int x, const string &sym) {
    dfa d(x + 1, 0);
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < CHAR_NUM; ++j) {
            d.nodes[i].next[j] = i;
        }
        for(char c : sym) {
            d.nodes[i].next[c - MN_CHAR] = i + 1;
        }
    }
    for(int j = 0; j < CHAR_NUM; ++j) {
        d.nodes[x].next[j] = x;
    }
    d.nodes[x].accepting = true;
    return d;
}

dfa at_most_from(int x, const string &sym) {
    dfa res = at_least_from(x + 1, sym);
    res.negate();
    return res;
}

dfa end_in_string_set(const vector<string> &subs) {
    aho_dfa ad;
    for(int i = 0; i < subs.size(); ++i) {
        ad.add_string(subs[i]);
    }
    return ad.to_dfa();
}

dfa in_string_set(const vector<string> &subs) {
    dfa d(1, 0);
    for(int i = 0; i < subs.size(); ++i) {
        add_string_to_dfa(subs[i], d);
    }
    d.nodes.emplace_back();
    for(int i = 0; i < d.nodes.size(); ++i) {
        for(int j = 0; j < CHAR_NUM; ++j) {
            if(d.nodes[i].next[j] == -1) {
                d.nodes[i].next[j] = d.nodes.size() - 1;
            }
        }
    }
    return d;
}

void with_arbitrary_suffix(dfa &d) {
    d.nodes.emplace_back();
    d.nodes.back().accepting = true;
    for(int i = 0; i < d.nodes.size(); ++i) {
        if(d.nodes[i].accepting) {
            for(int j = 0; j < CHAR_NUM; ++j) {
                d.nodes[i].next[j] = d.nodes.size() - 1;
            }
        }
    }
    remove_unreachable(d);
    remove_duplicates(d);
}

void with_arbitrary_prefix(dfa &d) {
    d = powerset_construction(d, vector<int>(1, d.initial), vector<int>(1, d.initial));
}

dfa contain_func_row(int x, char (*f)(char)) {
    vector<string> poss(CHAR_NUM, "");
    for(int j = 0; j < CHAR_NUM; ++j)
        poss[j].push_back(ALL_CHAR[j]);
    for(int i = 0; i < x - 1; ++i) {
        for(int j = 0; j < CHAR_NUM; ++j) {
            poss[j].push_back(f(poss[j].back()));
        }
    }
    vector<string> valid;
    for(string s : poss) {
        bool ok = true;
        for(char c : s) {
            ok &= c >= MN_CHAR;
            ok &= c <= MX_CHAR;
        }
        if(ok) valid.push_back(s);
    }
    dfa res = end_in_string_set(valid);
    with_arbitrary_suffix(res);
    return res;
}


dfa english_words(string arg0, bool exact) {
    auto binary_path { filesystem::path{ arg0 } };
    auto words_path { filesystem::absolute(binary_path).parent_path() / "words.txt" };
    ifstream english { words_path };
    vector<string> words;
    string word;
    while(english >> word) {
        words.push_back(word);
    }
    if(exact) {
        return in_string_set(words);
    } else {
        dfa res = end_in_string_set(words);
        with_arbitrary_suffix(res);
        return res;
    }
}

dfa top_passwords(string arg0, int n) {
    auto binary_path { filesystem::path{ arg0 } };
    auto passwords_path { filesystem::absolute(binary_path).parent_path() / "passwords.txt" };
    ifstream passwords { passwords_path };
    vector<string> pass;
    while(n--) {
        string cur;
        passwords >> cur;
        pass.push_back(cur);
    }
    return in_string_set(pass);
}

vector<vector<unsigned long long>> count_accepting(dfa &d) {
    vector<vector<unsigned long long>> dp(MAX_LEN + 1, vector<unsigned long long>(d.nodes.size(), 0));
    for(int i = 0; i < d.nodes.size(); ++i) {
        if(d.nodes[i].accepting) dp[0][i] = 1;
    }
    for(int k = 1; k <= MAX_LEN; ++k) {
        for(int i = 0; i < d.nodes.size(); ++i) {
            for(int j = 0; j < CHAR_NUM; ++j) {
                dp[k][i] = sat_add(dp[k][i], dp[k - 1][d.nodes[i].next[j]]);
            }
        }
    }
    for(int k = 1; k <= MAX_LEN; ++k) {
        for(int i = 0; i < d.nodes.size(); ++i) {
            dp[k][i] = sat_add(dp[k][i], dp[k - 1][i]);
        }
    }
    return dp;
}

void emit_strings(dfa &d, string &cur, int &m, int loc, vector<vector<unsigned long long>> &dp) {
    if(m == 0) return;
    if(dp[MAX_LEN - cur.size()][loc] == 0) return;
    if(d.nodes[loc].accepting) {
        cout << cur << '\n';
        m--;
    }
    if(cur.size() == MAX_LEN) return;
    for(int j = 0; j < CHAR_NUM; ++j) {
        cur.push_back(ALL_CHAR[j]);
        emit_strings(d, cur, m, d.nodes[loc].next[j], dp);
        cur.pop_back();
    }
}

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, x; cin >> n >> m;
    if(m == 0) {
        cout << "Mogulegt!\n";
        return 0;
    }
    if(n == 0) {
        cout << "Mogulegt!\n";
        dfa d = acceptor(); 
        string cur = "";
        vector<vector<unsigned long long>> dp = count_accepting(d);
        emit_strings(d, cur, m, d.initial, dp);
        return 0;
    }
    bool first_outer = true;
    dfa result = rejector();
    while(n--) {
        vector<dfa> subs;
        cin >> x;
        while(x--) {
            string s;
            cin >> s;
            bool negated = false;
            if(s == "not") {
                negated = true;
                cin >> s;
            }
            dfa d(0, 0);
            if(s == "contain") {
                cin >> s;
                if(s == "at") {
                    int count;
                    cin >> s >> count;
                    bool least = s == "least";
                    cin >> s >> ws;
                    string symbol_set = ALL_CHAR;
                    if(cin.peek() == 'f') {
                        cin >> s >> s;
                        symbol_set = s;
                    }
                    if(least) d = at_least_from(count, symbol_set);
                    else d = at_most_from(count, symbol_set);
                } else if(s == "an") {
                    cin >> s >> s;
                    d = english_words(argv[0], false);
                } else {
                    int count = stoi(s);
                    cin >> s >> s;
                    if(s == "equal") d = contain_func_row(count, same);
                    else if(s == "incrementing") d = contain_func_row(count, incr);
                    else if(s == "decrementing") d = contain_func_row(count, decr);
                    else assert(false);
                    cin >> s;
                }
            } else if(s == "include") {
                cin >> s;
                vector<string> triv(1, s);
                d = end_in_string_set(triv);
                with_arbitrary_suffix(d);
                cin >> s >> s >> s;
            } else if(s == "start") {
                cin >> s >> s;
                vector<string> triv(1, s);
                d = in_string_set(triv);
                with_arbitrary_suffix(d);
            } else if(s == "end") {
                cin >> s >> s;
                vector<string> triv(1, s);
                d = end_in_string_set(triv);
            } else if(s == "be") {
                cin >> s;
                if(s == "an") {
                    cin >> s >> s;
                    d = english_words(argv[0], true);
                } else if(s == "in") {
                    int count;
                    cin >> s >> count >> s >> s >> s;
                    d = top_passwords(argv[0], count);
                } else assert(false);
            } else assert(false);
            if(negated) d.negate();
            subs.push_back(d);
        }
        vector<pair<int,int>> sz_ord(subs.size());
        for(int i = 0; i < subs.size(); ++i)
            sz_ord[i] = make_pair(subs[i].nodes.size(), i);
        sort(sz_ord.begin(), sz_ord.end());
        int fst = sz_ord[0].second;
        for(int offs = 2; offs / 2 < subs.size(); offs *= 2) {
            for(int i = 0; i < subs.size() - offs / 2; i += offs)
                subs[sz_ord[i].second] = intersection_of(subs[sz_ord[i].second], subs[sz_ord[i + offs/2].second]);
        }
        vector<vector<unsigned long long>> dp = count_accepting(subs[fst]);
        if(dp[MAX_LEN][subs[fst].initial] >= m) {
            result = subs[fst];
             break;
        } else if(dp[MAX_LEN][subs[fst].initial] != 0) {
            if(first_outer) result = subs[fst];
            else result = union_of(result, subs[fst]);
            first_outer = false;
            dp = count_accepting(result);
            if(dp[MAX_LEN][result.initial] >= m) {
                break;
            }
        }
    }
    vector<vector<unsigned long long>> dp = count_accepting(result);
    if(dp[MAX_LEN][result.initial] < m) {
        cout << "Omogulegt!\n";
    } else {
        cout << "Mogulegt!\n";
        string cur = "";
        emit_strings(result, cur, m, result.initial, dp);
    }
}
