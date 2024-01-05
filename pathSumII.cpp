/*
    Path Sum II  [ Medium ]

    Get all the paths from root to leaft nodes whose sum is targetSum
*/
// Definition for a binary tree node.

#include<iostream>
#include<vector>

using namespace std;

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
    void allPaths(TreeNode* root, int targetSum, vector<vector<int>>& paths, vector<int>& temp){
        if(!root) return;
        // add curr val to temp path
        temp.push_back(root->val);

        // when leaf node
        if(!root->left && !root->right){
            if(targetSum == root->val)
                paths.push_back(temp);
            temp.pop_back();
            return;
        }

        // go for left subtree
        allPaths(root->left, targetSum - root->val, paths, temp);
        allPaths(root->right, targetSum - root->val, paths, temp);
        
        // backtrack
        temp.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> temp;
        allPaths(root, targetSum, paths, temp);
        return paths;
    }
};