#include <iostream>
#include <string>
#include <vector>
using namespace std;


int romanToInt(string s) {
  int ans = 0;
  for (int i = 0; i < s.length(); ++ i) {
    if (s[i] == 'I') {
      if ((i + 1) < s.length() && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
        if (s[i + 1] == 'V') {
          ans += 4;
        } else if (s[i + 1] == 'X') {
          ans += 9;
        }
        i ++;
        continue;
      }
      ans += 1;
    } else if (s[i] == 'X') {
      if ((i + 1) < s.length() && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
        if (s[i + 1] == 'L') {
          ans += 40;
        } else if (s[i + 1] == 'C') {
          ans += 90;
        }
        i ++;
        continue;
      }
      ans += 10;
    } else if (s[i] == 'C') {
      if ((i + 1) < s.length() && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
        if (s[i + 1] == 'D') {
          ans += 400;
        } else if (s[i + 1] == 'M') {
          ans += 900;
        }
        i ++;
        continue;
      }
      ans += 100;
    } else if (s[i] == 'V') {
      ans += 5;
    } else if (s[i] == 'L') {
      ans += 50;
    } else if (s[i] == 'D') {
      ans += 500;
    } else if (s[i] == 'M') {
      ans += 1000;
    }
  }
  return ans;
}


int main() {
  //string s = "LVIII";
  string s = "MCMXCIV";
  cout << romanToInt(s) << endl;
  return 0;
}
