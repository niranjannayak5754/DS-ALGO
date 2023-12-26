#include <iostream>
#include <vector>

using namespace std;

#define mod (1000000007)
class Tabulation
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // base case when no of dice is 0: 0-based indexing
        dp[0][0] = 1;
        // copy the recursion
        for (int N = 1; N <= n; N++)
        {
            for (int T = 1; T <= target; T++)
            {
                for (int i = 1; i <= k; i++)
                {
                    if (T - i >= 0)
                        dp[N][T] = (dp[N][T] + dp[N - 1][T - i]) % mod;
                }
            }
        }

        return dp[n][target];
    }
};

class Recursion
{
public:
    int countWaysToTarget(int n, int k, int target, vector<vector<int>> &dp)
    {
        // base case
        if (target <= 0)
            return 0;
        if (n == 1)
            return target <= k ? 1 : 0;

        if (dp[n][target] != -1)
            return dp[n][target];

        int count = 0;
        for (int i = 1; i <= k; i++)
        {
            count = (count + countWaysToTarget(n - 1, k, target - i, dp)) % mod;
        }

        return dp[n][target] = count;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return countWaysToTarget(n, k, target, dp);
    }
};

int main()
{
    Tabulation obj;
    int res = obj.numRollsToTarget(30, 30, 500);
    cout << res << endl;
    cout << obj.numRollsToTarget(2, 6, 7) << endl;

    Recursion obj1;
    cout << obj1.numRollsToTarget(2, 6, 7) << endl;

    return 0;
}