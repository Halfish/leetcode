#include <iostream>
#include <vector>

#include "../header/tree.h"

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root) {
        return ans;
    }
    vector<TreeNode*> curr;
    curr.push_back(root);
    int level = 0;
    while (!curr.empty()) {
        vector<int> v;
        vector<TreeNode*> next; // Next Level Node
        if (level % 2 == 0) {
            for (int i = 0; i < curr.size(); ++i) {
                v.push_back(curr[i]->val);
            }
        } else {
            for (int i = curr.size() - 1; i >= 0; --i) {
                v.push_back(curr[i]->val);
            }
        }
        level++;
        ans.push_back(v);
        for (int i = 0; i < curr.size(); ++i) {
            if (curr[i]->left) next.push_back(curr[i]->left);
            if (curr[i]->right) next.push_back(curr[i]->right);
        }
        curr.swap(next);
    }
    return ans;
}

int main() {
    vector<int> v = {3,9,20,-1,-1,15,7};
    TreeNode* root = buildTree(v);
    vector<vector<int>> ans = zigzagLevelOrder(root);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}