#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    string result;
    int size = s.size();
    int n = 2 * numRows - 2;
    for (int i = 0; i < numRows; ++i) {
      for (int j = 0; j < s.size(); j += n) {
        if (i + j < s.size()) {
          result.push_back(s[i + j]);
        }
        if (i > 0 && i < numRows - 1 && j + n - i < s.size()) {
          result.push_back(s[j + n - i]);
        }
      }
    }
    return result;
  }
};

// 输入：s = "PAYPALISHIRING", numRows = 4
// 输出："PINALSIGYAHRPI"
// 解释：
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

int main() {
  Solution s;
  // s.convert("ABCDEFGHIJKLMN", 3);
  string result = s.convert("PAYPALISHIRING", 4);
  cout << "result is " << result << endl;
  return 0;
}
