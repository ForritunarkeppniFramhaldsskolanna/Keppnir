#include<iostream>
#include<random>
using namespace std;

int main() {
    srand(123);
    string letters = "abcdefghijklmnopqrstuvwxyz";
    string s; cin >> s;
    for(int i = 0; i < 10; ++i) {
        cout << letters[rand() % 26];
    }
    cout << '\n';
}
