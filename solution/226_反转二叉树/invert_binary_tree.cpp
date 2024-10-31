#include "../header/tree.h"
#include <iostream>
#include <vector>
using namespace std;

TreeNode *invertTree(TreeNode *root) {
    if (!root) {
        return root;
    }
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main() {
    vector<int> v = {4, 2, 7, 1, 3, 6, 9};
    TreeNode *root = buildTree(v);
    root = invertTree(root);
    print_tree(root);
    return 0;
}
