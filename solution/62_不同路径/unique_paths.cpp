#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int uniquePaths_2(int m, int n) {
    int dp[n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == 0) {
                dp[j] = 1;
            } else {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
    }
    return dp[n - 1];
}

int main() {
    cout << uniquePaths(3, 3) << endl;
    cout << uniquePaths_2(3, 3) << endl;
    return 0;
}