#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        unordered_set<char> set;
        int i = 0;
        while (i < s.length()) {
            set.clear();
            for (int j = i; j < s.length(); ++j) {
                if (set.find(s[j]) == set.end()) {
                    set.insert(s[j]);
                    if (j - i + 1 > max_len) {
                        max_len = j - i + 1;
                    }
                    if (j == s.length() - 1) {
                        return max_len;
                    }
                    continue;
                }
                for (int k = i; k < j; ++k) {
                    if (s[k] == s[j]) {
                        i = k + 1;
                        break;
                    }
                }
                break;
            }
        }
        return max_len;
    }
};

int main() {
    Solution s;
    string str;
    cin >> str;
    int max_len = s.lengthOfLongestSubstring(str);
    cout << max_len << endl;
}
