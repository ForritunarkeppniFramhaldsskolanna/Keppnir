#include "validate.h"
#include <algorithm>
#include <bitset>
#include <filesystem>
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
    at_least(const size_t min_length) : min_length(min_length) {}
    bool operator()(const string_view s) const {
        return s.size() >= min_length;
    }
};

struct at_most : rule {
    size_t max_length;
    at_most(const size_t max_length) : max_length(max_length) {}
    bool operator()(const string_view s) const {
        return s.size() <= max_length;
    }
};

struct at_least_charset : rule {
    int64_t min_count;
    bitset<128> charset;
    at_least_charset(const int64_t min_count, const string_view chars) : min_count(min_count) {
        for (const auto c : chars) {
            charset[c] = true;
        }
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
            charset[c] = true;
        }
    }
    bool operator()(const string_view s) const {
        return count_if(s.begin(), s.end(), [this](const char c) {
            return this->charset[c];
        }) <= max_count;
    }
};

struct includes_substring : rule {
    string substring;
    includes_substring(const string& substring) : substring(substring) { }
    bool operator()(const string_view s) const {
        return s.find(substring) != string_view::npos;
    }
};

struct starts_with : rule {
    string prefix;
    starts_with(const string& prefix) : prefix(prefix) { }
    bool operator()(const string_view s) const {
        return basic_string_view(s.data(), min(s.size(), prefix.size())) == prefix;
    }
};

struct ends_with : rule {
    string suffix;
    ends_with(const string& suffix) : suffix(suffix) { }
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
    consecutive(const size_t count, const int64_t diff) : count(count), diff(diff) {}
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
    most_common_passwords(const size_t count) : count(count) {}
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
    cerr << "Processing: " << line << endl; 
    stringstream ss(line);
    string token;
    ss >> token;
    if (token == "not") {
        ss >> ws;
        getline(ss, token);
        return make_shared<not_rule>(read_rule(token));
    }
    if (token == "include") {
        // <string>
        ss >> token;
        auto result{ make_shared<includes_substring>(token) };
        // as a substring
        ss >> token >> token >> token;
        return result;
    }
    if (token == "start") {
        // with <string>
        ss >> token >> token;
        return make_shared<starts_with>(token);
    }
    if (token == "end") {
        // with <string>
        ss >> token >> token;
        return make_shared<ends_with>(token);
    }
    if (token == "be") {
        ss >> token;
        if (token == "an") {
            // english word
            ss >> token >> token;
            return make_shared<be_english_word>();
        }
        if (token == "in") {
            int count;
            // top <count> most common passwords
            ss >> token >> count >> token >> token >> token;
            return make_shared<most_common_passwords>(count);
        }
    }
    if (token == "contain") {
        ss >> token;
        if (token == "at") {
            ss >> token;
            if (token == "least") {
                int count;
                ss >> count;
                ss >> token;
                if (ss >> token) {
                    ss >> token;
                    return make_shared<at_least_charset>(count, token);
                }
                return make_shared<at_least>(count);
            }
            else {
                int count;
                ss >> count;
                ss >> token;
                if (ss >> token) {
                    ss >> token;
                    return make_shared<at_most_charset>(count, token);
                }
                return make_shared<at_most>(count);
            }
        }
        if (token == "an") {
            // an english word
            ss >> token >> token >> token;
            return make_shared<contain_english_word>();
        }
        int count{ stoi(token) };
        // consecutive <type>
        ss >> token >> token;
        if (token == "equal") {
            ss >> token;
            return make_shared<consecutive>(count, 0);
        }
        if (token == "incrementing") {
            ss >> token;
            return make_shared<consecutive>(count, 1);
        }
        if (token == "decrementing") {
            ss >> token;
            return make_shared<consecutive>(count, -1);
        }
    }

    assert(false);
    return {};
}

void load_words(const filesystem::path& p) {
    ifstream file{ p };
    string word;
    while (file >> word) {
        english_words.insert(word);
    }
    judge_message("Loaded %d words\n", english_words.size());
    file.close();
}

void load_passwords(const filesystem::path& p) {
    ifstream file{ p };
    string word;
    for (size_t i = 0; file >> word; i++) {
        common.emplace(word, i);
    }
    judge_message("Loaded %d passwords\n", common.size());
    file.close();
}

int main(int argc, char **argv) {
    init_io(argc, argv);
    
    const auto binary_path{ filesystem::path{ argv[0] }};
    const auto words_path{ filesystem::absolute(binary_path).parent_path() / "words.txt" };
    const auto passwords_path{ filesystem::absolute(binary_path).parent_path() / "passwords.txt" };

    load_words(words_path);
    load_passwords(passwords_path);

    int num_rule_sets, num_passwords;
    judge_in >> num_rule_sets >> num_passwords;
    
    vector<vector<shared_ptr<rule>>> rule_sets(num_rule_sets);
    for (auto& rule_set : rule_sets) {
        int num_rules;
        judge_in >> num_rules;
        
        rule_set.resize(num_rules);

        judge_in.ignore();
        string line;

        for (auto& r : rule_set) {
            getline(judge_in, line);
            r = read_rule(line);
        }
    }

    string judge_possibility;
    getline(judge_ans, judge_possibility);

    string author_possibility;
    if (!getline(author_out, author_possibility)) {
        wrong_answer("Could not read first line of author output, missing Mogulegt!/Omogulegt!.\n");
    }
    
    if(strcasecmp(judge_possibility.c_str(), author_possibility.c_str()) != 0) {
        wrong_answer("Wrong answer: Incorrect value for Mogulegt!/Omogulegt!.\n");
    }
    
    if (judge_possibility == "Mogulegt!") {
        set<string> seen;
        for (int i = 0; i < num_passwords; i++) {
            const auto line_no{ i+1 };
            string password;
            if (!getline(author_out, password)) {
                wrong_answer("Could not read password in line %d.\n", line_no);
            }
            if (password.size() > 32) {
                wrong_answer("Password %s in line %d exceeds global length limit.\n", password.c_str(), line_no);
            }
            auto check_rule_set{ [&password](const vector<shared_ptr<rule>>& rule_set) {
                return all_of(rule_set.begin(), rule_set.end(), [&password](const auto r) {
                    return (*r)(password);
                });
            } };
            if (seen.find(password) != seen.end()) {
                wrong_answer("Password %s in line %d has already appeared.\n", password.c_str(), line_no);
            }
            if (!rule_sets.empty() && none_of(rule_sets.begin(), rule_sets.end(), check_rule_set)) {
                wrong_answer("Password %s in line %d does not satisfy any rule set.\n", password.c_str(), line_no);
            }
            seen.insert(password);
        }
    }
    string s;
    author_out >> ws;
    if(author_out >> s) {
        wrong_answer("Wrong answer: Trailing output.\n");
    }

    accept();

    return 0;
}
