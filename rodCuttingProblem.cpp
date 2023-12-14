#include <iostream>
#include <vector>
#include<climits>

using namespace std;

class Solution
{
public:
    int f(int i, int N, vector<int> &price, vector<vector<int>> &dp)
    {
        if(i == 0)
            return N* price[0];

        if(dp[i][N] != -1) return dp[i][N];

        int notTake = 0 + f(i - 1, N, price, dp);
        int take = INT_MIN;
        int rodLength = i + 1;
        if (rodLength <= N)
            take = price[i] + f(i, N - rodLength, price, dp);

        return dp[i][N] = max(take, notTake);
    }

    int rodCut(vector<int>& price, int n){
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(n-1, n, price, dp);
    }

    int rodCutTabulation(vector<int>& price, int n){

        vector<int> prev(n+1, 0), curr(n+1, 0);

        for(int N = 0; N <= n; N++){
            prev[N] = price[0] * N;
        }

        for(int i = 1; i <= n; i++){
            for(int N = 0; N <= n; N++){
                int notTake = 0 + prev[N];
                int take = INT_MIN;
                int rodLength = i + 1;
                if (rodLength <= N)
                    take = curr[N - rodLength];
                curr[N] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[n];
    }
};
