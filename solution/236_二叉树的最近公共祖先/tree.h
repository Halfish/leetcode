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

void buildTree(vector<int> &v, int pValue, int qValue, TreeNode **root,
               TreeNode **p, TreeNode **q) {
    if (v.size() == 0) {
        return;
    }
    *root = new TreeNode(v[0]);
    int index = 0;
    queue<TreeNode *> my_queue;
    my_queue.push(*root);
    while (!my_queue.empty()) {
        int count = my_queue.size();
        cout << "count = " << count << endl;
        for (int i = 0; i < count; ++i) {
            TreeNode *node = my_queue.front();
            cout << "i = " << i << ", index = " << index
                 << ", node = " << node->val << endl;
            my_queue.pop();
            if (node->val == pValue)
                *p = node;
            if (node->val == qValue)
                *q = node;
            if (index + 1 < v.size() && v[++index] >= 0) {
                cout << "v[" << index << "] = " << v[index] << endl;
                node->left = new TreeNode(v[index]);
                my_queue.push(node->left);
            }
            if (index + 1 < v.size() && v[++index] >= 0) {
                cout << "v[" << index << "] = " << v[index] << endl;
                node->right = new TreeNode(v[index]);
                my_queue.push(node->right);
            }
        }
    }
}