#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

struct Card {
    string name;
    string id;
    string type;
    string subtype;
    string date;
};

int type_order(const string& type, const string& subtype) {
    if (type == "Skrimsli") {
        if (subtype == "Venjulegt") return 0;
        if (subtype == "Ahrifa") return 1;
        if (subtype == "Bodunar") return 2;
        if (subtype == "Samruna") return 3;
        if (subtype == "Samstillt") return 4;
        if (subtype == "Thaeo") return 5;
        if (subtype == "Penduls") return 6;
        if (subtype == "Tengis") return 7;
        return 8;
    } else if (type == "Galdur") {
        if (subtype == "Venjulegur") return 9;
        if (subtype == "Bunadar") return 10;
        if (subtype == "Svida") return 11;
        if (subtype == "Samfelldur") return 12;
        if (subtype == "Bodunar") return 13;
        if (subtype == "Hradur") return 14;
        return 15;
    } else if (type == "Gildra") {
        if (subtype == "Venjuleg") return 16;
        if (subtype == "Samfelld") return 17;
        if (subtype == "Mot") return 18;
        return 19;
    } else if (type == "Annad") {
        return 20;
    }
    return 21; 
}

bool compareCards(const Card& a, const Card& b, const vector<string>& sort_order) {
    for (const string& field : sort_order) {
        if (field == "nafn") {
            if (a.name != b.name) return a.name < b.name;
        } else if (field == "id") {
            if (a.id != b.id) return a.id < b.id;
        } else if (field == "flokkur") {
            if (a.type != b.type) {
                return type_order(a.type, a.subtype) < type_order(b.type, b.subtype);
            }
            if (a.subtype != b.subtype)
            {
                return type_order(a.type, a.subtype) < type_order(b.type, b.subtype);
            }
        } else if (field == "dagsetning") {
            if (a.date != b.date) return a.date < b.date;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    vector<Card> cards(n);
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        string type_subtype = tokens[2];
        size_t dash_pos = type_subtype.find('-');
        if (dash_pos != string::npos) {
            cards[i].type = type_subtype.substr(0, dash_pos);
            cards[i].subtype = type_subtype.substr(dash_pos + 1);
        } else {
            cards[i].type = type_subtype;
            cards[i].subtype = "";
        }

        cards[i].name = tokens[0];
        cards[i].id = tokens[1];
        cards[i].date = tokens[3];
    }

    string sort_line;
    getline(cin, sort_line);
    stringstream ss_sort(sort_line);
    string sort_field;
    vector<string> sort_order;
    while (ss_sort >> sort_field) {
        sort_order.push_back(sort_field);
    }

    sort(cards.begin(), cards.end(), [&](const Card& a, const Card& b) {
        return compareCards(a, b, sort_order);
    });

    for (const Card& card : cards) {
        cout << card.name << endl;
    }

    return 0;
}
