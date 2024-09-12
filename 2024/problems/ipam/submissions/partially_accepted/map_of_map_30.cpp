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

ip_t read_ip() {
    string address;
    cin >> address;
    return ipv4_to_integer(address);
}

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

int main()
{
    ios_base::sync_with_stdio(false);

    size_t q;
    cin >> q;

    map<ip_t, map<string, string>> properties;
    map<string, string> definitions;
    string address;
    for (size_t i = 0; i < q; i++) {
        const auto operation { read_operation() };

        if (operation == define_op) {
            const auto key{ read_string() };
            const auto value{ read_string() };
            definitions[key] = value;
        }
        else if (operation == undefine_op) {
            const auto key{ read_string() };
            definitions.erase(key);
            for (auto& [ip, props] : properties) {
                props.erase(key);
            }
        }
        else if (operation == set_op) {
            auto start_ip{ read_ip() };
            const auto end_ip{ read_ip() };
            const auto key{ read_string() };
            const auto value{ read_string() };
            auto steps = end_ip - start_ip;
            while (steps--) {
                properties[start_ip][key] = value;
                start_ip++;
            }
            properties[start_ip][key] = value;
        }
        else if (operation == get_op) {
            const auto ip{ read_ip() };
            const auto& result{ properties[ip] };
            cout << definitions.size() << endl;
            for (const auto& [key, value] : definitions) {
                const auto it{ result.find(key) };
                cout << key << " " << (it == result.end() ? value : it->second) << endl;
            }
        }
        else {
            assert(false);
        }
    }

    return 0;
}
