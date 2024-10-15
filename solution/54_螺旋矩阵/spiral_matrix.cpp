#include <iostream>
#include <vector>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int x0 = 0;
    int y0 = 0;
    int x1 = matrix[0].size() - 1;
    int y1 = matrix.size() - 1;
    while (x0 <= x1 && y0 <= y1) {
        // (x0 -> x1, y0)
        for (int x = x0; x <= x1; ++ x) {
            ans.push_back(matrix[y0][x]);
        }
        // (x1, y0 -> y1)
        for (int y = y0 + 1; y <= y1; ++y) {
            ans.push_back(matrix[y][x1]);
        }
        if (y1 > y0 && x1 > x0) {
            // (x1 -> x0, y1)
            for (int x = x1 - 1; x > x0; --x) {
                ans.push_back(matrix[y1][x]);
            }
            // (x0, y1 -> y0)
            for (int y = y1; y > y0; --y) {
                ans.push_back(matrix[y][x0]);
            }
        }
        x0 ++;
        y0 ++;
        x1 --;
        y1 --;
    }
    return ans;
}

int main() {
    int m = 4;
    int n = 3;
    int value = 1;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; ++ i) {
        vector<int> v;
        for (int j = 0; j < m; ++ j) {
            v.push_back(value ++);
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