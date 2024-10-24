#include "../header/tree.h"
#include <iostream>
#include <vector>
using namespace std;

void dfs(TreeNode *root, int depth, vector<pair<int, int>> &path) {
    if (!root) {
        return;
    }
    if (root->left)
        dfs(root->left, depth + 1, path);
    path.push_back(make_pair(root->val, depth));
    if (root->right)
        dfs(root->right, depth + 1, path);
}

bool isSymmetric(TreeNode *root) {
    vector<pair<int, int>> path;
    dfs(root, 0, path);
    for (int i = 0; i < path.size() / 2; ++i) {
        int j = path.size() - i - 1;
        if (path[i].first != path[j].first ||
            path[i].second != path[j].second) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> v = {1, 2, 2, 3, 4, 4, 3};
    TreeNode *root = buildTree(v);
    cout << isSymmetric(root) << endl;
    return 0;
}