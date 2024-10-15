#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};

TreeNode* buildTree(vector<int> &v) {
    if (v.size() == 0) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(v[0]);
    int index = 0;
    queue<TreeNode *> my_queue;
    my_queue.push(root);
    while (!my_queue.empty()) {
        int count = my_queue.size();
        for (int i = 0; i < count; ++i) {
            TreeNode *node = my_queue.front();
            my_queue.pop();
            if (index + 1 < v.size() && v[++index] >= 0) {
                node->left = new TreeNode(v[index]);
                my_queue.push(node->left);
            }
            if (index + 1 < v.size() && v[++index] >= 0) {
                node->right = new TreeNode(v[index]);
                my_queue.push(node->right);
            }
        }
    }
    return root;
}
