#include "../header/tree.h"
#include <iostream>
#include <vector>

bool dfs(TreeNode *root, vector<int> &v) {
    if (!root) {
        return true;
    }
    v.push_back(root->val);
    int count = v.size();
    bool left = dfs(root->left, v);
    for (int i = count; i < v.size(); ++i) {
        if (v[i] >= root->val) {
            return false;
        }
    }
    count = v.size();
    bool right = dfs(root->right, v);
    for (int i = count; i < v.size(); ++i) {
        if (v[i] <= root->val) {
            return false;
        }
    }
    return left && right;
}

bool isValidBST(TreeNode *root) {
    vector<int> v;
    return dfs(root, v);
}

int main() {
    vector<int> v = {5, 1, 4, -1, -1, 3, 6};
    TreeNode *root = buildTree(v);
    cout << isValidBST(root) << endl;
    return 0;
}