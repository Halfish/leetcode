#include "../header/tree.h"
#include <iostream>
#include <vector>
using namespace std;

void dfs(TreeNode *root, int depth, int &ans) {
    if (!root) {
        return;
    }
    ans = max(ans, depth);
    if (root->left) {
        dfs(root->left, depth + 1, ans);
    }
    if (root->right) {
        dfs(root->right, depth + 1, ans);
    }
}

int maxDepth(TreeNode *root) {
    int ans = 0;
    dfs(root, 1, ans);
    return ans;
}

int main() {
    vector<int> v = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *root = buildTree(v);
    cout << maxDepth(root) << endl;
    return 0;
}