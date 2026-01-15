#include<iostream>
#include<vector>
using namespace std;

void quit() {
    cout << "/ff\n";
    exit(0);
}

int main() {
    int n, l, t;
    cin >> n >> l >> t;
    int cap = l * t - 1;
    vector<string> outp;
    while(n--) {
        string word;
        cin >> word;
        if(outp.empty() ||
            outp.back().size() + word.size() + 1 > cap)
            outp.push_back(word);
        else {
            outp.back().push_back(' ');
            outp.back() += word;
        }
        if(outp.back().size() > cap)
            quit();
    }
    for(string s : outp) 
        cout << s << '\n';
}
