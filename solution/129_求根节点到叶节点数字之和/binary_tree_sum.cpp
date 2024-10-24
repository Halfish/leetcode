#include "../header/tree.h"
#include <iostream>
using namespace std;

int to_number(vector<int> &num) {
    int ans = 0;
    for (int i = 0; i < num.size(); ++i) {
        ans = ans * 10 + num[i];
    }
    return ans;
}

void dfs(TreeNode *root, vector<int> &num, int &sum) {
    if (!root) {
        return;
    }
    num.push_back(root->val);
    if (!root->left && !root->right && num.size() > 0) {
        sum += to_number(num);
    }
    if (root->left) {
        dfs(root->left, num, sum);
    }
    if (root->right) {
        dfs(root->right, num, sum);
    }
    num.pop_back();
}

int sumNumbers(TreeNode *root) {
    vector<int> s;
    int sum = 0;
    dfs(root, s, sum);
    return sum;
}

int main() {
    vector<int> v = {1, 2, 3};
    TreeNode *root = buildTree(v);
    cout << sumNumbers(root) << endl;
    return 0;
}