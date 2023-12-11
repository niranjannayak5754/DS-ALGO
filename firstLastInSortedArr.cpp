/*
    *********** Find First and last position of element in a sorted array
Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int firstOccurence(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        int ans = -1;

        while(l <= r){
            int mid = l + (r - l)/2;

            if(nums[mid] == target){
                ans = mid;
                // search to left for first occurence
                r = mid - 1;
            } else if(nums[mid] > target){
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }

        return ans;
    }

    int lastOccurences(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        int ans = -1;

        while(l <= r){
            int mid = l + (r - l)/2;

            if(nums[mid] == target){
                ans = mid;
                // search to right for last occurence
                l = mid + 1;
            } else if(nums[mid] > target){
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurence(nums, target);
        if(first == -1) return {-1, -1};
        int last = lastOccurences(nums, target);
        return {first, last};
    }
};

int main(){
    // Input: nums = [5,7,7,8,8,10], target = 8
    // Output: [3,4]
    Solution obj;
    vector<int> nums {5,7,7,8,8,10};
    vector<int> res = obj.searchRange(nums, 8);
    cout << res[0] << " to " << res[1] << endl;
    vector<int> res1 = obj.searchRange(nums, 6);
    cout << res1[0] << " to " << res1[1] << endl;
    return 0;

}