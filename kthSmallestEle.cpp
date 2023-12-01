/**

 */

// Definition for a binary tree node.

#include<iostream>
#include<stack>
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> S;
        TreeNode* cur = root;
        while(cur || !S.empty()){
            while(cur){
                S.push(cur);
                cur = cur->left;
            }

            cur = S.top();
            S.pop();

            if(--k == 0) return cur->val;

            cur = cur->right;
        }
        
        return -1;
    }
};