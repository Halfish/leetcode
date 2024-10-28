#include "../header/tree.h"
#include <iostream>
#include <vector>
using namespace std;

bool dfs(TreeNode *root, int targetSum, int &curSum) {
    if (!root) {
        return false;
    }
    curSum += root->val;
    if (!root->left && !root->right && curSum == targetSum) {
        return true;
    }
    if (root->left && dfs(root->left, targetSum, curSum)) {
        return true;
    }
    if (root->right && dfs(root->right, targetSum, curSum)) {
        return true;
    }
    curSum -= root->val;
    return false;
}

bool hasPathSum(TreeNode *root, int targetSum) {
    int curSum = 0;
    return dfs(root, targetSum, curSum);
}

int main() {
    vector<int> v = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
    v = {1, 2};
    TreeNode *root = buildTree(v);
    cout << hasPathSum(root, 1) << endl;
    return 0;
}