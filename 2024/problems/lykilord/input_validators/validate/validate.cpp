#include <algorithm>
#include <assert.h>
#include <bitset>
#include <filesystem>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string_view>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

set<string> english_words;
map<string, size_t> common;

struct rule {
    virtual bool operator()(const string_view s) const {
        return true;
    }
};

struct at_least : rule {
    size_t min_length;
    at_least(const size_t min_length) : min_length(min_length) {
        assert(0u <= min_length);
        assert(min_length <= 32u);
    }
    bool operator()(const string_view s) const {
        return s.size() >= min_length;
    }
};

struct at_most : rule {
    size_t max_length;
    at_most(const size_t max_length) : max_length(max_length) {
        assert(0u <= max_length);
        assert(max_length <= 32u);
    }
    bool operator()(const string_view s) const {
        return s.size() <= max_length;
    }
};

struct at_least_charset : rule {
    int64_t min_count;
    bitset<128> charset;
    at_least_charset(const int64_t min_count, const string_view chars) : min_count(min_count) {
        for (const auto c : chars) {
            assert(33 <= c);
            assert(c <= 126);
            assert(!charset[c]);
            charset[c] = true;
        }
        assert(0u <= min_count);
        assert(min_count <= 32u);
    }
    bool operator()(const string_view s) const {
        return count_if(s.begin(), s.end(), [this](const char c) {
            return this->charset[c];
        }) >= min_count;
    }
};

struct at_most_charset : rule {
    int64_t max_count;
    bitset<128> charset;
    at_most_charset(const int64_t max_count, const string_view chars) : max_count(max_count) {
        for (const auto c : chars) {
            assert(33 <= c);
            assert(c <= 126);
            assert(!charset[c]);
            charset[c] = true;
        }
        assert(0u <= max_count);
        assert(max_count <= 32u);
    }
    bool operator()(const string_view s) const {
        return count_if(s.begin(), s.end(), [this](const char c) {
            return this->charset[c];
        }) <= max_count;
    }
};

struct includes_substring : rule {
    string substring;
    includes_substring(const string& substring) : substring(substring) {
        assert(1u <= substring.size() && substring.size() <= 32u);
        for(const auto c : substring) {
            assert(33 <= c);
            assert(c <= 126);
        }
    }
    bool operator()(const string_view s) const {
        return s.find(substring) != string_view::npos;
    }
};

struct starts_with : rule {
    string prefix;
    starts_with(const string& prefix) : prefix(prefix) { 
        assert(1u <= prefix.size() && prefix.size() <= 32u);
        for(const auto c : prefix) {
            assert(33 <= c);
            assert(c <= 126);
        }
    }
    bool operator()(const string_view s) const {
        return basic_string_view(s.data(), min(s.size(), prefix.size())) == prefix;
    }
};

struct ends_with : rule {
    string suffix;
    ends_with(const string& suffix) : suffix(suffix) { 
        assert(1u <= suffix.size() && suffix.size() <= 32u);
        for(const auto c : suffix) {
            assert(33 <= c);
            assert(c <= 126);
        }
    }
    bool operator()(const string_view s) const {
        return s.size() >= suffix.size() && s.compare(s.size() - suffix.size(), string_view::npos, suffix) == 0;
    }
};

struct contain_english_word : rule {
    contain_english_word() { }
    bool operator()(const string_view s) const {
        for (size_t i = 0; i < s.size(); i++) {
            for (size_t j = 1; i+j <= s.size(); j++) {
                if (english_words.find(string{ s.substr(i, j) }) != english_words.end()) {
                    return true;
                }
            }
        }
        return false;
    }
};

struct consecutive : rule {
    size_t count;
    int64_t diff;
    consecutive(const size_t count, const int64_t diff) : count(count), diff(diff) {
        assert(2 <= count && count <= 5);
        assert(-1 <= diff && diff <= 1);
    }
    bool operator()(const string_view s) const {
        if (count == 0) {
            return true;
        }
        for (size_t i = 0; i + count - 1 < s.size(); i++) {
            const auto sub{ s.substr(i, count) };
            if (adjacent_find(sub.begin(), sub.end(), [this](const int a, const int b) { return b - a != this->diff; }) == sub.end()) {
                return true;
            }
        }
        return false;
    }
};

struct be_english_word : rule {
    be_english_word() { }
    bool operator()(const string_view s) const {
        return english_words.find(string{ s }) != english_words.end();
    }
};

