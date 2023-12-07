/*
    ******* Minimum Depth of Binary Tree ****************

    Approach -> if(root->left) not there, then right height is min height. vice-versa for root->right
            -> if both left subtree and right subtree are there, min of these two heights is answer

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

        if(!root->left)
          return 1 + minDepth(root->right);
        
        if(!root->right)
          return 1 + minDepth(root->left);

        int lh = 1 + minDepth(root->left);
        int rh = 1 + minDepth(root->right);

        return min(lh, rh);
    }
};