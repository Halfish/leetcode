#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

/*
 * 直接用一个数组记录走过的数字，这样边界值比较好判断。
 */
vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    if (matrix.size() == 0) {
        return ans;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool visited[rows][cols];
    memset(visited, false, sizeof(visited));

    int op[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int total = rows * cols;
    int i = 0;
    int j = 0;
    int index = 0;
    for (int count = 0; count < total; ++count) {
        ans.push_back(matrix[i][j]);
        visited[i][j] = true;
        int next_i = i + op[index][0];
        int next_j = j + op[index][1];
        if (next_i < 0 || next_j < 0 || next_i >= rows || next_j >= cols ||
            visited[next_i][next_j]) {
            index = (index + 1) % 4;
        }
        i += op[index][0];
        j += op[index][1];
    }
    return ans;
}

int main() {
    int m = 4;
    int n = 3;
    int value = 1;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; ++i) {
        vector<int> v;
        for (int j = 0; j < m; ++j) {
            v.push_back(value++);
        }
        matrix.push_back(v);
    }
    vector<int> ans = spiralOrder(matrix);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}