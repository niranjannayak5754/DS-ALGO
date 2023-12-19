#include<iostream>
#include<vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int f(TreeNode* root, int& diameter){
        if(!root) return 0;

        int left_h = f(root->left, diameter);
        int right_h = f(root->right, diameter);

        diameter = max(left_h + right_h, diameter);

        return 1 + max(left_h, right_h);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        f(root, diameter);
        return diameter;
    }
};