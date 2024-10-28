#include "../header/tree.h"
#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> &path) {
    int s = 0;
    for (int v : path) {
        s += v;
    }
    return s;
}

void dfs(TreeNode *root, int targetSum, vector<int> &path,
         vector<vector<int>> &ans) {
    if (!root) {
        return;
    }
    path.push_back(root->val);
    if (!root->left && !root->right) {
        if (sum(path) == targetSum) {
            ans.push_back(vector<int>(path));
        }
    }
    if (root->left) {
        dfs(root->left, targetSum, path, ans);
    }
    if (root->right) {
        dfs(root->right, targetSum, path, ans);
    }
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> path;
    dfs(root, targetSum, path, ans);
    return ans;
}

int main() {
    vector<int> v = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
    TreeNode *root = buildTree(v);
    vector<vector<int>> ans = pathSum(root, 22);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}