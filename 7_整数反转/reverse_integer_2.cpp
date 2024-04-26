#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    int ret = 0;
    while (x) {
      if (ret > 214748364 || ret < -214748364) {
        return 0;
      }
      ret = ret * 10 + x % 10;
      x = x / 10;
    }
    return ret;
  }
};

int main() {
  Solution s;
  int result = s.reverse(-123);
  cout << "result is " << result << endl;
  return 0;
}