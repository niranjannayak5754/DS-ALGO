/*
    Maximum Profit in Job Scheduling
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int scheduler(int i, vector<vector<int>>& jobs, vector<int>& dp)
    {
        // base case
        if(i == jobs.size()) return 0;
        
        if(dp[i] != -1) return dp[i];

        // take current task and move to next task which can be taken
        vector<int> curr{jobs[i][1], 0, 0};
        int next_i = lower_bound(jobs.begin() + i, jobs.end(), curr) - jobs.begin();
        int take = jobs[i][2] + scheduler(next_i, jobs, dp);
        
        // don't take current task
        int notTake = scheduler(i + 1, jobs, dp);

        return dp[i] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
            vector<int>& profit)
    {
        int n = profit.size();
        vector<vector<int>> jobs;

        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n, -1);
        return scheduler(0, jobs, dp);
    }
};

class Tabulation {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
            vector<int>& profit)
    {
        int n = profit.size();
        vector<vector<int>> jobs;

        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        vector<int> dp(n + 1, 0);

        for(int i = n -1; i >= 0; i--){
            // take current task and move to next task which can be taken
            vector<int> curr{jobs[i][1], 0, 0};
            int next_i = lower_bound(jobs.begin() + i, jobs.end(), curr) - jobs.begin();

            int take = jobs[i][2] + dp[next_i];
            
            // don't take current task
            int notTake = dp[i+1];

            dp[i] = max(take, notTake);
        }

        return dp[0];
    }
};

