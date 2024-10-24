#include "../header/tree.h"
#include <iostream>
#include <vector>
using namespace std;

void dfs(TreeNode *root, vector<int> &path) {
    if (!root) {
        return;
    }
    path.push_back(root->val);
    if (root->left) {
        dfs(root->left, path);
    }
    if (root->right) {
        dfs(root->right, path);
    }
}

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    dfs(root, ans);
    return ans;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9};
    TreeNode *root = buildTree(v);
    vector<int> ans = preorderTraversal(root);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}