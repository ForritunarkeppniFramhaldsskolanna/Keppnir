#include <iostream>
#include <map>

using namespace std;
char readchar(){
    char r;
    cin.get(r);
    return r;
}
void gameover(){
    cout << "Neibb" << endl;
    exit(0);
}
int main(){
    cin.sync_with_stdio(false);
    int thing = 10 * 10 * 10 - 3, counter = 0;
    char curr = readchar();
    if(curr != 'b') gameover();
    map<char,bool> things;
    things['a'] = true;
    things['i'] = true;
    things['e'] = true;
    things['o'] = true;
    things['u'] = true;
    things['y'] = true;
    
    curr = readchar();
    if(curr != 'r') gameover();
    while(curr == 'r'){
        counter++;
        curr = readchar();
    }
    if(!things[curr]) gameover();
    while(cin >> curr) gameover();
    if(counter > thing || counter < 2) gameover();

    cout << "Jebb" << endl;
}
