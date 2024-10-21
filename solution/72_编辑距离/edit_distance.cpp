#include <cstring>
#include <iostream>
using namespace std;

int minDistance(string word1, string word2) {
    if (word1.size() == 0) {
        return word2.size();
    }
    if (word2.size() == 0) {
        return word1.size();
    }
    int dp[word1.size()][word2.size()];
    memset(dp, 0, sizeof(dp));

    dp[0][0] == word1[0] == word2[0] ? 0 : 1;
    int min_value = 1;
    for (int i = 0; i < word1.size(); ++i) {
        min_value = word1[i] == word2[0] ? 0 : min_value;
        dp[i][0] = min_value + i;
    }
    min_value = 1;
    for (int j = 0; j < word2.size(); ++j) {
        min_value = word1[0] == word2[j] ? 0 : min_value;
        dp[0][j] = min_value + j;
    }

    for (int i = 1; i < word1.size(); ++i) {
        for (int j = 1; j < word2.size(); ++j) {
            int left = dp[i - 1][j] + 1;
            int up = dp[i][j - 1] + 1;
            int arrow = dp[i - 1][j - 1] + (word1[i] == word2[j] ? 0 : 1);
            dp[i][j] = min(left, min(up, arrow));
        }
    }
    // for (int i = 0; i < word1.size(); ++i) {
    //     for (int j = 0; j < word2.size(); ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[word1.size() - 1][word2.size() - 1];
}

int main() {
    cout << minDistance("horse", "ros") << endl;
    cout << minDistance("intention", "execution") << endl;
    return 0;
}