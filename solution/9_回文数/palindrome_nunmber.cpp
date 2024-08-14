#include <iostream>
using namespace std;

class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        string s;
        while (x) {
            s.push_back(x % 10 + '0');
            x = x / 10;
        }
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(-121) << endl;
    return 0;
}
