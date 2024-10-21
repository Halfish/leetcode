#include "../header/tree.h"
#include <iostream>
using namespace std;

void dfs(TreeNode *root, int depth, vector<int> &ans) {
    if (!root) {
        return;
    }
    if (ans.size() == depth) {
        ans.push_back(root->val);
    }
    if (root->right) {
        dfs(root->right, depth + 1, ans);
    }
    if (root->left) {
        dfs(root->left, depth + 1, ans);
    }
}

vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    dfs(root, 0, ans);
    return ans;
}

int main() {
    //vector<int> v = {1, 2, 3, -1, 5, -1, 4};
    vector<int> v = {1, -1, 3};
    TreeNode *root = buildTree(v);
    vector<int> ans = rightSideView(root);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}