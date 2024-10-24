#include <iostream>
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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    TreeNode *root = new TreeNode(preorder[0]);
    int leftLen = 0;
    while (true) {
        if (inorder[leftLen] == root->val) {
            break;
        }
        leftLen++;
    }
    if (leftLen > 0) {
        vector<int> leftPre(preorder.begin() + 1,
                            preorder.begin() + 1 + leftLen);
        vector<int> leftIn(inorder.begin(), inorder.begin() + leftLen);
        TreeNode *leftNode = buildTree(leftPre, leftIn);
        root->left = leftNode;
    }

    int rightLen = preorder.size() - 1 - leftLen;
    if (rightLen > 0) {
        vector<int> rightPre(preorder.end() - rightLen, preorder.end());
        vector<int> rightIn(inorder.end() - rightLen, inorder.end());
        TreeNode *rightNode = buildTree(rightPre, rightIn);
        root->right = rightNode;
    }
    return root;
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(preorder, inorder);
    cout << root->val << endl;
    return 0;
}
