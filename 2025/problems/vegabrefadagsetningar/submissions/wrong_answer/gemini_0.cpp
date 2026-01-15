#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
  string line;
  getline(cin, line);

  int day, year;
  string icelandic_month, english_month;

  sscanf(line.c_str(), "%d %s /%s %d", &day, &icelandic_month[0], &english_month[0], &year);
  icelandic_month = icelandic_month.substr(0, 3);
  english_month = english_month.substr(0, 3);

  unordered_map<string, int> month_map = {
    {"JAN", 1}, {"FEB", 2}, {"MAR", 3}, {"APR", 4},
    {"MAÍ", 5}, {"JÚN", 6}, {"JÚL", 7}, {"ÁGÚ", 8},
    {"SEP", 9}, {"OKT", 10}, {"NÓV", 11}, {"DES", 12}
  };

  int month = month_map[icelandic_month];

  year += 2000;

  printf("%04d-%02d-%02d\n", year, month, day);

  return 0;
}
