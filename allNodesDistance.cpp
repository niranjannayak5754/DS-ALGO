/**
    Given the root of a binary tree, the value of a target node target, and an integer k,
    return an array of the values of all nodes that have a distance k from the target node.
    You can return the answer in any order.

    Example 1:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
    Output: [7,4,1]
    Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

    Example 2:
    Input: root = [1], target = 1, k = 3
    Output: []
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findKDistanceNodes(TreeNode* node, int k , unordered_map<TreeNode*, TreeNode*>& parent, unordered_set<TreeNode*>& visited, vector<int>& result){
    if (!node || visited.count(node) || k < 0) return;
    if (k == 0){
        result.push_back(node->val);
        return;
    }
    visited.insert(node);
    findKDistanceNodes(node->left, k-1, parent, visited, result);
    findKDistanceNodes(node->right, k-1, parent, visited, result);
    findKDistanceNodes(parent[node], k-1, parent, visited, result);
}

TreeNode *findNode(TreeNode *root, int target, unordered_map<TreeNode*, TreeNode*>& parent)
{
    if(!root) return NULL;
    if (root->val == target) return root;

    if (root->left){
        parent[root->left] = root;
        TreeNode *leftNode = findNode(root->left, target, parent);
        if (leftNode) return leftNode;
    }

    if (root->right){
        parent[root->right] = root;
        TreeNode *rightNode = findNode(root->right, target, parent);
        if(rightNode) return rightNode;
    }

    return NULL;
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* targetNode = findNode(root, target->val, parent);
    unordered_set<TreeNode*> visited;
    vector<int> result;
    findKDistanceNodes(targetNode, k, parent, visited, result);
    return result;
}


int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *target = root;
    int k = 2;
    vector<int> result = distanceK(root, target, k);
    for (int val : result)
        cout << val << " ";
    return 0;
}