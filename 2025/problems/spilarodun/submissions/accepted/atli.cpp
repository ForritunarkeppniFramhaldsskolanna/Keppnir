#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct card {
    string name, id, date;
    int type;
    card(string dat[4]) {
        name = dat[0];
        id = dat[1];
        date = dat[3];
        if(dat[2] == "Annad") {
            type = 17;
        } else if(dat[2][0] == 'S') {
            if(dat[2][11] == 'V')
                type = 0;
            else if(dat[2][11] == 'A')
                type = 1;
            else if(dat[2][11] == 'B')
                type = 2;
            else if(dat[2][14] == 'r')
                type = 3;
            else if(dat[2][11] == 'S')
                type = 4;
            else if(dat[2][12] == 'h')
                type = 5;
            else if(dat[2][11] == 'P')
                type = 6;
            else type = 7;
        } else if(dat[2][1] == 'a') {
            if(dat[2][9] == 'V')
                type = 8;
            else if(dat[2][10] == 'u')
                type = 9;
            else if(dat[2][10] == 'v')
                type = 10;
            else if(dat[2][9] == 'S')
                type = 11;
            else if(dat[2][9] == 'B')
                type = 12;
            else type = 13;
        } else {
            if(dat[2][9] == 'V')
                type = 14;
            else if(dat[2][9] == 'S')
                type = 15;
            else type = 16;
        }
    }
};

card read_card() {
    string buf;
    getline(cin, buf);
    string parts[4] = { "", "", "", "" };
    int ind = 0;
    for(int i = 0; i < buf.size(); ++i) {
        if(buf[i] == ',') {
            i++; ind++;
            continue;
        }
        parts[ind].push_back(buf[i]);
    }
    return card(parts);
}

int main() {
    string buf;
    getline(cin, buf);
    int n = stoi(buf);
    vector<card> cards;
    for(int i = 0; i < n; ++i)
        cards.push_back(read_card());
    string ord[4];
    for(int i = 0; i < 4; ++i)
        cin >> ord[i];
    sort(cards.begin(), cards.end(), [&](const card &c1, const card &c2) {
        for(int i = 0; i < 4; ++i) {
            if(ord[i] == "nafn" && c1.name != c2.name)
                return c1.name < c2.name;
            if(ord[i] == "id" && c1.id != c2.id)
                return c1.id < c2.id;
            if(ord[i] == "flokkur" && c1.type != c2.type)
                return c1.type < c2.type;
            if(ord[i] == "dagsetning" && c1.date != c2.date)
                return c1.date < c2.date;
        }
        return false;
    });
    for(int i = 0; i < n; ++i) {
        cout << cards[i].name << '\n';
    }
}
