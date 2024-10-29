#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool is_valid(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) {
        return false;
    }
    if (grid[i][j] <= 0) {
        return false;
    }
    grid[i][j] = -1;
    return true;
}

void bfs(vector<vector<int>> &grid, int i, int j, int &max_area) {
    if (!is_valid(grid, i, j)) {
        return;
    }
    int area = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    while (!q.empty()) {
        int count = q.size();
        area += count;
        for (int c = 0; c < count; ++c) {
            pair<int, int> p = q.front();
            // 代码可以优化
            if (is_valid(grid, p.first - 1, p.second)) {
                q.push(make_pair(p.first - 1, p.second));
            }
            if (is_valid(grid, p.first + 1, p.second)) {
                q.push(make_pair(p.first + 1, p.second));
            }
            if (is_valid(grid, p.first, p.second - 1)) {
                q.push(make_pair(p.first, p.second - 1));
            }
            if (is_valid(grid, p.first, p.second + 1)) {
                q.push(make_pair(p.first, p.second + 1));
            }
            q.pop();
        }
    }
    max_area = max(max_area, area);
    cout << "(" << i << ", " << j << ") -> " << area << endl;
}

int maxAreaOfIsland(vector<vector<int>> &grid) {
    int max_area = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            bfs(grid, i, j, max_area);
        }
    }
    return max_area;
}

int main() {
    vector<vector<int>> matrix = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                  {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                  {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << maxAreaOfIsland(matrix) << endl;
    return 0;
}
