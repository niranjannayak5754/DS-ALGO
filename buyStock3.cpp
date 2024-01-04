/*
    Best Time to Buy and Sell Stock III [ Hard ]

    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    Find the maximum profit you can achieve. You may complete at most two transactions.

    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

    Example 1:
    Input: prices = [3,3,5,0,0,3,1,4]
    Output: 6
    Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
    Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

    Example 2:
    Input: prices = [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // intuition: can complete at most two transactions i.e buy sell buy sell
    // transaction count = 4 where 0 and 2 is buy, 1 and 3 is sell
    // similar to buy sell stock II
    // Note: we could have used idx, canBuy, cap also
    int f(int i, int t, vector<int>& prices, vector<vector<int>>& dp){
        if(i == prices.size() || t == 4) return 0;

        if(dp[i][t] != -1) return dp[i][t];

        if(t % 2 == 0){ // can buy stock
            return dp[i][t] = max(
                f(i+1, t+1, prices, dp) - prices[i], // buy
                f(i+1, t, prices, dp) // don't buy
            );
        }
        // can sell stock
        return dp[i][t] = max(
            f(i+1, t+1, prices, dp) + prices[i], // sell
            f(i+1, t, prices, dp) // don't sell
        );
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(0, 0, prices, dp);
    }
};

class Tabulation {
public:
    // intuition: can complete at most two transactions i.e buy sell buy sell
    // transaction count = 4 where 0 and 2 is buy, 1 and 3 is sell
    // similar to buy sell stock II
    // Note: we could have used idx, canBuy, cap also
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        // base case is by default false
        // dp[n][4] = 0

        for(int i = n-1; i >= 0; i--){
            for(int t = 3; t >= 0; t--){
                if(t % 2 == 0){ // can buy stock
                    dp[i][t] = max(
                        dp[i+1][t+1] - prices[i], // buy
                        dp[i+1][t] // don't buy
                    );
                } else{
                    // can sell stock
                    dp[i][t] = max(
                        dp[i+1][t+1] + prices[i], // sell
                        dp[i+1][t] // don't sell
                    );
                }
            }
        }

        return dp[0][0];
    }
};