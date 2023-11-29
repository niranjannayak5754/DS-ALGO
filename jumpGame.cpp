/*
    JUMP GAME [Medium]
    You are given an integer array nums. You are initially positioned at the array's first index,
    and each element in the array represents your maximum jump length at that position.
    Return true if you can reach the last index, or false otherwise.

    Example 1:
    Input: nums = [2,3,1,1,4]
    Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

    Example 2:
    Input: nums = [3,2,1,0,4]
    Output: false
    Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
    
    Constraints:
    1 <= nums.length <= 104
    0 <= nums[i] <= 105
*/

#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int idx;
    int limit = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        idx = i + nums[i];
        if (idx > n - 2)
            return true;
        limit = max(limit, idx);
        if (limit == i)
            return false;
    }
    return true;
}

int main(){
    vector<int> nums1{2,3,1,1,4};
    vector<int> nums2{3,2,1,0,4};
    vector<int> nums3{3,0,8,2,0,0,1};
    vector<int> nums4{2};
    cout << canJump(nums1) << canJump(nums2) << canJump(nums3) << canJump(nums4) << endl;
    return 0;
}