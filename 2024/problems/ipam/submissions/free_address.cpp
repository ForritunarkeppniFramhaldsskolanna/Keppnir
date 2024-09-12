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

// Write the 128-bit integer val to out, with a minus sign if decimal and neg
// is true. Obey all of the ostream settings of out for integer display: octal
// or hexadecimal, upper case letters, plus sign, fill character and width, and
// fill placement.
static void out128(std::ostream& out, __uint128_t val, int neg) {
    // Note if the number is zero. (No hex or octal prefix in this case.)
    auto zero = val == 0;

    // Note if upper-case letters requested.
    auto state = out.flags();
    auto upper = (state & std::ios_base::uppercase) != 0;

    // Set base for digits.
    unsigned base = state & std::ios_base::hex ? 16 :
                    state & std::ios_base::oct ? 8 :
                    10;

    // Space for digits and prefix. Generate digits starting at the end of the
    // string, going backwards. num will be the digit string. Terminate it.
    char str[47];
    auto end = str + sizeof(str), num = end;
    *--num = 0;

    // Compute and place digits in base base.
    do {
        char dig = val % base;
        val /= base;
        dig += dig < 10 ? '0' : (upper ? 'A' : 'a') - 10;
        *--num = dig;
    } while (val);

    // Prepend octal number with a zero if requested.
    if (state & std::ios_base::showbase && base == 8 && !zero)
        *--num = '0';

    // pre will be the prefix string. Terminate it.
    auto pre = num;
    *--pre = 0;

    // Put a plus or minus sign in the prefix as appropriate.
    if (base == 10) {
        if (neg)
            *--pre = '-';
        else if (state & std::ios_base::showpos)
            *--pre = '+';
    }

    // Prefix a hexadecimal number if requested.
    else if (state & std::ios_base::showbase && base == 16 && !zero) {
        *--pre = upper ? 'X' : 'x';
        *--pre = '0';
    }

    // Compute the number of pad characters and get the fill character.
    auto len = (num - pre) + (end - num) - 2;
    auto pad = out.width();
    out.width(0);
    pad = pad > len ? pad - len : 0;
    char fill = out.fill();

    // Put the padding before prefix if neither left nor internal requested.
    if (!(state & (std::ios_base::internal | std::ios_base::left)))
        while (pad) {
            out << fill;
            pad--;
        }

    // Write prefix.
    out << pre;

    // Put the padding between the prefix and the digits if requested.
    if (state & std::ios_base::internal)
        while (pad) {
            out << fill;
            pad--;
        }

    // Write digits.
    out << num;

    // Put number to the left of padding, if requested.
    if (state & std::ios_base::left)
        while (pad) {
            out << fill;
            pad--;
        }
}

// Overload << for an unsigned 128-bit integer.
std::ostream& operator<<(std::ostream& out, __uint128_t val) {
    out128(out, val, 0);
    return out;
}

// Overload << for a signed 128-bit integer. Negation of the most negative
// signed value gives the correct unsigned absolute value.
std::ostream& operator<<(std::ostream& out, __int128_t val) {
    auto state = out.flags();
    if (val < 0 && !(state & (std::ios_base::hex | std::ios_base::oct)))
        out128(out, (__uint128_t)-val, 1);
    else
        out128(out, (__uint128_t)val, 0);
    return out;
}

using ip_t = unsigned __int128;

constexpr ip_t ipv4_part_bits{ 8 };
constexpr ip_t ipv6_part_bits{ 16 };


constexpr bool is_ipv4(string_view ip) {
    return ip.find('.') != string_view::npos;
}

vector<string_view> split(string_view s, char c) {
    vector<string_view> result;
    while (true) {
        size_t pos = s.find(c);
        if (pos == string_view::npos) break;
        result.push_back(s.substr(0, pos));
        s.remove_prefix(pos + 1);
    }
    result.push_back(s);
    return result;
}

ip_t ipv6_to_integer(string_view ip) {
    auto parts{ split(ip, ':') };
    ip_t result{ 0 };

    auto skip_it{ find_if(parts.begin() + 1,
                          parts.end(),
                          [](const auto sv){ return sv.empty(); })
    };

    size_t parts_low{ 0 };
    size_t parts_high{ 0 };
    size_t parts_skipped{ 0 };
    if (skip_it != parts.end()) {
        size_t skip_index{ static_cast<size_t>(distance(parts.begin(), skip_it)) };
        parts_high = skip_index;
        parts_low = parts.size() - skip_index - 1;
        if (parts.begin()->empty()) parts_high--;
        if (parts.rbegin()->empty()) parts_low--;
        parts_skipped = 8 - (parts_high + parts_low);
    }
    else {
        parts_high = parts.size();
        parts_low = 0;
        parts_skipped = 0;
    }
    
    for (size_t i = 0; i < parts_high; i++) {
        ip_t part{ 0 };
        std::from_chars(parts[i].begin(), parts[i].end(), part, 16);
        result <<= ipv6_part_bits;
        result |= part;
    }
    result <<= ipv6_part_bits * parts_skipped;
    for (size_t i = parts.size() - parts_low; i < parts.size(); i++) {
        ip_t part{ 0 };
        std::from_chars(parts[i].begin(), parts[i].end(), part, 16);
        result <<= ipv6_part_bits;
        result |= part;
    }

    return result;
}

