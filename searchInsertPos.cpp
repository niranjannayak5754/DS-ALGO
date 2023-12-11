/*
    ****** Search Insert Position [Easy] *****************

Given a sorted array of distinct integers and a target value,
return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 
Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l <= r){
            int mid = r - (r - l)/2;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target){
                r = mid -1;
            } else{
                l = mid + 1;
            }
        }
        
        return l;
    }
};