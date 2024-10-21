#include <iostream>
#include <cstring>
using namespace std;


int longestCommonSubsequence(string text1, string text2) {
    int dp[text1.size() + 1][text2.size() + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= text1.size(); ++i) {
        for (int j = 1; j <= text2.size(); ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[text1.size()][text2.size()];
}

int main() {
    cout << longestCommonSubsequence("abcde", "ace") << endl;
    cout << longestCommonSubsequence("abc", "abc") << endl;
    return 0;
}