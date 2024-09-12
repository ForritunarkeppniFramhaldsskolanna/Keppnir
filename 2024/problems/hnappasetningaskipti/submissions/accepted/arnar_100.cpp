#include <algorithm>
#include <iostream>

using namespace std;

constexpr string_view qwerty{R"( ~1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./)"};
constexpr string_view dvorak{R"( ~1234567890[]',.pyfgcrl/=aoeuidhtns-;qjkxbmwvz)"};
constexpr string_view bjarki{R"( 0248613579=-/bjarkigust.,loempdcnvq;[]yzhwfx'~)"};

constexpr auto get_layout(const string_view sv) {
    if (sv == "qwerty") {
        return qwerty;
    }
    if (sv == "dvorak") {
        return dvorak;
    }
    if (sv == "bjarki") {
        return bjarki;
    }
    return string_view{};
}

int main() {
    string from, to, text;
    cin >> from >> to >> to;
    cin.ignore();
    getline(cin, text);
    auto from_layout{ get_layout(from) };
    auto to_layout{ get_layout(to) };

    transform(text.begin(),
              text.end(),
              text.begin(),
              [to_layout, from_layout](const char c) { return to_layout[from_layout.find(c)]; });

    cout << text << endl;

    return 0;
}
