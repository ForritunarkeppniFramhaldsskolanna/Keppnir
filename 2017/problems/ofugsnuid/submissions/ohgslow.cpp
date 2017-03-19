#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n, temp;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        reverse(arr.begin(), arr.end());
        cin >> temp;
        arr.push_back(temp);
        reverse(arr.begin(), arr.end());
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
}
