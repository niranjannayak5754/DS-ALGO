/*
    ******* Maximum Depth of Binary Tree ****************

    Approach
            ->maximum of left and right subtree heights is answer

*/

#include<bits/stdc++.h>
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        int lh = 1 + minDepth(root->left);
        int rh = 1 + minDepth(root->right);

        return max(lh, rh);
    }
};