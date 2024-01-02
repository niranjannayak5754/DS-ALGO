/*
    Flatten Binary Tree [ Medium ]

    Given the root of a binary tree, flatten the tree into a "linked list":

    The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.

*/

#include<iostream>
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
private:
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};

// intuition: Morris traversal
// attaching the rightmost node of binary tree to right of current node
class OptimizedSolution{
public:
    void flatten(TreeNode* root){
        if(!root) return;
        TreeNode* curr = root;
        TreeNode* prev;

        while(curr){
            if(curr->left){
                prev = curr->left;
                // getting the rightmost node of left subtree
                while(prev->right) prev = prev->right;

                prev->right = curr->right;
                
                curr->right = curr->left;
                curr->left = NULL;
            }
            // moving to next node
            curr = curr->right;
        }
    }
};