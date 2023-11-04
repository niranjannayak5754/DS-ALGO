/**
 * 104. Maximum Depth of Binary Tree [Easy]

    Given the root of a binary tree, return its maximum depth.
    A binary tree's maximum depth is the number of nodes
    along the longest path from the root node down to the farthest leaf node.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: 3

    Example 2:
    Input: root = [1,null,2]
    Output: 2
**/
#include<bits/stdc++.h>

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

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    int left_size = 1 + maxDepth(root->left);
    int right_size = 1 + maxDepth(root->right);
    return left_size > right_size ? left_size : right_size;
}

int main(){
    // [3,9,20,null,null,15,7]
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(8);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << maxDepth(root) << endl;
    return 0;
}
