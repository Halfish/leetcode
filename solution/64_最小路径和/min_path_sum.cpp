#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &grid) {
    int dp[grid.size()][grid[0].size()];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < grid.size(); ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < grid[0].size(); ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < grid.size(); ++i) {
        for (int j = 1; j < grid[0].size(); ++j) {
            dp[i][j] = grid[i][j];
            dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[grid.size() - 1][grid[0].size() - 1];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };
    cout << minPathSum(grid) << endl;

    return 0;
}