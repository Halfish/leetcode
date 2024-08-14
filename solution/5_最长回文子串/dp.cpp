#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }

    void print(int **dp, int len) {
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }

    string longestPalindrome(string s) {
        int dp[s.size()][s.size()];
        // 1. ij 的最长回文子串长度； 2. 以 ij 为边界的子串长度。
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        dp[s.size() - 1][s.size() - 1] = 1;
        for (int i = s.size() - 2; i >= 0; --i) {
            for (int j = 1; j < s.size(); ++j) {
                if (i > j) {
                    continue;
                } else if (j == i) {
                    dp[i][j] = 1;
                } else if (s[i] == s[j] && dp[i + 1][j - 1] == (j - i - 1)) {
                    dp[i][j] += dp[i + 1][j - 1] + 2;
                }
            }
        }

        string ans;
        int max_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < s.size(); ++j) {
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    ans = s.substr(i, max_len);
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return ans;
    }
};

int main() {
    Solution s;
    string result = s.longestPalindrome("aacabdkacaa");
    cout << "result is " << result << endl;
    return 0;
}
