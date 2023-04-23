#include "validate.h"
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

double progress(double x, double a, double b) {
   return (x-a)/(b-a);
}

double lerp(double p, double a, double b)
{
    return (1 - p)*a + p*b;
}

struct scoring {
    int guesses;
    int score;
};

double get_score(int guesses, int n){
    vector<scoring> scoring_for_level = {
        { 0, 100},
        { (int) ceil(log2(n)), 100 },
        { (int) ceil(sqrt(n)), 80 },
        { (n + 2)/3, 50 },
        { 2 * (n + 2)/3, 25 },
        { n-1, 5 },
        { n, 1},
    };

    if (guesses > n) return 0;

    for (size_t i = 1; i < scoring_for_level.size(); i++){
        if (guesses <= scoring_for_level[i].guesses){
            double p = progress(guesses, scoring_for_level[i-1].guesses, scoring_for_level[i].guesses);
            return lerp(p, scoring_for_level[i-1].score, scoring_for_level[i].score);
        }
    }
    assert(false);
}


int main(int argc, char **argv) {
    init_io(argc, argv);

    int n;
    judge_in >> n;

    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        int num;
        judge_in >> num;
        arr[i] = num;
    }

    cout << n << endl;

    int guesses = 0;
    while (true) {
        char operation;
        if (!(author_out >> operation)) {
            wrong_answer("Wrong answer: unexpected EOF.\n");
        }
        
        if (operation == '?'){
            int k;
            if (!(author_out >> k)) {
                wrong_answer("Wrong answer: k was not specified.\n");
            }

            if (k < 0 || k > n) {
                wrong_answer("Wrong answer: k was not in the range [0, n]\n");
            }

            vector<int> guess(k);
            for (int i = 0; i < k; i++){
                if (!(author_out >> guess[i])){
                    wrong_answer("Wrong answer: Guess %d was not specified\n", i);
                }

                guess[i]--;

                if (guess[i] < 0 || guess[i] >= n) {
                    wrong_answer("Wrong answer: Index %d out of range", guess[i]);
                }
            }

            sort(guess.begin(), guess.end());

            for (int i = 0; i < k-1; i++){
                if (guess[i] == guess[i+1]){
                    wrong_answer("Wrong answer: Same index appears twice %d", guess[i]);
                }
            }

            random_shuffle(guess.begin(), guess.end());

            for (int i = 0; i < k; i++){
                cout << arr[guess[i]] << ' ';
            }
            cout << endl;
        }
        else if (operation == '!'){
            vector<int> guess(n);
            for (int i = 0; i < n; i++){
                if (!(author_out >> guess[i])){
                    wrong_answer("Wrong answer: Guess %d was not specified\n", i);
                }

                if (guess[i] < 1 || guess[i] > n) {
                    wrong_answer("Wrong answer: Value %d out of range\n", guess[i]);
                }

                if (guess[i] != arr[i]){
                    wrong_answer("Wrong answer: Guess %d did not match answer, %d != %d\n", i, guess[i], arr[i]);
                }
            }

            string trailing;
            if (author_out >> trailing){
                wrong_answer("Wrong answer: Trailing output\n");
            }

            // Check that this is not the sample case, TODO find better way to ignoe sample.
            if (n < 1e4){
                accept_with_score(0);
            }

            accept_with_score(get_score(guesses, n)/20);
        }
        else {
            wrong_answer("Wrong answer: Invalid start of guess.\n");
        }

        guesses++;
    }
}
