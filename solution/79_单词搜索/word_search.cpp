#include <iostream>
#include <vector>
using namespace std;


bool dfs(vector<vector<char>>& board, int i, int j, int index, string& word) {
    if (index == word.size()) {
        return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) {
        return false;
    }
    if (board[i][j] == '0') {
        // visited
        return false;
    }
    if (board[i][j] != word[index]) {
        return false;
    }
    char tmp = board[i][j];
    board[i][j] = '0';
    if (dfs(board, i - 1, j, index + 1, word)) {
        return true;
    }
    if (dfs(board, i + 1, j, index + 1, word)) {
        return true;
    }
    if (dfs(board, i, j - 1, index + 1, word)) {
        return true;
    }
    if (dfs(board, i, j + 1, index + 1, word)) {
        return true;
    }
    board[i][j] = tmp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (dfs(board, i, j, 0, word)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'B', 'S'},
        {'A', 'E', 'E', 'E'},
    };
    string word = "BCBSB";
    cout << exist(board, word) << endl;
    return 0;
}