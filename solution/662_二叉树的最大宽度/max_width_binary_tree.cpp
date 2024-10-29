#include "../header/tree.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int widthOfBinaryTree(TreeNode *root) {
    queue<pair<TreeNode *, unsigned long long>> q;
    q.push(make_pair(root, 1L));
    unsigned long long ans = 1L;
    while (!q.empty()) {
        int count = q.size();
        unsigned long long begin = -1;
        unsigned long long end = -1;
        for (int i = 0; i < count; ++i) {
            pair<TreeNode *, unsigned long long> p = q.front();
            if (i == 0) {
                begin = p.second;
            }
            if (i == count - 1) {
                end = p.second;
            }
            if (p.first->left) {
                q.push(make_pair(p.first->left, p.second * 2));
            }
            if (p.first->right) {
                q.push(make_pair(p.first->right, p.second * 2 + 1));
            }
            q.pop();
        }
        ans = max(ans, end - begin + 1);
    }
    return ans;
}

int main() {
    vector<int> v = {1, 3, 2, 5, 3, -1, 9};
    v = {1, 3, 2, 5, -1, -1, 9, 6, -1, 7};
    TreeNode *root = buildTree(v);
    cout << widthOfBinaryTree(root) << endl;
    return 0;
}