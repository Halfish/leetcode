#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string ans;
    for (int i = 0; i < s.length(); ++ i) {
      // 偶数
      int len = 0;
      while (true) {
        if (i - len < 0 || i + len + 1 >= s.length()) {
          break;
        }
        if (s[i - len] != s[i + len + 1]) {
          break;
        }
        len ++;
      }
      if (2 * len > ans.length()) {
        ans = s.substr(i - len + 1, len * 2);
      }

      // 奇数
      len = 0;
      while (true) {
        if (i - len < 0 || i + len >= s.length()) {
          break;
        }
        if (s[i - len] != s[i + len]) {
          break;
        }
        len++;
      }
      if (len * 2 - 1 > ans.length()) {
        ans = s.substr(i - len + 1, len * 2 - 1);
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  string result = s.longestPalindrome("aba");
  cout << "result is " << result;
  return 0;
};
