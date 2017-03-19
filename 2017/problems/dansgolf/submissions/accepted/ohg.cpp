#include <iostream>
#include <map>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    int l, b, c, counter = 0, x, y;
    cin >> l >> b >> c;
    map<int,bool> track;
    for(int i = 0; i < c; i++){
        cin >> x >> y;
        if(!track[x - y]){
            track[x - y] = true;
            counter++;
        }
    }
    cout << counter << endl;
} 
