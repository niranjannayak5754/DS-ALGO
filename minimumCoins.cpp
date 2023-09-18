#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

// using tabulation for the problem of coin change or minimum coins
int minimumCoins(vector<int> &nums, int amount)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int T = 0; T <= amount; T++)
    {
        if (T % nums[0])
            dp[0][T] = 1e9;
        else
            dp[0][T] = T / nums[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int T = 0; T <= amount; T++)
        {
            int notTake = dp[i-1][T];
            int take = INT_MAX;
            if (nums[i] <= T)
            {
                take = 1 + dp[i][T - nums[i]];
            }
            dp[i][T] = min(take, notTake);
        }
    }
    int res = dp[n - 1][amount];
    if (res >= 1e9)
        return -1;
    return res;
}

int main()
{
    vector<int> nums{2};
    int amount = 3;
    cout << minimumCoins(nums, amount);
    return 0;
}