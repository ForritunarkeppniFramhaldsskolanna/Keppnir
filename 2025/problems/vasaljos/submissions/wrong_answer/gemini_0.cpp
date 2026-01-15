#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<bool> known_good(n + 1, false);
  int good_count = 0;

  for (int i = 1; i <= n; ++i) {
    if (good_count >= 2) break;
    
    if (known_good[i]) continue;

    for (int j = i + 1; j <= n; ++j) {
        if (known_good[j]) continue;

        cout << i << " " << j << endl;
        string result;
        cin >> result;

        if (result == "Ljos!") {
            return 0;
        } else {
            // "Myrkur!"
            
            bool i_might_be_good = true;
            bool j_might_be_good = true;

             //Check against known good batteries if any exist to see if either of them is bad
            for (int k = 1; k <= n; ++k) {
                if(k == i || k == j) continue;

                if(known_good[k]){
                    cout << i << " " << k << endl;
                    cin >> result;
                    if(result == "Ljos!"){
                        i_might_be_good = false;
                        break; // i is bad
                    }

                    cout << j << " " << k << endl;
                    cin >> result;
                    if (result == "Ljos!"){
                        j_might_be_good = false;
                        break; // j is bad.
                    }
                }
            }
          
          if (!i_might_be_good) break; // if i is definitely bad, move on. No need to check it anymore.
          if(!j_might_be_good) continue; //if j is def bad, no need to recheck.
            
        }
    }

     //After the inner loop, check to find any known good battery.
    for (int j = i+1; j <=n; j++) {

          if (known_good[j]) continue;

          bool i_good = true;
        for (int k = 1; k <= n; k++){
            
          if (k != i && k!= j && !known_good[k]) {

                cout << i << " " << k << endl;
                string result;
                cin >> result;
                if(result == "Ljos!"){
                    known_good[i] = true;
                    good_count++;
                    i_good = false;
                    break;
                }
            }
        }

        if(!i_good) break;
    }


  }

    //Find the 2 good ones
    vector<int> good_ones;
      for(int i = 1; i <=n; ++i){
          if(known_good[i]){
              good_ones.push_back(i);
          }
          if(good_ones.size() == 2) break;
      }

      if(good_ones.size() == 2){
          cout << good_ones[0] << " " << good_ones[1] << endl;
          string res;
          cin >> res;
      }

  return 0;
}