const ip_t ipv4_start{ ipv6_to_integer("0:0:0:0:0:ffff:0:0") };
const ip_t ipv4_end{ ipv6_to_integer("0:0:0:0:0:ffff:ffff:ffff") };

ip_t ipv4_to_integer(string_view ip) {
    ip_t result{ 0 };
    while (!ip.empty()) {
        ip_t part{ 0 };
        auto [ptr, ec] = std::from_chars(ip.begin(), ip.end(), part);
        result = (result << ipv4_part_bits) | part;
        auto step{ distance(ip.begin(), ptr) };
        ip.remove_prefix(step + (ptr == ip.end() ? 0 : 1));
    }
    return ipv4_start + result;
}

ip_t ip_to_integer(string_view ip) {
    if (is_ipv4(ip)) {
        return ipv4_to_integer(ip);
    }
    return ipv6_to_integer(ip);
}

ip_t read_ip() {
    string address;
    cin >> address;
    return ip_to_integer(address);
}

void write_ip(ip_t ip) {
    cout << hex;
    for (int i = 7; i >= 0; i--) {
        cout << setfill('0') << setw(4) << ((ip >> (i*16)) & 0xffff) << (i ? ":" : "");
    }
    cout << dec << endl;
}

template <typename index_t, typename count_t>
struct vertex_t {
    using key_t = string;
    using value_t = string;
    using collection_t = map<value_t, count_t>;
    
    index_t left;
    index_t right;
    count_t in_use{ 0 };
    std::optional<bool> lazy;

    vertex_t<index_t, count_t> *left_child{ nullptr };
    vertex_t<index_t, count_t> *right_child{ nullptr };

    vertex_t(index_t left, index_t right) : left(left), right(right) {}

    bool fully_inside(index_t l, index_t r) {
        return l <= left && right <= r;
    }

    bool fully_outside(index_t l, index_t r) {
        return max(left, l) > min(right, r);
    }

    bool is_internal() const {
        return left < right;
    }
    
    void extend() {
        if (!left_child && is_internal()) {
            index_t mid = left + (right - left) / 2;
            left_child = new vertex_t<index_t, count_t>(left, mid);
            right_child = new vertex_t<index_t, count_t>{mid+1, right};
        }
    }

    void push(vertex_t<index_t, count_t>* child) {
        if (child && lazy.has_value()) {
            child->lazy = lazy;
        }
    }

    void apply() {
        if (lazy.has_value()) {
            in_use = lazy.value() * (right - left + 1);
            lazy = std::nullopt;
        }
    }

    void propagate() {
        push(left_child);
        push(right_child);
        apply();
    }

    index_t size() const {
        return right - left + 1;
    }

    count_t set_usage(index_t l, index_t r, bool taken) {
        extend();
        propagate();
        if (fully_inside(l, r)) {
            lazy = taken;
            propagate();
            return in_use;
        }
        if (fully_outside(l, r)) {
            return in_use;
        }
        return in_use = left_child->set_usage(l, r, taken) + right_child->set_usage(l, r, taken);
    }

    count_t get_usage(index_t l, index_t r) {
        extend();
        propagate();
        if (fully_inside(l, r)) {
            return in_use;
        }
        if (fully_outside(l, r)) {
            return 0;
        }
        return left_child->get_usage(l, r) + right_child->get_usage(l, r);
    }

    std::optional<index_t> find_first_unused(index_t l, index_t r) {
        extend();
        propagate();
        if (fully_inside(l, r)) {
            if (!is_internal()) {
                return in_use == 0 ? std::optional<index_t>{left} : std::optional<index_t>{};
            }
            if (left_child->in_use < left_child->size()) {
                return left_child->find_first_unused(l, r);
            }
            else {
                return right_child->find_first_unused(l, r);
            }
        }
        if (fully_outside(l, r)) {
            return {};
        }
        auto left_res{ left_child->find_first_unused(l, r) };
        return left_res.has_value() ? left_res : right_child->find_first_unused(l, r);
    }
};

constexpr int get_op{ 1 };
constexpr int set_op{ 2 };
constexpr int find_first_unused_op{ 3 };

int read_operation() {
    int op;
    cin >> op;
    return op;
}

string read_string() {
    string s;
    cin >> s;
    return s;
}

bool read_set_value() {
    string s;
    cin >> s;
    return s == "lease" ? true : false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    ip_t min_ip{ 0 };
    ip_t max_ip{ ~min_ip };
    vertex_t<ip_t, ip_t> *root = new vertex_t<ip_t, ip_t>{min_ip, max_ip};

    string address;
    for (int i = 0; i < n; i++) {
        const auto operation { read_operation() };
        const auto start_ip{ read_ip() };
        const auto end_ip{ read_ip() };
        
        if (operation == get_op) {
            const auto result{ root->get_usage(start_ip, end_ip) };
            cout << result << endl;
        }
        else if (operation == set_op) {
            const auto taken{ read_set_value() };
            root->set_usage(start_ip, end_ip, taken);
            cout << "operation finished" << endl;
        }
        else if (operation == find_first_unused_op) {
            const auto result{ root->find_first_unused(start_ip, end_ip) };
            if (result) {
                write_ip(*result);
            }
            else {
                cout << "null" << endl;
            }
        }
        else {
            assert(false);
        }
    }

    return 0;
}