struct most_common_passwords : rule {
    size_t count;
    most_common_passwords(const size_t count) : count(count) {
        assert(1u <= count);
        assert(count <= 100'000u);
    }
    bool operator()(const string_view s) const {
        auto it{ common.find(string{ s }) };
        return it != common.end() && it->second < count;
    }
};

struct not_rule : rule {
    shared_ptr<rule> other;
    not_rule(shared_ptr<rule> other) : other(other) {}
    bool operator()(const string_view s) const {
        return !(*other)(s);
    }
};


shared_ptr<rule> read_rule(const string& line) {
    stringstream ss(line);
    string token;
    ss >> token;
    if (token == "not") {
        ss >> ws;
        assert(getline(ss, token));
        assert(token.substr(0, 10) != "contain at");
        assert(token.substr(0, 3) != "not");
        return make_shared<not_rule>(read_rule(token));
    }
    if (token == "include") {
        // <string>
        assert(ss >> token);
        auto result{ make_shared<includes_substring>(token) };
        // as a substring
        assert(ss >> token);
        assert(token == "as");
        assert(ss >> token);
        assert(token == "a");
        assert(ss >> token);
        assert(token == "substring");
        return result;
    }
    if (token == "start") {
        // with <string>
        assert(ss >> token);
        assert(token == "with");
        assert(ss >> token);
        return make_shared<starts_with>(token);
    }
    if (token == "end") {
        // with <string>
        assert(ss >> token);
        assert(token == "with");
        assert(ss >> token);
        return make_shared<ends_with>(token);
    }
    if (token == "be") {
        assert(ss >> token);
        if (token == "an") {
            // english word
            assert(ss >> token);
            assert(token == "english");
            assert(ss >> token);
            assert(token == "word");
            return make_shared<be_english_word>();
        }
        if (token == "in") {
            int count;
            // top <count> most common passwords
            assert(ss >> token);
            assert(token == "top");
            assert(ss >> count >> token);
            assert(token == "most");
            assert(ss >> token);
            assert(token == "common");
            assert(ss >> token);
            assert(token == "passwords");
            return make_shared<most_common_passwords>(count);
        }
    }
    if (token == "contain") {
        assert(ss >> token);
        if (token == "at") {
            assert(ss >> token);
            if (token == "least") {
                int count;
                assert(ss >> count >> token);
                assert(token == "symbols");
                if (ss >> token) {
                    assert(token == "from");
                    assert(ss >> token);
                    return make_shared<at_least_charset>(count, token);
                }
                return make_shared<at_least>(count);
            }
            else {
                assert(token == "most");
                int count;
                assert(ss >> count >> token);
                assert(token == "symbols");
                if (ss >> token) {
                    assert(token == "from");
                    assert(ss >> token);
                    return make_shared<at_most_charset>(count, token);
                }
                return make_shared<at_most>(count);
            }
        }
        if (token == "an") {
            // an english word
            assert(ss >> token);
            assert(token == "english");
            assert(ss >> token);
            assert(token == "word");
            return make_shared<contain_english_word>();
        }
        int count{ stoi(token) };
        // consecutive <type>
        assert(ss >> token);
        assert(token == "consecutive");
        assert(ss >> token);
        if (token == "equal") {
            assert(ss >> token);
            assert(token == "symbols");
            return make_shared<consecutive>(count, 0);
        } else if (token == "incrementing") {
            assert(ss >> token);
            assert(token == "symbols");
            return make_shared<consecutive>(count, 1);
        } else {
            assert(token == "decrementing");
            assert(ss >> token);
            assert(token == "symbols");
            return make_shared<consecutive>(count, -1);
        }
    }

    assert(false);
    return {};
}

int read_nonneg_int() {
    string s;
    cin >> s;
    assert((s == "0") || (s[0] != '0'));
    return stoi(s);
}

void eat_space() {
    assert(cin.peek() == ' ');
    cin.ignore(1);
    assert(!isspace(cin.peek()));
}

void eat_newline() {
    assert(cin.peek() == '\n');
    cin.ignore(1);
    assert((cin.peek() == EOF) || !isspace(cin.peek()));
}

int main(int argc, char **argv) {
    assert(!isspace(cin.peek()));
    int num_rule_sets = read_nonneg_int();
    eat_space();
    int num_passwords = read_nonneg_int();
    eat_newline();

    int total_rules = 0;
    
    vector<vector<shared_ptr<rule>>> rule_sets(num_rule_sets);
    for (auto& rule_set : rule_sets) {
        int num_rules = read_nonneg_int();
        eat_newline();

        total_rules += num_rules;
        
        rule_set.resize(num_rules);

        string line;

        for (auto& r : rule_set) {
            assert(getline(std::cin, line));
            for(int i = 0; i < line.size() - 1; ++i) {
                assert(!isspace(line[i]) || !isspace(line[i + 1]));
            }
            for(int i = 0; i < line.size() - 1; ++i) {
                if(isspace(line[i])) {
                    assert(line[i] == ' ');
                }
            }
            r = read_rule(line);
        }
    }

    assert(total_rules <= 30);

    string s;
    assert(!(cin >> s));

    return 42;
}
