#include<bits/stdc++.h>
using namespace std;

void quitr() { cout << "Runnun\n"; exit(0); }
void quitt() { cout << "Styfun\n"; exit(0); }
void quitd() { cout << "Veit ekki\n"; exit(0); }

int main() {
    ios_base::sync_with_stdio(false);
    string s1, s2; cin >> s1 >> s2;
    if(s1 == s2 || s2 == "0.0") quitd();
    int ploc1 = 0, ploc2 = 0;
    while(s1[ploc1] != '.') ploc1++;
    while(s2[ploc2] != '.') ploc2++;
    if(ploc1 < ploc2) quitr();
    s1.erase(ploc1, 1);
    s2.erase(ploc2, 1);
    for(int i = 0; i < s2.size(); ++i) {
        if(s2[i] > s1[i]) quitr();
        if(s2[i] < s1[i]) {
            if(s1[i] >= '5' && s1[i - 1] != '0') quitt();
            else quitd();
        }
    }
    if(s1[s2.size()] >= '5' && s2.back() != '0') quitt();
    else quitd();
}
