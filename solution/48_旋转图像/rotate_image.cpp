#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size() / 2; ++j) {
            swap(matrix[i][j], matrix[i][matrix[i].size() - j - 1]);
        }
    }

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            if (i + j + 1 >= matrix.size()) {
                break;
            }
            swap(matrix[i][j], matrix[matrix.size() - j - 1][matrix.size() - i - 1]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}