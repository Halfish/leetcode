#include "../header/tree.h"
#include <iostream>
#include <vector>
using namespace std;

void dfs(TreeNode *root, vector<int> &v) {
    if (!root) {
        return;
    }
    if (root->left) {
        dfs(root->left, v);
    }
    v.push_back(root->val);
    if (root->right) {
        dfs(root->right, v);
    }
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    dfs(root, ans);
    return ans;
}

int main() {
    vector<int> v = {1, -1, 2, 3};
    TreeNode *root = buildTree(v);
    vector<int> ans = inorderTraversal(root);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}