/*
    House Robber II [Medium]
    A robber cannot rob two adjacent house. There are n houses, each house having nums[i] money stashed.
    This nums array is connected in circle so first and last house are also adjacent.
    Find the maximum money a robber can rob in one night.
*/
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
class Solution {
private:
    int rob(vector<int>& nums, int start, int end){
        int prev1 = 0, prev2=0;
        for(int i= start;i < end; i++){
            int temp = prev1;
            prev1 = max(prev2 + nums[i], prev1);
            prev2 = temp;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        return max(rob(nums, 0, n-1), rob(nums, 1, n));
    }
};