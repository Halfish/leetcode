#include <iostream>
#include <vector>

#include "tree.h"


/*
 * 题解的算法
 */
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (!left && !right) {
        return nullptr;
    }
    if (left && right) {
        return root;
    }
    return left ? left : right;
        
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