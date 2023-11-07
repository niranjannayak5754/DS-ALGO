/*
    House Robber [Medium] [DP] [Memoization]
*/
#include <bits/stdc++.h>

using namespace std;
class Solution
{
private:
    int rob_dp(vector<int> &nums, int idx, vector<int> &dp)
    {
        if (idx < 0)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        dp[idx] = max(rob_dp(nums, idx - 2, dp) + nums[idx], rob_dp(nums, idx - 1, dp));
        return dp[idx];
    }

public:
    // efficient solution
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int prev1 = 0, prev2 = 0;
        for (int val : nums)
        {
            int temp = prev1;
            prev1 = max(prev2 + val, prev1);
            prev2 = temp;
        }
        return prev1;
    }
    // dp solution
    int rob_dp(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return rob_dp(nums, n-1, dp);
    }

    // iterative solution
    int rob_iterative(vector<int> &nums){
        int n = nums.size();
        if (n==0) return 0;
        vector<int> dp(n+1);
        dp[0] = 0, dp[1] = nums[0];
        for(int i = 1; i<n; i++){
            dp[i+1] = max(dp[i-1] + nums[i], dp[i]);
        }
        return dp[n];
    }
};

int main()
{
    vector<int> nums{2, 1, 1, 2};
    Solution obj;
    cout << obj.rob_dp(nums) << endl;
    cout << obj.rob(nums) << endl;
    cout << obj.rob_iterative(nums) << endl;
    return 0;
}