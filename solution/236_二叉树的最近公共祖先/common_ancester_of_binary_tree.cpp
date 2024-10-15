#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

#include "tree.h"

bool dfs(TreeNode *curr, TreeNode *target, vector<TreeNode *> &path) {
    if (!curr)
        return false;
    path.push_back(curr);
    if (curr == target) {
        return true;
    }
    if (dfs(curr->left, target, path)) {
        return true;
    }
    if (dfs(curr->right, target, path)) {
        return true;
    }
    path.pop_back();
    return false;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> path_p;
    vector<TreeNode *> path_q;
    dfs(root, p, path_p);
    dfs(root, q, path_q);
    TreeNode *ans = nullptr;
    for (int i = 0; i < path_p.size(); ++i) {
        if (i < path_q.size() && path_p[i] == path_q[i]) {
            ans = path_p[i];
        }
    }
    return ans;
}

int main() {
    vector<int> v = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode *root;
    TreeNode *p;
    TreeNode *q;
    buildTree(v, 2, 6, &root, &p, &q);
    cout << root->val << ", " << p->val << ", " << q->val << endl;
    TreeNode *ans = lowestCommonAncestor(root, p, q);
    cout << ans->val << endl;
    return 0;
}