#include "../header/tree.h"
#include <iostream>
#include <vector>
using namespace std;

int dfs(TreeNode *root, int &ans) {
    if (!root) {
        return 0;
    }
    int left_depth = dfs(root->left, ans);
    int right_depth = dfs(root->right, ans);
    ans = max(left_depth + right_depth, ans);
    return max(left_depth, right_depth) + 1;
}

int diameterOfBinaryTree(TreeNode *root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    TreeNode *root = buildTree(v);
    cout << diameterOfBinaryTree(root) << endl;
    return 0;
}