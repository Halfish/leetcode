#include <iostream>
#include <vector>
using namespace std;


void dfs(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) {
        return;
    }
    if (grid[i][j] != '1') {
        return;
    }
    grid[i][j] = '2'; // mark visited

    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    return;
}

int numIslands(vector<vector<char>> &grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << numIsLands(grid) << endl;
    cout << numIsLands(grid2) << endl;

    return 0;
}
