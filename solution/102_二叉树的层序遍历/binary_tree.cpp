#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};


/*
 * 二叉树的广度（宽度）优先遍历
 */
vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > ans;
    queue<TreeNode *> q;
    if (root) {
        q.push(root);
    }
    while (!q.empty()) {
        vector<int> v;
        queue<TreeNode *> sub_q;
        while (!q.empty()) {
            TreeNode *node = q.front();
            v.push_back(node->val);
            q.pop();
            if (node->left) {
                sub_q.push(node->left);
            }
            if (node->right) {
                sub_q.push(node->right);
            }
        }
        q = sub_q;
        ans.push_back(v);
    }
    return ans;
}

int main() { 
    vector<int> array = {3,9,20, -1, -1,15,7};
    TreeNode* root = nullptr;
    queue<TreeNode*> q;
    q.push(new TreeNode(array[0]));
    int i = 1;
    while (true) {
        if (i >= (array.size() + 1) / 2) {
            break;
        }

    }
    return 0; 
}