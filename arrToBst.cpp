/*
Convert Sorted Array to Binary Search Tree

    Given an integer array nums where the elements are sorted in ascending order, convert it to a 
    height-balanced
    binary search tree.

    Input: nums = [-10,-3,0,5,9]
    Output: [0,-3,9,-10,null,5]
    Explanation: [0,-10,5,null,-3,null,9] is also accepted:
*/

/*
Approach:
    Provided it is sorted array. Get the mid value of array and divide in left and right half excluding mid
    consider left array as left subtree and right array as righttree
    root -> val = arr[mid]
    root -> left = left_subtree
    root -> right = right subtree
Call the function recursively for each left and right subtree
*/
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *constructBst(int l, int r, vector<int> &nums){
    if(l > r) return nullptr;
    int mid = (l+r)/2;
    return new TreeNode(nums[mid], constructBst(l, mid -1, nums), constructBst(mid + 1, r, nums));
}

TreeNode *convertToBst(vector<int> &nums){
    return constructBst(0, nums.size()-1, nums);
}

int main(){
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode *root = convertToBst(nums);
    return 0;
}