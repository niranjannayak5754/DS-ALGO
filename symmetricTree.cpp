/*
    Symmetric Tree is the Tree having left value of all nodes == right value of corresponding nodes
*/

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isMirror(TreeNode *left, TreeNode *right)
{
    if (left == NULL || right == NULL)
        return left == right;
    if (left->val != right->val)
        return false;
    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetricTree(TreeNode *root)
{
    return root == NULL || isMirror(root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << isSymmetricTree(root);
    return 0;
}