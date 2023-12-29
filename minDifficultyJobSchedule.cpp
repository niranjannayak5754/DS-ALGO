
/*
    Hard -> Minimum Difficulty for a job Schedule

    Problem:
    You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

    You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days.
    The difficulty of a day is the maximum difficulty of a job done on that day.

    You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

    Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int recursion(int idx, int d, vector<int> &jobDifficulty, vector<vector<int>> &dp)
    {
        if (d == 1)
        {
            int maxi = 0;
            for (int i = idx; i < jobDifficulty.size(); i++)
                maxi = max(maxi, jobDifficulty[i]);
            return maxi;
        }

        if (dp[idx][d] != -1)
            return dp[idx][d];

        int res = INT_MAX, maxValue = 0;
        for (int i = idx; i <= jobDifficulty.size() - d; i++)
        {
            maxValue = max(maxValue, jobDifficulty[i]);
            res = min(res, maxValue + recursion(i + 1, d - 1, jobDifficulty, dp));
        }

        return dp[idx][d] = res;
    }

    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (n < d)
            return -1;
        vector<vector<int>> dp(n, vector<int>(d + 1, -1));
        return recursion(0, d, jobDifficulty, dp);
    }
};

class Tabulation
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (n < d)
            return -1;

        vector<vector<int>> dp(d + 1, vector<int>(n + 1, INT_MAX));
        dp[0][n] = 0;

        for (int days = 1; days <= d; days++)
        {
            for (int i = 0; i <= n - days; i++)
            {
                int maxValue = 0;
                for (int j = i; j <= n - days; j++)
                {
                    maxValue = max(maxValue, jobDifficulty[j]);
                    if (dp[days - 1][j + 1] != INT_MAX)
                        dp[days][i] = min(dp[days][i], maxValue + dp[days - 1][j + 1]);
                }
            }
        }

        return dp[d][0];
    }
};