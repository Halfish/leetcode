#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    if (x == -2147483648) {
      return 0;
    }
    bool isNegative = x < 0;
    if (x < 0) {
      x = -x;
    }
    int arr[10] = {0};
    int size = 0;
    while (x) {
      arr[size++] = x % 10;
      x = x / 10;
    }
    for (int i = 0; i < size; ++i) {
      cout << "arr[" << i << "] is " << arr[i] << endl;
    }
    int max[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
    if (size == 10) {
      for (int i = 0; i < 10; ++i) {
        if (arr[i] < max[i]) {
          break;
        }
        if (arr[i] > max[i]) {
          return 0;
        }
      }
    }
    int ret = 0;
    for (int i = 0; i < size; ++i) {
      cout << "i = " << i << ", s[i] = " << arr[i] << endl;
      ret = ret * 10 + (arr[i]);
    }
    return isNegative ? -ret : ret;
  }
};

int main() {
  Solution s;
  int result = s.reverse(-2147483412);
  cout << "result is " << result << endl;
  return 0;
}