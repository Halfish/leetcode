#include "../header/tree.h"
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int dfs(TreeNode *root, bool &ans) {
    if (!root || ans == false) {
        return 0;
    }
    int left_depth = dfs(root->left, ans);
    int right_depth = dfs(root->right, ans);
    if (left_depth - right_depth > 1 || right_depth - left_depth > 1) {
        ans = false;
    }
    return max(left_depth, right_depth) + 1;
}

bool isBalanced(TreeNode *root) {
    bool ans = true;
    dfs(root, ans);
    return ans;
}

int main() {
    vector<int> v = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *root = buildTree(v);
    cout << isBalanced(root) << endl;
    return 0;
}