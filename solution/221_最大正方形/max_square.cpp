#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix) {
    queue<pair<int, int>> q;
    int len = 1;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == '1') {
                q.push(make_pair(i, j));
            }
        }
    }
    while (!q.empty()) {
        len++;
        int count = q.size();
        for (int s = 0; s < count; ++s) {
            pair<int, int> p = q.front();

            // check border
            bool flag = true;
            for (int j = 0; j < len; ++j) {
                int i = p.first + len - 1;
                if (i >= matrix.size() || (p.second + j) >= matrix[i].size() ||
                    matrix[i][p.second + j] != '1') {
                    flag = false;
                    break;
                }
            }

            for (int i = 0; i < len; ++i) {
                int j = p.second + len - 1;
                if ((p.first + i) >= matrix.size() ||
                    j >= matrix[p.first + i].size() ||
                    matrix[p.first + i][j] != '1') {
                    flag = false;
                    break;
                }
            }

            q.pop();
            if (flag) {
                q.push(p);
            }
        }
    }
    return (len - 1) * (len - 1);
}

/*
 * 动态规划
 */
int maximalSquare_2(vector<vector<char>> &matrix) {
    // dp[i][j] 表示 i,j 为结尾的正方向边长
    int dp[matrix.size()][matrix[0].size()];
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            dp[i][j] = matrix[i][j] - '0';
        }
    }

    int ans = 0;
    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[i].size(); ++j) {
            if (dp[i][j] > 0) {
                dp[i][j] += min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                ans = max(ans, dp[i][j]);
            }
        }
    }
    for (int i = 0; i < matrix.size(); ++i) {
        ans = max(ans, dp[i][0]);
    }
    for (int j = 0; j < matrix[0].size(); ++j) {
        ans = max(ans, dp[0][j]);
    }
    return ans * ans;
}

int main() {
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    matrix = {{'1', '0', '1', '1', '0', '1'}, {'1', '1', '1', '1', '1', '1'},
              {'0', '1', '1', '0', '1', '1'}, {'1', '1', '1', '0', '1', '0'},
              {'0', '1', '1', '1', '1', '1'}, {'1', '1', '0', '1', '1', '1'}};
    cout << maximalSquare(matrix) << endl;
    cout << maximalSquare_2(matrix) << endl;
    return 0;
}