#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <ranges>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#if __cplusplus <= 202002L
template <class Enum>
constexpr std::underlying_type_t<Enum> to_underlying(Enum e) noexcept {
    return static_cast<std::underlying_type_t<Enum>>(e);
}
#endif

enum struct type_t : int32_t {
    venjulegt = 1 << 0,
    ahrifa = 1 << 1,
    bodunar = 1 << 2,
    samruna = 1 << 3,
    samstillt = 1 << 4,
    thaeo = 1 << 5,
    penduls = 1 << 6,
    tengis = 1 << 7,
    venjulegur = 1 << 8,
    bunadar = 1 << 9,
    svida = 1 << 10,
    samfelldur = 1 << 11,
    bodunarr = 1 << 12,
    hradur = 1 << 13,
    venjuleg = 1 << 14,
    samfelld = 1 << 15,
    mot = 1 << 16,
    skrimsli = 1 << 20,
    galdur = 1 << 21,
    gildra = 1 << 22,
    annad = 1 << 23,
};

istream& operator>>(istream& ins, type_t& type) {
    using enum type_t;
    string s;
    ins >> s;
    if (s.size() > 0 && s.back() == ',') {
        s.pop_back();
    }
    int32_t result = 0;
    if (s == "Skrimsli") {
        result |= to_underlying(skrimsli);
    }
    else if (s == "Galdur") {
        result |= to_underlying(galdur);
    }
    else if (s == "Gildra") {
        result |= to_underlying(gildra);
    }
    else if (s == "Annad") {
        type = annad;
        return ins;
    }
    else {
        assert(false);
    }

    ins >> s;
    ins >> s;
    if (s.size() > 0 && s.back() == ',') {
        s.pop_back();
    }

    if (s == "Venjulegt") {
        result |= to_underlying(venjulegt);
    }
    else if (s == "Ahrifa") {
        result |= to_underlying(ahrifa);
    }
    else if (s == "Bodunar") {
        result |= (result == to_underlying(skrimsli) ? to_underlying(bodunar) : to_underlying(bodunarr));
    }
    else if (s == "Samruna") {
        result |= to_underlying(samruna);
    }
    else if (s == "Samstillt") {
        result |= to_underlying(samstillt);
    }
    else if (s == "Thaeo") {
        result |= to_underlying(thaeo);
    }
    else if (s == "Penduls") {
        result |= to_underlying(penduls);
    }
    else if (s == "Tengis") {
        result |= to_underlying(tengis);
    }
    else if (s == "Venjulegur") {
        result |= to_underlying(venjulegur);
    }
    else if (s == "Bunadar") {
        result |= to_underlying(bunadar);
    }
    else if (s == "Svida") {
        result |= to_underlying(svida);
    }
    else if (s == "Samfelldur") {
        result |= to_underlying(samfelldur);
    }
    else if (s == "Hradur") {
        result |= to_underlying(hradur);
    }
    else if (s == "Venjuleg") {
        result |= to_underlying(venjuleg);
    }
    else if (s == "Samfelld") {
        result |= to_underlying(samfelld);
    }
    else if (s == "Mot") {
        result |= to_underlying(mot);
    }
    else {
        assert(false); 
    }
    type = static_cast<type_t>(result);
    return ins;
}


struct card_t {
    int32_t id;
    type_t type;
    string name;
    string date;
};

istream& operator>>(istream& ins, card_t& card) {
    ins >> ws;
    getline(ins, card.name, ','); 
    ins >> ws;
    ins >> card.id;
    ins >> ws;
    char trash;
    ins >> trash;
    ins >> card.type;
    ins >> ws;
    ins >> card.date;
    return ins;
}

int main() {
    int32_t n;
    cin >> n;
    vector<card_t> cards(n);
    for (auto& card : cards) {
        cin >> card;
    }

    vector<string> orders(4);
    for (auto& order : orders) {
        cin >> order;
    }

    for (auto& order : views::reverse(orders)) {
        if (order == "nafn") {
            ranges::stable_sort(cards, {}, &card_t::name);
        }
        else if (order == "id") {
            ranges::stable_sort(cards, {}, &card_t::id);
        }
        else if (order == "flokkur") {
            ranges::stable_sort(cards, {}, &card_t::type);
        }
        else if (order == "dagsetning") {
            ranges::stable_sort(cards, {}, &card_t::date);
        }
        else {
            assert(false);
        }
    }

    for (const auto& card : cards) {
        cout << card.name << endl;
    }

    return 0;
}
