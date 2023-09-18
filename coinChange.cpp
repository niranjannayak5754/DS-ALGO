#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;


int getTarget(vector<int>& nums,int idx, int target, vector<vector<int>>& dp){
    if(idx == 0){
        if(target % nums[0]) return 1e9;
        return target/nums[0];
    }
    if (dp[idx][target] != -1) return dp[idx][target];
    int notTake = getTarget(nums, idx - 1, target, dp);
    int take = INT_MAX;
    if (nums[idx]<= target){
        take = 1 + getTarget(nums, idx, target - nums[idx], dp);
    }
    return dp[idx][target] = min(take, notTake);
}

int minimumCoins(vector<int>& nums, int amount){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int res = getTarget(nums,n-1, amount, dp);
    if (res >= 1e9) return -1;
    return res;
}

int main(){
    vector<int> nums{1, 2, 5};
    int amount = 11;
    cout << minimumCoins(nums,amount);
    return 0;
}