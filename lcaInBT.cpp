/*
    lowest common ancestor in binary tree problem
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

TreeNode *createTree()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    return root;
}

TreeNode *findNode(TreeNode *root, int target)
{
    if (!root)
    {
        return nullptr;
    }

    if (root->val == target)
    {
        return root;
    }

    TreeNode *leftResult = findNode(root->left, target);
    TreeNode *rightResult = findNode(root->right, target);

    return leftResult ? leftResult : rightResult;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return nullptr;
    if (root == p || root == q)
        return root;

    TreeNode *leftResult = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightResult = lowestCommonAncestor(root->right, p, q);
    if (!leftResult)
        return rightResult;
    if (!rightResult)
        return leftResult;
    return root;
}

int main()
{
    // root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    TreeNode *root = createTree();
    TreeNode *p = findNode(root, 5);
    TreeNode *q = findNode(root, 4);
    TreeNode *lca = lowestCommonAncestor(root, p, q);
    cout << lca->val;
    return 0;
}