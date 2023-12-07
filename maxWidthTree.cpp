/*
    ********* Maximum Width of Binary Tree [Medium] *************

    Using indexing for each nodes, so that width of current level will be last_idx - first_idx + 1;

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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            int min_idx = q.front().second;
            int first, last;

            for(int i = 0; i < size; i++){
                // int will work fine but in case, cur_idx crosses INT_MAX
                long long cur_idx = q.front().second - min_idx;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = cur_idx;
                if(i == size - 1) last = cur_idx;

                if(node->left)
                    q.push({node->left, 2LL * cur_idx + 1});
                
                if(node->right)
                    q.push({node->right, 2LL * cur_idx + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};