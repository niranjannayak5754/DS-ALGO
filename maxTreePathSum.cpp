
/*
    ****** Maximum Binary Tree Path Sum [Hard] ************************

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
    int maxPathSum(TreeNode* root, int& maxi) {
        if(!root) return 0;

        // getting the left subtree sum (ignoring negative sum)
        int left_sum = max(0, maxPathSum(root->left, maxi));
        
        // getting the right subtree sum (ignoring negative sum)
        int right_sum = max(0, maxPathSum(root->right, maxi));
        
        // getting track of maximum path sum i.e left -> node -> right
        maxi = max(maxi, left_sum + right_sum + root->val);

        // returning either the left tree path or right tree path sum
        // since both paths sum can't be taken forward
        return max(left_sum, right_sum) + root->val;
    }

    int maxPathSum(TreeNode* root){
        if(!root) return 0;
        int maxi = INT_MIN;
        maxPathSum(root, maxi);
        return maxi;
    }
};