#include <iostream>
#include<limits.h>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValidBST(TreeNode *node, long minVal, long maxVal)
{
    if (!node)
        return true;

    if (node->val <= minVal || node->val >= maxVal)
        return false;

    return isValidBST(node->left, minVal, node->val) && isValidBST(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode *root)
{
    return isValidBST(root, LONG_MIN, LONG_MAX);
}

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(5);

    bool isBST = isValidBST(root);
    cout << isBST;

    return 0;
}