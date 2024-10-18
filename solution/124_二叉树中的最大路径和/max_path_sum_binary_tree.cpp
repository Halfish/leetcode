#include <cfloat>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#include "../header/tree.h"

/*
 * 后序遍历
 */
void dfs(TreeNode *root, unordered_map<TreeNode *, int> &m,
         unordered_map<TreeNode *, int> &n) {
    if (!root) {
        return;
    }
    dfs(root->left, m, n);
    dfs(root->right, m, n);

    int n_value = 0;
    int m_value = root->val;
    if (root->left) {
        n_value = max(n_value, n[root->left]);
        m_value += max(0, n[root->left]);
    }
    if (root->right) {
        n_value = max(n_value, n[root->right]);
        m_value += max(0, n[root->right]);
    }
    n[root] = root->val + n_value;
    m[root] = m_value;
}

int maxPathSum(TreeNode *root) {
    unordered_map<TreeNode *, int> m; // 当前节点作为根节点的最大路径和
    unordered_map<TreeNode *, int> n; // 一路走走到底
    dfs(root, m, n);
    int ans = root->val;
    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        ans = max(ans, iter->second);
    }
    for (auto iter = n.begin(); iter != n.end(); ++iter) {
        ans = max(ans, iter->second);
    }
    return ans;
}

int gain(TreeNode *root, int &ans) {
    if (!root) {
        return 0;
    }
    int left = gain(root->left, ans);
    int right = gain(root->right, ans);
    // 当前节点的增益值 = root + 左子树或者右子树或者不选
    int ret = root->val + max(0, max(left, right));

    // 记录最大路径和，当前节点，可以包含0,1,2个子树
    int max_value = root->val + max(0, left) + max(0, right);
    if (max_value > ans) {
        ans = max_value;
    }
    return ret;
}

/*
 * 解法二：递归的过程中记录就行，不需要哈希表
 */
int maxPathSum2(TreeNode *root) {
    int ans = INT_MIN;
    gain(root, ans);
    return ans;
}

int main() {
    // vector<int> v = {1, 2, 3};
    vector<int> v = {-10, 9, 20, -1, -1, 15, 7};
    TreeNode *root = buildTree(v);
    cout << maxPathSum(root) << endl;
    cout << maxPathSum2(root) << endl;
    return 0;
}
