#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
#define fs first
#define sc second
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

using ip_t = unsigned int;

constexpr ip_t ipv4_part_bits{ 8 };
constexpr ip_t min_ip{ 0 };
constexpr ip_t max_ip{ ~min_ip };

ip_t ipv4_to_integer(string_view ip) {
    ip_t result{ 0 };
    while (!ip.empty()) {
        ip_t part{ 0 };
        auto [ptr, ec] = std::from_chars(ip.begin(), ip.end(), part);
        result = (result << ipv4_part_bits) | part;
        auto step{ distance(ip.begin(), ptr) };
        ip.remove_prefix(step + (ptr == ip.end() ? 0 : 1));
    }
    return result;
}

ip_t ip_to_integer(string_view ip) {
    return ipv4_to_integer(ip);
}

ip_t read_ip() {
    string address;
    cin >> address;
    return ip_to_integer(address);
}

template <typename index_t, typename count_t>
struct vertex_t {
    using key_t = size_t;
    using value_t = pair<size_t, size_t>;
    using collection_t = map<key_t, value_t>;
    
    index_t left;
    index_t right;
    collection_t properties;

    vertex_t<index_t, count_t> *left_child{ nullptr };
    vertex_t<index_t, count_t> *right_child{ nullptr };

    vertex_t(index_t left, index_t right) : left(left), right(right) {}
    
    void extend() {
        if (!left_child && left < right) {
            index_t mid = left + (right - left) / 2;
            left_child = new vertex_t<index_t, count_t>(left, mid);
            right_child = new vertex_t<index_t, count_t>{mid+1, right};
        }
    }

    void set_range(const index_t l, const index_t r, const key_t& key, const value_t& value) {
        extend();
        if (l <= left && right <= r) {
            properties[key] = value;
            return;
        }
        if (max(left, l) > min(right, r)) {
            return;
        }
        left_child->set_range(l, r, key, value);
        right_child->set_range(l, r, key, value);
    }
    
    void get(index_t i, collection_t& result) {
        if (i <= left && right <= i) {
            result = properties;
            return;
        }
        if (max(left, i) > min(right, i)) {
            return;
        }
        if (left_child) left_child->get(i, result);
        if (right_child) right_child->get(i, result);
        auto iter{ result.begin() };
        for (const auto& [k, v] : properties) {
            while (iter != result.end() && iter->first < k) iter++;
            if (iter == result.end() || k < iter->first) {
                result.emplace_hint(iter, k, v);
            }
            else if (k == iter->first && v.first > iter->second.first) {
                result[k] = v;
                iter++;
            }
        }
    }

    collection_t get(index_t i) {
        collection_t result;
        get(i, result);
        return result;
    }
};

constexpr auto define_op{ '+' };
constexpr auto undefine_op{ '-' };
constexpr auto set_op{ '=' };
constexpr auto get_op{ '?' };

char read_operation() {
    char op;
    cin >> op;
    return op;
}

string read_string() {
    string s;
    cin >> s;
    return s;
}

struct string_tracker {
    vector<string> keys;
    unordered_map<string, size_t> mapping;

    string_tracker() {
        keys.reserve(1'000);
        mapping.reserve(1'000);
        mapping.max_load_factor(0.5);
    }
    
    size_t insert(const string& key) {
        const auto res{ mapping.try_emplace(key, mapping.size()) };
        if (res.second) {
            keys.push_back(key);
        }
        return res.first->second;
    }

    string_view get_string(const size_t index) {
        return keys[index];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    size_t q;
    cin >> q;

    string_tracker mapping;
    const auto null_id{ mapping.insert("") };
    vertex_t<ip_t, ip_t> *root = new vertex_t<ip_t, ip_t>{min_ip, max_ip};
    map<size_t, pair<size_t, size_t>> definitions;
    for (size_t i = 0; i < q; i++) {
        const auto operation { read_operation() };

        if (operation == define_op) {
            const auto skey{ read_string() };
            const auto key{ mapping.insert(skey) };
            const auto svalue{ read_string() };
            const auto value{ mapping.insert(svalue) };
            auto it{ definitions.find(key) };
            if (it == definitions.end()) {
                it = definitions.insert(make_pair(key, make_pair(i, value))).first;
            }
            else {
                it->second.second = value;
            }
        }
        else if (operation == undefine_op) {
            const auto skey{ read_string() };
            const auto key{ mapping.insert(skey) };
            definitions.erase(key);
        }
        else if (operation == set_op) {
            const auto start_ip{ read_ip() };
            const auto end_ip{ read_ip() };
            const auto skey{ read_string() };
            const auto key{ mapping.insert(skey) };
            const auto svalue{ read_string() };
            const auto value{ mapping.insert(svalue) };
            root->set_range(start_ip, end_ip, key, {i, value});
        }
        else if (operation == get_op) {
            const auto ip{ read_ip() };
            const auto result{ root->get(ip) };
            vector<pair<string_view, string_view>> to_output;
            auto it{ definitions.begin() };
            for (const auto& [key, value] : definitions) {
                const auto it{ result.find(key) };
                if (it == result.end() || it->second.first < value.first) {
                    to_output.emplace_back(mapping.get_string(key), mapping.get_string(value.second));
                }
                else {
                    to_output.emplace_back(mapping.get_string(key), mapping.get_string(it->second.second));
                }
            }

            sort(to_output.begin(), to_output.end());
            cout << to_output.size() << endl;
            for (const auto& [k, v] : to_output) {
                cout << k << " " << v << endl;
            }
        }
        else {
            assert(false);
        }
    }

    return 0;
}
