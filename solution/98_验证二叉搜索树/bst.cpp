#include "../header/tree.h"
#include <iostream>
#include <vector>

/*
 * 中序遍历的结果一定是有序的
 */
void dfs(TreeNode *root, vector<int> &v) {
    if (!root) {
        return;
    }
    dfs(root->left, v);
    v.push_back(root->val);
    dfs(root->right, v);
}

bool isValidBST(TreeNode *root) {
    vector<int> v;
    dfs(root, v);
    for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1] >= v[i]) {
            return false;
        }
    }
    return true;
}


int main() {
    vector<int> v = {5, 1, 4, -1, -1, 3, 6};
    //vector<int> v = {2, 1, 3};
    TreeNode *root = buildTree(v);
    cout << isValidBST(root) << endl;
    return 0;
}
