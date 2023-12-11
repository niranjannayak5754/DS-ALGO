
/*
    **** SubArray Sum with K [Medium] **********88

    Given a integer array nums and integer k;
    Return the number of subArrays which has k sum;
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    int subArrWithSumK(vector<int>& nums, int k){
        // defining a map storing presum and count of previous subArrays with that sum
        unordered_map<int, int> mp;
        // initializing a map with 0 preSum and count 1;
        mp[0] = 1;
        int res = 0;
        int preSum = 0;

        for(int val : nums){
            preSum += val;
            // checking if prefix sum with presum - k exists
            // that mean subarr with sum k exists and it's count is mp[preSum - k]
            res += mp[preSum - k];
            mp[preSum]++;
        }

        return res;
    }
};