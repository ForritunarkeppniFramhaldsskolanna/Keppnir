#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  long double x;
  cin >> x;

  for (int num_planets = 0; num_planets <= 100000; ++num_planets) {
    long double chips = 151 + num_planets * 40;
    long double multiplier = 8 + num_planets * 4;
    multiplier *= (1 + 0.1 * num_planets);

    long double avg = (chips + multiplier) / 2.0;
    long double score = avg * avg;

    if (score >= x) {
      cout << num_planets << endl;
      return 0;
    }
  }

  return 0;
}
