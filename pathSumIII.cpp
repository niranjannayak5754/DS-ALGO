/*
    Path Sum III [ Medium ] [ Hash Map ]

    Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

    The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
*/

#include<iostream>
#include<unordered_map>

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
    int pathSumFromRoot(TreeNode * root, long int targetSum){
        int count=0;
        if (root->val == targetSum) count++;
        if (root->left){
            count += pathSumFromRoot(root->left, targetSum-root->val);
        } 
        if (root->right){
            count += pathSumFromRoot(root->right, targetSum-root->val);
        }
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        int count = pathSumFromRoot(root, targetSum);
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);
        return count;
    }
};


class HashSolution {
public:
    unordered_map<long, int> map;
    int count = 0;
    
    void countPathSum(TreeNode* root, int target, long sum){
        if(!root)
            return;
        sum += root->val;        //Path sum from root
        if(sum == target)
            count++;
        if(map.find(sum - target) != map.end())         //checking whether any target sum path present in the path from root to the current node
            count += map[sum - target];
        map[sum]++;
        countPathSum(root->left, target, sum);
        countPathSum(root->right, target, sum);
        map[sum]--;      //After visiting the left and right subtree, we have to reduce this path sum count from map since we are leaving this path
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        countPathSum(root, targetSum, 0);
        return count;
    }
};